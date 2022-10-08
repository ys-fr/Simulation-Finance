#!/bin/bash
#SBATCH -p job1
#SBATCH -n 1
#SBATCH -J SymPoisson
#SBATCH -o SymPoisson_out
#SBATCH -e SymPoisson_err
g++ -O3 main.cpp
./a.out -1.0 0.5 1 10
python show.py