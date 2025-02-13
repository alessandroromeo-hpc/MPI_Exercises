#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

void main(int argc, char * argv[]) {
     int err;
     int nprocs, my_rank;
     err = MPI_Init(&argc, &argv);
     MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
     MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
     MPI_Request req0[2], req1[2];
     MPI_Status status[2];
     double a[2], b[2];
        
     if (my_rank == 0) { 
       a[0] = 2.0;
       a[1] = 4.0;
       MPI_Isend(a, 2, MPI_DOUBLE, 1, 10, MPI_COMM_WORLD, &req0[0]);
       MPI_Irecv(b, 2, MPI_DOUBLE, 1, 11, MPI_COMM_WORLD, &req0[1]);
       //b[0] += 10.0;
       MPI_Waitall(2, req0, status);
       b[0] += 10.0;
     }
     else if (my_rank == 1)  {
       a[0] = 3.0;
       a[1] = 5.0;
       MPI_Isend(a, 2, MPI_DOUBLE, 0, 11, MPI_COMM_WORLD, &req1[0]);
       MPI_Irecv(b, 2, MPI_DOUBLE, 0, 10, MPI_COMM_WORLD, &req1[1]);
       MPI_Waitall(2, req1, status);
     }

     printf("My a array is %f, %f and I am proc number %d \n", a[0], a[1], my_rank);
     printf("My b array is %f, %f and I am proc number %d \n", b[0], b[1], my_rank);

     err = MPI_Finalize();
}

