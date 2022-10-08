#!/bin/bash
#SBATCH -p job1
#SBATCH -n 1
#SBATCH -J Gauss
#SBATCH -o Gauss_out
#SBATCH -e Gauss_err
g++ -O3 main.cpp
./a.out -.0 1 10
python show.py