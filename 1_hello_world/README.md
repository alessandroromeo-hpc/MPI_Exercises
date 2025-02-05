# How to compile


# Leo Boost
ml gcc/12.2.0 openmpi/4.1.6--gcc--12.2.0

mpif90 hello_world.f90 -o hello_world_fortran.exe

mpicc hello_world.c -o hello_world_C.exe

mpic++ hello_world.cpp -o hello_world_cpp.exe

# Leo DCGP
ml intel-oneapi-compilers intel-oneapi-mpi

mpiifx hello_world.f90 -o hello_world_fortran.exe

mpiicx hello_world.c -o hello_world_C.exe

mpiicpx hello_world.cpp -o hello_world_cpp.exe
