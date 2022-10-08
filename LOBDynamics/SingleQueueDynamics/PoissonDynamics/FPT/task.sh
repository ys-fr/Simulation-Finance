#!/bin/bash
#SBATCH -p job1
#SBATCH -n 1
#SBATCH -J SingleQueueDynamics
#SBATCH -o SingleQueueDynamics_out
#SBATCH -e SingleQueueDynamics_err
g++ -O3 main.cpp
./a.out 1. 2. 3. 10000.
python show.py