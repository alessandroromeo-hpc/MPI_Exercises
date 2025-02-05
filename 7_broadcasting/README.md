# Task 0 initializes a variable to a given value,then modifies the variable (for example, by calculating the square of its value) and finally broadcasts it to all the others tasks.

## How to compile

# Leo Booster

mpicc broadcasting.c -o broadcasting_c.exe

mpif90 broadcasting.f90 -o broadcasting_f90.exe

# Leo DCGP
mpiicx broadcasting.c -o broadcasting_c.exe

mpiifx broadcasting.f90 -o broadcasting_f90.exe
