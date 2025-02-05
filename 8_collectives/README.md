# Task 0 initializes a one-dimensional array assigning to each cell the value of its index. This array is then divided into chunks and sent to other processes. After having received the proper chunk, each process updates it by adding its rank and then sends it back to root process. (Analyze the cases for equal and not equal chunks separately).

## How to compile

# Leo Booster
mpicc collectives.c -o collectives_c.exe

mpif90 collectives.f90 -o collectives_f90.exe

# Leo DCGP
mpiicx collectives.c -o collectives_c.exe

mpiifx collectives.f90 -o collectives_f90.exe