# Leo Booster

# 1. Compile serial code

# C
gcc -o serial jacobi-serial.c -lm 

# Fortran
gfortran -o serial jacobi-serial.f90 

# 2. Run serial version and time it
# time srun ./serial 100 100

# 3. Repeat with one of the MPI code versions:
#   - Using blocking SEND and RECEIVE
#   - Using non-blocking SEND and RECEIVE
#   - MPI SendRecv

ml gcc/11.3.0 openmpi/4.1.4--gcc--11.3.0-cuda-11.8

# for example for blocking version:
# Fortran 
mpif90 -o jacobi-mpi jacobi-block-mpi.f90 

# C 
mpicc -o jacobi-mpi jacobi-block-mpi.c -lm 

# 4. Run MPI version
# srun ./jacobi-mpi 100 100 

# 5. Produce scaling!
# You should time the Jacobi MPI for 100x100, 200x200, and 300x300 grid sizes as a function of number of MPI ranks (e.g. 2, 4, 8, 16,.), comparing with the time obtained for the serial version. 


# Leo DCGP

# 1. Compile serial code

# C
icx -o serial jacobi-serial.c -lm 

# Fortran
ifx -o serial jacobi-serial.f90 

# 2. Run serial version and time it
# time srun ./serial 100 100

# 3. Repeat with one of the MPI code versions:
#   - Using blocking SEND and RECEIVE
#   - Using non-blocking SEND and RECEIVE
#   - MPI SendRecv

ml intel-oneapi-compilers intel-oneapi-mpi

# for example for blocking version:
# Fortran 
mpiifx -o jacobi-mpi jacobi-block-mpi.f90 

# C 
mpiicx -o jacobi-mpi jacobi-block-mpi.c -lm 

# 4. Run MPI version
# srun ./jacobi-mpi 100 100 

# 5. Produce scaling!
# You should time the Jacobi MPI for 100x100, 200x200, and 300x300 grid sizes as a function of number of MPI ranks (e.g. 2, 4, 8, 16,.), comparing with the time obtained for the serial version. 


