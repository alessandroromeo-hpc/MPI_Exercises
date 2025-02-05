# How to compile

# Leo Booster
mpicc 4.2_comm_p2p_nonblocking.c -o comm_p2p_nonblocking_c.exe

mpicc 4.1_comm_p2p_nonblocking_Irecv.c -o comm_p2p_nonblocking_Irecv_c.exe

mpif90 4.2_comm_p2p_nonblocking.f90 -o comm_p2p_nonblocking_f90.exe

mpif90 4.1_comm_p2p_nonblocking_Irecv.f90 -o comm_p2p_nonblocking_Irecv_f90.exe

# Leo DCGP
mpiicx 4.2_comm_p2p_nonblocking.c -o comm_p2p_nonblocking_c.exe

mpiicx 4.1_comm_p2p_nonblocking_Irecv.c -o comm_p2p_nonblocking_Irecv_c.exe

mpiifx 4.2_comm_p2p_nonblocking.f90 -o comm_p2p_nonblocking_f90.exe

mpiifx 4.1_comm_p2p_nonblocking_Irecv.f90 -o comm_p2p_nonblocking_Irecv_f90.exe


# Notes

There are a few comments in these source codes.

What will happen if you uncomment one of these lines?