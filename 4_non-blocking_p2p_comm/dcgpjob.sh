#!/bin/bash
#SBATCH --nodes=2
#SBATCH --ntasks-per-node=1
#SBATCH --cpus-per-task=1
#SBATCH -p dcgp_usr_prod   
#SBATCH -q dcgp_qos_dbg
#SBATCH --account=!!!! PUT HERE YOUR ACCOUNT NAME !!!!
#SBATCH -J masterhpcmpi
#SBATCH --time=00:05:00
#SBATCH --output %x-slurm_job-%j.out
#SBATCH --error  %x-slurm_job-%j.err

srun -n 2 ./!!!! PUT HERE EXECUTABLE NAME !!!!
