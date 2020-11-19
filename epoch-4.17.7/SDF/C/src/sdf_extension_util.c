/*
 * SDF (Self-Describing Format) Software Library
 * Copyright (c) 2013-2016, SDF Development Team
 *
 * Distributed under the terms of the BSD 3-clause License.
 * See the LICENSE file for details.
 */

#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sdf_extension.h>
#include <sdf_derived.h>
#include <sdf.h>

#ifndef _WIN32
# include <unistd.h>
# include <dlfcn.h>
#endif

static void *sdf_global_extension = NULL;
static void *sdf_global_extension_dlhandle = NULL;
static int   sdf_global_extension_failed = 0;

int sdf_purge_duplicates(sdf_file_t *h);

void *sdf_extension_load(sdf_file_t *h)
{
#ifndef _WIN32
    sdf_extension_create_t *sdf_extension_create;
    void *p;
    char *libname1 = "sdf_extension.so";
    char *libname2 = "libsdf_extension.so";
    char *path_env, *pathname, *path;
    char *sep = ":;,";
    int len;
    struct stat sb;

    h->sdf_extension_version  = SDF_EXTENSION_VERSION;
    h->sdf_extension_revision = SDF_EXTENSION_REVISION;

    if (sdf_global_extension_failed) {
        h->error_message = "sdf_extension_load: failed to load extension.";
        return NULL;
    }

    if (sdf_global_extension) return sdf_global_extension;

    /*
     * SDF_EXTENSION_PATH is a string separated by colon, semicolon or comma
     * Each substring is examined in turn. If it is a file then we attempt to
     * load it as a dynamic library. If it is a directory then we attempt to
     * load a file named "sdf_extension.so" or "libsdf_extension.so" in that
     * directory. The routine exits once a valid library is found.
     */
    path_env = getenv("SDF_EXTENSION_PATH");
    if (path_env) {
        len = strlen(path_env) + strlen(libname1) + strlen(libname2) + 2;
        pathname = malloc(len);
        for (path = strtok(path_env, sep); path; path = strtok(NULL, sep)) {
            stat(path, &sb);
            if (S_ISDIR(sb.st_mode)) {
                snprintf(pathname, len, "%s/%s", path, libname1);
                sdf_global_extension_dlhandle = dlopen(pathname, RTLD_LAZY);
                if (!sdf_global_extension_dlhandle) {
                    snprintf(pathname, len, "%s/%s", path, libname2);
                    sdf_global_extension_dlhandle = dlopen(pathname, RTLD_LAZY);
                }
            } else if (S_ISREG(sb.st_mode)) {
                sdf_global_extension_dlhandle = dlopen(path, RTLD_LAZY);
            }
            if (sdf_global_extension_dlhandle) break;
        }
        free(pathname);
    }

    if (!sdf_global_extension_dlhandle) {
        sdf_global_extension_dlhandle = dlopen(libname1, RTLD_LAZY);
        if (!sdf_global_extension_dlhandle)
            sdf_global_extension_dlhandle = dlopen(libname2, RTLD_LAZY);
    }

    if (!sdf_global_extension_dlhandle) {
        sdf_global_extension_failed = 1;
        h->error_message = dlerror();
        return NULL;
    }

    // Weird pointer copying required by ISO C
    p = dlsym(sdf_global_extension_dlhandle, "sdf_extension_create");
    memcpy(&sdf_extension_create, &p, sizeof(p));

    sdf_global_extension = sdf_extension_create(h);

    return sdf_global_extension;
#endif
}


void sdf_extension_unload(void)
{
#ifndef _WIN32
    sdf_extension_destroy_t *sdf_extension_destroy;
    void *p;

    if (!sdf_global_extension_dlhandle) return;

    if (sdf_global_extension) {
        // Weird pointer copying required by ISO C
        p = dlsym(sdf_global_extension_dlhandle, "sdf_extension_destroy");
        memcpy(&sdf_extension_destroy, &p, sizeof(p));

        sdf_extension_destroy(sdf_global_extension);
    }

#ifndef VALGRIND
    dlclose(sdf_global_extension_dlhandle);
    sdf_global_extension_dlhandle = NULL;
#endif

    sdf_extension_destroy = NULL;
    sdf_global_extension = NULL;
    sdf_global_extension_failed = 0;

    return;
#endif
}


void sdf_extension_free_data(sdf_file_t *h)
{
#ifndef _WIN32
    sdf_extension_free_t *sdf_extension_free;
    void *p;

    if (!sdf_global_extension_dlhandle) return;

    if (sdf_global_extension) {
        // Weird pointer copying required by ISO C
        p = dlsym(sdf_global_extension_dlhandle, "sdf_extension_free");
        if (!p)
            return;
        memcpy(&sdf_extension_free, &p, sizeof(p));

        sdf_extension_free(h);
    }

    return;
#endif
}


int sdf_read_blocklist_all(sdf_file_t *h)
{
    sdf_extension_t *ext;
    char **preload;
    sdf_block_t *b, *next, *cur, *block;
    int i;

    // Retrieve the extended interface library from the plugin manager
    sdf_extension_load(h);
    ext = sdf_global_extension;

    if (h->blocklist) {
        if (ext) ext->timestate_update(ext, h);
        return 0;
    }

    sdf_read_blocklist(h);

    // Append derived data to the blocklist using built-in library.
    sdf_add_derived_blocks(h);

    if (ext) {
        preload = ext->preload(ext, h);
        // For each entry in the preload array, try to find the block
        // and populate its data.
        if (preload) {
            int n = 0;
            cur = h->current_block;
            while(preload[n]) {
                b = sdf_find_block_by_id(h, preload[n]);
                if (b && !b->data) {
                    h->current_block = b;
                    sdf_read_data(h);
                }
                free(preload[n]);
                n++;
            }
            free(preload);
            h->current_block = cur;
        }

        // Append derived data to the blocklist using the extension library.
        ext->read_blocklist(ext, h);
    }

    // Append additional derived data for blocks added by the extension.
    sdf_add_derived_blocks_final(h);
    sdf_purge_duplicates(h);

    // Fill in dimensions for derived blocks
    next = h->last_block_in_file;
    while (next) {
        b = next;
        next = b->next;

        if (b->blocktype != SDF_BLOCKTYPE_PLAIN_DERIVED
                && b->blocktype == SDF_BLOCKTYPE_POINT_DERIVED) continue;

        if (b->ndims > 0 || !b->mesh_id) continue;

        block = sdf_find_block_by_id(h, b->mesh_id);
        b->ndims = block->ndims;
        memcpy(b->local_dims, block->local_dims,
               b->ndims * sizeof(*b->local_dims));

        if (b->blocktype == SDF_BLOCKTYPE_POINT_DERIVED) {
            b->nelements_local = block->dims[0];
        } else {
            b->nelements_local = 1;
            for (i = 0; i < b->ndims; i++) {
                if (b->stagger == SDF_STAGGER_CELL_CENTRE && !b->station_id)
                    b->local_dims[i]--;
                b->nelements_local *= b->local_dims[i];
            }
        }

        if (!b->datatype_out)
            b->datatype_out = block->datatype_out;
    }

    return 0;
}


void sdf_extension_print_version(sdf_file_t *h)
{
    int major, minor;
    sdf_extension_t *ext;

    // Retrieve the extended interface library from the plugin manager
    sdf_extension_load(h);
    ext = sdf_global_extension;

    if (ext) {
        ext->get_version(ext, &major, &minor);
        printf("Loaded extension: %s-%d.%d\n", ext->get_name(ext), major, minor);
    } else {
        printf("No extension loaded\n");
        if (sdf_global_extension_failed)
            printf("%s\n", h->error_message);
    }
}
