#!/bin/bash
#SBATCH --ntasks=36    # Job requires 36 CPU core
#SBATCH --time=60      # Job should run for one hour
#SBATCH --exclude=cn[66-69,71-136,153-256,265-320,325-328]

module purge
module load cuda/8.0.61 cudnn/6.0 sqlite/3.30.1 bzip2/1.0.6 libffi/3.2.1 gcc/9.2.0 lzma/4.32.7 tcl/8.6.6.8606 python/3.9.2

echo
echo
echo 'Open a new terminal and enter the following command, filling in XXX with the node'
echo 'number in the links at the bottom and YOURNETID as is necessary. Then enter password.'
echo 'Nothing will happen. Come back to this terminal and copy/paste the last link into a'
echo 'browser. NOTE: If there are any issues, you may have to restart your device as the'
echo 'port #8888 may already be assigned. The easiest way is to fix it is to restart.'
echo
echo
echo 'ssh -NL localhost:8888:cnXXX:8888 YOURNETID@login.storrs.hpc.uconn.edu'
echo
echo 'ssh -NL localhost:8888:cn:8888 @login.storrs.hpc.uconn.edu'
echo
echo
jupyter-notebook --no-browser --ip='*'
