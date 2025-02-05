#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

void main(int argc, char * argv[]) {
     int err;
     int nprocs, my_rank;
     err = MPI_Init(&argc, &argv);
     MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
     MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
     MPI_Request req;
     MPI_Status status;
     double a[2], b[2];
        
     if (my_rank == 0) { 
       a[0] = 2.0;
       a[1] = 4.0;
       MPI_Irecv(a, 2, MPI_DOUBLE, FIXME, 10, MPI_COMM_WORLD, &req);
       MPI_Send(a, 2, MPI_DOUBLE, FIXME, 10, MPI_COMM_WORLD);
       MPI_Wait(FIXME, MPI_STATUS_IGNORE);
     }
     else if (my_rank == 1)  {
       a[0] = 3.0;
       a[1] = 5.0;
       MPI_Irecv(b, 2, MPI_DOUBLE, FIXME, 10, MPI_COMM_WORLD, &req);
       MPI_Send(a, 2, MPI_DOUBLE, FIXME, 10, MPI_COMM_WORLD);
       MPI_Wait(FIXME, MPI_STATUS_IGNORE);
     }

     printf("My a array is %f, %f and I am proc number %d \n", a[0], a[1], my_rank);
     printf("My b array is %f, %f and I am proc number %d \n", b[0], b[1], my_rank);

     err = MPI_Finalize();
}

