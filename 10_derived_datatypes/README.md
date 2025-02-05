# 10. Consider the exercise 3.3(v2). Modify the functions Build_mpi_type and Get_input in order to introduce a new MPI_Datatype called input_mpi_t, and, using the addresses of the storing variables, compute the correct displacements needed for creating a new struct type containing the three input values needed for running the trapezoidal rule.

## How to compile

# Leo Booster
mpicc 10_trapezoidal_input.c -o trap_c.exe

# Leo DCGP
mpiicx 10_trapezoidal_input.c -o trap_c.exe

# 10.2 Illustrate how to use the MPI_Aint type and the MPI_AINT MPI_Datatype. This application consists of 2 MPI processes. The MPI process 0 sends the address takes the address of its local variable to the MPI process 1, which prints it.

# Leo Booster
mpicc 10.2_Aint.c -o aint_c.exe

# Leo DCGP
mpiicx 10.2_Aint.c -o aint.exe
