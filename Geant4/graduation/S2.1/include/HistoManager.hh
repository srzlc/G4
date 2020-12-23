#ifndef HistoManager_h
#define HistoManager_h 1

#include "globals.hh"

#include "g4root.hh"
////////////
class HistoManager
{
  public:
   HistoManager();
  ~HistoManager();

  private:
    void Book();
    G4String fFileName;
};
#endif
