#!/bin/bash
#SBATCH --partition=debug
#SBATCH --constraint="skylake"
#SBATCH --ntasks=1
#SBATCH --time=00:05:00

MODULEPATH=${HOME}:${MODULEPATH}

module purge
module load gcc/9.2.0 glib/2.49.4 cmake/3.22.2 make/4.3

gcc --version

#rm -rf ./build/*
cd flames2/third_generation_hpc/build
cmake ..
make
