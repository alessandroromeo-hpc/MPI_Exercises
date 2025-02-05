#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

void main(int argc, char * argv[]) {
  
  int err;
  int nprocs, my_rank;
  err = MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
  MPI_Status status;
  int count = 10000;
  double a[count], b[count];
     
  if (my_rank == FIXME) { 
    for (int i = 0; i < count; i++)
	    a[i] = 2.0*i;

    //FIXME
    //FIXME
  }
  else if (my_rank == FIXME)  {
    for (int i = 0; i < count; i++)
	    a[i] = 2.0*i + 1.0;

    //FIXME
    //FIXME
  }

  printf("My a array is %f, %f and I am proc number %d \n", a[0], a[1], my_rank);
  printf("My b array is %f, %f and I am proc number %d \n", b[0], b[1], my_rank);

  err = MPI_Finalize();
}

