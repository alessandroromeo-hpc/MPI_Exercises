#include <stdio.h>
#include <mpi.h>

void main(int argc, char * argv[]) {
     int err;
     int nprocs, my_rank;
     err = MPI_Init(&argc, &argv);
     MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
     MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
     printf("Hello I am %d of %d procs \n", my_rank, nprocs);
     err = MPI_Finalize();
}

