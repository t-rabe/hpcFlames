#!/bin/bash
#SBATCH --partition=general
#SBATCH --constraint="skylake"
#SBATCH --ntasks=16
#SBATCH --time=01:00:00

module purge
module load gcc/9.2.0 glib/2.49.4 cmake/3.22.2 make/4.3

cd flames2/third_generation_hpc/build
./run_thirdGen_driver
