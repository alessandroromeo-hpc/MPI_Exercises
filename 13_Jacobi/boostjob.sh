#!/bin/bash
#SBATCH --nodes=4
#SBATCH --ntasks-per-node=4
#SBATCH --cpus-per-task=1
#SBATCH -p boost_usr_prod   
#SBATCH -q boost_qos_dbg
#SBATCH --account=!! PUT YOU ACCOUNT HERE !!
#SBATCH -J masterjacobi
#SBATCH --time=00:05:00
#SBATCH --output %x-slurm_job-%j.out
#SBATCH --error  %x-slurm_job-%j.err

EXECPATH=!! PUT EXEC PATH HERE !!

srun -n 16 $EXECPATH 100 100
