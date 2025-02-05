#include "mpi.h" 
#include <stdio.h> 
#define SIZE 16 
#define UP 0 
#define DOWN 1 
#define LEFT 2 
#define RIGHT 3 
int main(int argc, char *argv[]) 
{ 
   int numtasks, rank, source, dest, outbuf, i, tag = 1, inbuf[4] = {MPI_PROC_NULL,MPI_PROC_NULL,MPI_PROC_NULL,MPI_PROC_NULL};
   int nbrs[4], dims[2] = {4, 4}, periods[2] = {0, 0}, reorder = 0, coords[2]; 
   MPI_Request reqs[8]; 
   MPI_Status stats[8]; 
   MPI_Comm cartcomm; // required variable 
   MPI_Init(&argc,&argv); 
   MPI_Comm_size(MPI_COMM_WORLD, &numtasks); 

   if (numtasks == SIZE) { 
      // create cartesian virtual topology, get rank, coordinates, neighbor ranks
      ...
      printf("rank = %d inbuf(u,d,l,r) = %d %d %d %d\n", rank, inbuf[UP], inbuf[DOWN], inbuf[LEFT], inbuf[RIGHT]); 
   } 
   else 
      printf("Must specify %d processors. Terminating.\n", SIZE); 
   MPI_Finalize();
   return 0; 
}
