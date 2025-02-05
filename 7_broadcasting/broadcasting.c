#include <stdlib.h>
#include <stdio.h>
#include <mpi.h>

int main (int argc, char* argv[]){

  int my_id, num_procs, inserted_num, modified_num;
  
  MPI_Init(&argc, &argv);	/* starts MPI */
  MPI_Comm_rank (MPI_COMM_WORLD, &my_id);	/* get current process id */
  MPI_Comm_size (MPI_COMM_WORLD, &num_procs);	/* get number of processes */
  
  printf("my_id is %d and modified_num before broadcast is %d\n", my_id, modified_num); /* not initialized value!!! */

  if(my_id == 0) {
    /* printf("Insert an integer value: \n");     In case of interactive run */
    /*    scanf("%d", &inserted_num);*/
    inserted_num = FIXME;
    printf("Inserted num is :%d\n", inserted_num);
    modified_num = FIXME ;
  }

  else {
    inserted_num = FIXME;
    modified_num = FIXME;
  }

  MPI_FIXME(FIXME, FIXME, FIXME, FIXME, FIXME);
  
  printf("my_id is %d ,inserted_num is %d and modified_num is %d\n", my_id, inserted_num, modified_num);

  MPI_Finalize();
  return 0;
}
