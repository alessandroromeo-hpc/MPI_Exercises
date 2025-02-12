#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

void main(int argc, char * argv[]) {
     int err;
     int nprocs, my_rank;
     err = MPI_Init(&argc, &argv);
     MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
     MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

     if (nprocs != 2 && my_rank == 0) {
       printf("ERROR: this code should be run with exactly 2 processes");
       exit(1);
     }       
     
     MPI_Status *status;
     int number;
     if (my_rank == 0) { 
       number = 0;
       printf("Before sending: my number is %d and I am proc number %d \n", number, my_rank);
       MPI_Send(&number, 1, MPI_INT, 1, 10, MPI_COMM_WORLD);
     }
     else if (my_rank == 1)  {
       number = 1;
       printf("Before receiving: my number is %d and I am proc number %d \n", number, my_rank);
       MPI_Recv(&number, 1, MPI_INT, 0, 10, MPI_COMM_WORLD, status);
     }

     printf("My number is %d and I am proc number %d \n", number, my_rank);

     err = MPI_Finalize();
}

