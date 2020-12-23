#!/bin/bash
#SBATCH -p paratera
#SBATCH -N 1 
#SBATCH -n 24 
#SBATCH -J SR
cd ~/sr/Pol01.1parallel/build
./Pol01  histos.mac

