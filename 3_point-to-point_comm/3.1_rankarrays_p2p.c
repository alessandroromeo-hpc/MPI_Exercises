#include <stdlib.h>
#include <stdio.h>
#include <mpi.h>

#define NDATA 10000

int main(int argc, char* argv[]){

    int me, nprocs, i = 0;
    MPI_Status status;

    float a[NDATA];
    float b[NDATA];

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &me);

    /* Initialize data */
    for(i = 0; i < NDATA; ++i){
      a[i] = me;
    }
    
    /* Protect against the use with a number of processes != 2 */
    if(nprocs != 2){
      FIXME
    }

    /* Send and Receive data */
    FIXME

    printf("\tI am task %d and I have received b(0) = %1.2f \n", me, b[0]);

    MPI_Finalize();
    return 0;
}

