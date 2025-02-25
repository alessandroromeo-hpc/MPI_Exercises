#include "mpi.h" 
#include <stdio.h> 
#define NPROCS 8

int main(int argc, char **argv) {
    int rank, new_rank, nprocs, sendbuf, recvbuf;
    int ranks1[4]={0,1,2,3}, ranks2[4]={4,5,6,7}; 
    MPI_Group orig_group, new_group; 
    MPI_Comm new_comm; 
  
    MPI_Init(&argc, &argv); 
    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); 

    if (nprocs != NPROCS) {
        printf("Must specify MP_PROCS= %d. Terminating.\n", NPROCS);
        MPI_Finalize();
        exit(0);
    }
    
    sendbuf = rank; 

    //extract the original group handle
    MPI_Comm_group(MPI_COMM_WORLD, &orig_group); 
  
    //divide tasks into two distinct groups based upon rank
    if(rank < nprocs/2) 
        MPI_Group_incl(orig_group, nprocs/2, ranks1, &new_group); 
    else 
        MPI_Group_incl(orig_group, nprocs/2, ranks2, &new_group); 
    
    //create new communicator and then perform collective communications
    MPI_Comm_create(MPI_COMM_WORLD, new_group, &new_comm); 
    MPI_Allreduce(&sendbuf, &recvbuf, 1, MPI_INT, MPI_SUM, new_comm);

    //get rank in new group
    MPI_Group_rank(new_group, &new_rank); 
    
    printf("rank = %d newrank = %d recvbuf = %d\n", rank, new_rank, recvbuf);
    
    MPI_Group_free(&new_group); 
    MPI_Comm_free(&new_comm); 
    MPI_Finalize();
    return 0; 
}
