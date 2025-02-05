# How to compile

# Leo Booster

mpif90 3.0_comm_p2p.f90 -o comm_p2p_f90.exe

mpicc 3.0_comm_p2p.c -o comm_p2p_c.exe

# Leo DCGP

mpiifx 3.0_comm_p2p.f90 -o comm_p2p_f90.exe

mpiicx 3.0_comm_p2p.c -o comm_p2p_c.exe

# BONUS Write a code using point to point communication that makes two processes send each other an array of floats containing their rank. Each of the processes will declare two float arrays, A and B, of a fixed dimension (10000).  All of the elements of the array A will be initialized with the rank of the process. Then, A and B will be used as the buffers for SEND and RECEIVE, respectively. The program terminates with each process printing out one element of the array B.
