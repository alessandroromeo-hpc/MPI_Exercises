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
  
  err = MPI_Init(&argc,&argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
  MPI_Comm_rank(MPI_COMM_WORLD, &myid);

  A[0] = myid;
  printf("\t I am task %d and I have A = %d \n", myid, A[0]);

  right = (myid + 1) % numprocs;
  left = myid - 1;

  if (left < 0)
    left = numprocs - 1;
    //left  = (myid - 1 + numprocs) % numprocs;  
  
  MPI_Sendrecv(A, 1, MPI_INT, right, 123, B, 1, MPI_INT, left, 123, MPI_COMM_WORLD, &status);

  printf("\t I am task %d and I have received B = %d \n", myid, B[0]);

  err = MPI_Finalize();

  return 0;
}


