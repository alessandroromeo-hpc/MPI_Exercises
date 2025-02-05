#!/bin/bash
#SBATCH --nodes=2
#SBATCH --ntasks-per-node=2
#SBATCH --cpus-per-task=1
#SBATCH -p boost_usr_prod   
#SBATCH -q boost_qos_dbg
#SBATCH --account=cin_staff
#SBATCH -J mpitests
#SBATCH --time=00:05:00
#SBATCH --exclusive
#SBATCH --output %x-slurm_job-%j.out
#SBATCH --error  %x-slurm_job-%j.err

EXECPATH=/leonardo/home/userinternal/aromeo00/courses/mpi_intro_examples/10_Jacobi/sendrecv.exe
#EXECPATH=/leonardo/home/userinternal/aromeo00/courses/mpi_intro_examples/4_non-blocking_p2p_comm/solutions/comm_p2p_nonblocking_c.exe

srun -n 4 $EXECPATH 100 100
