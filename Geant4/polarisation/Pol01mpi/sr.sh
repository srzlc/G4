#!/bin/bash
#SBATCH -p paratera
#SBATCH -N 2 
#SBATCH -n 48
#SBATCH -J SR
cd ~/sr/Pol01mpi/build
./Pol01  histos.mac

