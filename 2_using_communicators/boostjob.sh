#!/bin/bash
#SBATCH --nodes=2
#SBATCH --ntasks-per-node=2
#SBATCH --cpus-per-task=1
#SBATCH -p boost_usr_prod   
#SBATCH -q boost_qos_dbg
#SBATCH --account=!!!! PUT HERE YOUR ACCOUNT NAME !!!!
#SBATCH -J mpitests
#SBATCH --time=00:05:00
#SBATCH --output %x-slurm_job-%j.out
#SBATCH --error  %x-slurm_job-%j.err

srun -n 4 ./!!!! PUT HERE YOUR EXECUTABLE NAME !!!!
