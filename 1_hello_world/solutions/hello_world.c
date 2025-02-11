#include <stdio.h>
#include <mpi.h>

int main(int argc, char * argv[] ){
     int err;

     err = MPI_Init(&argc, &argv);

     printf("Hello world (C version)!\n");

     err = MPI_Finalize();

     return 0;
}
