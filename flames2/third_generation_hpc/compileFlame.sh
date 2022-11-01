#!/bin/bash
#SBATCH --partition=debug
#SBATCH --exclude=cn[66-69,71-136,153-256,265-320,325-328]
#SBATCH --ntasks=1
#SBATCH --time=00:05:00

module purge
module load gcc/9.2.0 glib/2.49.4 cmake/3.22.2 make/4.3

gcc --version

rm -rf build/*
cd build
g++ -std=c++14 -pthread -Wall ../third_generation/src/driver.cpp ../third_generation/src/Functions.cpp ../third_generation/src/RandChoice.cpp ../third_generation/src/ApplyFuncs.cpp ../third_generation/src/MakeMatrix.cpp -o run_thirdGen_driver

echo "Compiled Successfully"
