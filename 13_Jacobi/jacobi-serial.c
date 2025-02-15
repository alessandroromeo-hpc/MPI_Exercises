#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

// Grid boundary conditions
#define RIGHT 1.0
#define LEFT 1.0
#define TOP 1.0
#define BOTTOM 10.0

// Algorithm settings
#define TOLERANCE 0.0001
#define NPRINT 1000
#define MAX_ITER 500000

int main(int argc, char*argv[]) {

    int k;
    double tmpnorm,bnorm,norm;

    if (argc !=3) {
        printf("usage: $argv[0] GRIDX GRIDY\n");
        return(1);
    }

    int nx=atoi(argv[1]);
    int ny=atoi(argv[2]);

    int ny2=ny+2;

    printf("grid size %d X %d \n",ny,ny);

    // allocate grid and updated grid
    double *grid= (double*)malloc(sizeof(double)*(nx+2)*(ny+2));
    double *grid_new= (double*)malloc(sizeof(double)*(nx+2)*(ny+2));

    // Initialise Grid boundaries
    int i,j;
    for (i=0; i<ny+2; i++) {
        grid_new[i]=grid[i]=TOP;
        j=(ny+2)*(nx+1)+i;
        grid_new[j]=grid[j]=BOTTOM;
    }
    for (i=1; i<nx+1; i++) {
        j=(ny+2)*i;
        grid_new[j]=grid[j]=LEFT;
        grid_new[j+ny+1]=grid[j+ny+1]=RIGHT;
    }

    // Initialise rest of grid
    for (i=1; i<=nx; i++) {
        for (j=1; j<=ny; j++) {
            k=(ny+2)*i+j;
            grid_new[k]=grid[k]=0.0;
        }
    }


    // This is used to test convergence of the calculation
    tmpnorm=0.0;
    for (i=1; i<=nx; i++) {
        for (j=1; j<=ny; j++) {
            k=(ny+2)*i+j;
            tmpnorm=tmpnorm+pow(grid[k]*4-grid[k-1]-grid[k+1] - grid[k-(ny+2)] - grid[k+(ny+2)], 2);

        }
    }
    bnorm=sqrt(tmpnorm);

    // Main loop
    int iter;
    for (iter=0; iter<MAX_ITER; iter++) {

        // Convergence check
        tmpnorm=0.0;
        for (i=1; i<=nx; i++) {
            for (j=1; j<=ny; j++) {
                k=(ny+2)*i+j;
                tmpnorm=tmpnorm+pow(grid[k]*4-grid[k-1]-grid[k+1] - grid[k-(ny+2)] - grid[k+(ny+2)], 2);
            }
        }

        norm=sqrt(tmpnorm)/bnorm;
        if (norm < TOLERANCE) break;

        // Update new grid
        for (i=1; i<=nx; i++) {
            for (j=1; j<=ny; j++) {
                k=(ny+2)*i+j;
                grid_new[k]=0.25 * (grid[k-1]+grid[k+1] + grid[k-(ny+2)] + grid[k+(ny+2)]);
            }
        }

        // copy updated grid
        memcpy(grid, grid_new, sizeof(double) * (nx + 2) * (ny+2));

        if (iter % NPRINT ==0) printf("Iteration =%d ,Relative norm=%e\n",iter,norm);
    }

    printf("Terminated on %d iterations, Relative Norm=%e \n", iter,norm);


    free(grid);
    free(grid_new);
    return 0;


}
