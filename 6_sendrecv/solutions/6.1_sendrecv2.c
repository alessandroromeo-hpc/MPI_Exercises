#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>


#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  int err;
  int myid, numprocs, left, right, i;
  int A[1], B[1];
  MPI_Request request;
  MPI_Status status;
  
  MPI_Init(&argc,&argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
  MPI_Comm_rank(MPI_COMM_WORLD, &myid);

  right = (myid + 1) % numprocs;
  left = myid - 1;
  
  if (left < 0)
    left = numprocs - 1;

  //left  = (myid - 1 + numprocs) % numprocs;
  
  A[0] = myid;
  MPI_Isend(A, 1, MPI_FLOAT, right, 0, MPI_COMM_WORLD, &request);
  MPI_Recv(B, 1, MPI_FLOAT, left, 0, MPI_COMM_WORLD, &status);

  MPI_Wait(&request, &status);


  printf("\t I am task %d and I have received B = %d \n", myid, B[0]);

  err = MPI_Finalize();

  return 0;
}


