#include <stdio.h>
#include <stdlib.h>
#include <FIXME>

void main(int argc, char * argv[]) {
     int err;
     int nprocs, my_rank;
     FIXME;
     MPI_Comm_FIXME(MPI_COMM_WORLD, &nprocs);
     MPI_Comm_FIXME(MPI_COMM_WORLD, &my_rank);

     if (nprocs != 2 && my_rank == 0) {
       printf("ERROR: this code should be run with exactly 2 processes");
       exit(1);
     }       

     MPI_Barrier(MPI_COMM_WORLD);
     
     FIXME *status;
     int number;
     if (my_rank == FIXME) { 
       number = 0;
       printf("Before sending: my number is %d and I am proc number %d \n", FIXME, FIXME);
       MPI_Send(FIXME);
     }
     else if (my_rank == FIXME)  {
       number = 1;
       printf("Before receiving: my number is %d and I am proc number %d \n", number, my_rank);
       MPI_Recv(FIXME);
     }

     printf("My number is %d and I am proc number %d \n", number, my_rank);

     FIXME;
}

