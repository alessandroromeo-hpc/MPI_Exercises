# Each process initializes a one-dimensional array by giving to all the elements the value of its rank+1. Then the root process (task 0) performs a sum reduce operation to the arrays of all the processes, and after that performs a product reduce on the same arrays. Finally, each process generates a random number and root process finds (and prints) the maximum value among these random values.
# Modify the code to perform a simple scalability test using MPI_Wtime. This function/routine returns a floating-point number of seconds, representing elapsed wall-clock time since some time in the past. You can call it at the beginning and at the end of your MPI part of the code, then use the difference so store the elapsed time. Notice what happens when you go up with the number of processes involved.

## How to compile

# Leo Booster
mpicc reduction.c -o reduction_c.exe

mpif90 reduction.f90 -o reduction_f90.exe

# Leo DCGP
mpiicx reduction.c -o reduction_c.exe

mpiifx reduction.f90 -o reduction_f90.exe
