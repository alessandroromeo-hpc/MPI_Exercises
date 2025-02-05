# 11.1 Create two different process groups for separate collective communications exchange, starting from 8 processes and using MPI_Group_incl. Then perform an Allreduce to sum the ranks of those two independent groups and print the result.

## How to compile

# Leo Booster
mpicc 11.1_groups.c -o groups_c.exe

mpif90 11.1_groups.f90 -o groups_f90.exe

# Leo DCGP
mpiicx 11.1_groups.c -o groups_c.exe

mpiifx 11.1_groups.f90 -o groups_f90.exe


# 11.2 Create a communicator which contains the prime ranks from MPI_COMM_WORLD (max 16 processes, unless ranks[] array is modified in the code). Use MPI_Group_incl and results in prime_group. Next, pass that group to MPI_Comm_create_group to create prime_comm. At the end, be careful to not use prime_comm on processes which don’t have it, therefore one should check that the communicator is not MPI_COMM_NULL, which is returned from MPI_Comm_create_group on the ranks not included in ranks.

## How to compile

# Leo Booster
mpicc 11.2_primes.c -o primes_c.exe

mpif90 11.2_primes.f90 -o primes_f90.exe

# Leo DCGP
mpiicx 11.2_primes.c -o primes_c.exe

mpiifx 11.2_primes.f90 -o primes_f90.exe
