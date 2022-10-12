#!/bin/bash
#SBATCH -p job1
#SBATCH -n 1
#SBATCH -c 5
#SBATCH -J SingleQueueDynamics
#SBATCH -o SingleQueueDynamics_out
#SBATCH -e SingleQueueDynamics_err

export OMP_NUM_THREADS=5
g++ -O3 main.cpp -fopenmp
./a.out 1. 2. 3. 1000 100
python show.py 1000