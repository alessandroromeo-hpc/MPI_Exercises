#include FIXME
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10

typedef int row[N];

int main(int argc, char *argv[])
{
  int np, rank, n, r;
  int iglob;
  int i,j;
  int k;
  row *mat;
  MPI_Status status;

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &np);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  /* Number of rows that are assigned to each processor, taking care of the remainder */
  n = FIXME;
  r = FIXME;
  if(rank < r)
    n++;

  /* Allocate local workspace */
  mat = (row *) malloc(n * sizeof(row));
  /* Column of the first "one" entry */
  iglob = n * FIXME;
  if (rank >= r)
    iglob += FIXME;
  /* Initilize local matrix */
  for(i = 0; i < n; i++)
  {
    for(j = 0; j < N; j++)
      if(j == FIXME)
        mat[i][j] = FIXME;
      else
        mat[i][j] = FIXME;
    iglob++;
  }

  /* Print matrix */
  if(FIXME){
    /* Rank 0: print local buffer */
    for(i = 0; i < n; i++){
      for(j = 0; j < N; j++)
        printf("%d ", mat[i][j]);
      printf("\n");
    }
    /* Receive new data from other processes in an ordered fashion and print the buffer */
    for (k = 1; k < np; k++){
      if(k == r){
        n = n - 1;
      }
        
      MPI_Recv(FIXME, FIXME, FIXME, FIXME, FIXME, FIXME, FIXME);
        
      for (i = 0; i < n; i++){
        for (j = 0; j < N; j++)
          printf("%d ", mat[i][j]);
        printf("\n");
      }
    }
  }
  else {
    /* Send local data to Rank 0 */
    MPI_Send(FIXME, FIXME, FIXME, FIXME, FIXME, FIXME);
  }

  free(FIXME);  
  MPI_Finalize();
  return 0;
}
