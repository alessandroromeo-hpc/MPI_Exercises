/* File: mpi_trap4.c
* Purpose: Use MPI to implement a parallel version of the trapezoidal rule.
* This version uses collective communications and MPI derived datatypes
* to distribute the input data and compute the global sum.
*
* Input: The endpoints of the interval of integration and the number of trapezoids
* Output: Estimate of the integral from a to b of f(x) using the trapezoidal rule and n trapezoids.
*
* Compile: mpicc -g -Wall -o mpi_trap4 mpi_trap.c
* Run: mpiexec -n <number of processes> ./mpi_trap
*
* Algorithm:
* 1. Each process calculates "its" interval of integration.
* 2. Each process estimates the integral of f(x) over its interval using the trapezoidal rule.
* 3a. Each process != 0 sends its integral to 0.
* 3b. Process 0 sums the calculations received from the individual processes and prints the result.
*
* Note: f(x) is all hardwired.
* IPP: Section 3.2.2 (pp. 96 and ff.)
*/
#include <stdio.h>
#include <mpi.h> /* MPI routines, definitions, etc. */

/* Function to build MPI data structure for data to be broadcasted */
void Build_mpi_type(double* a_p, double* b_p, int* n_p, MPI_Datatype* input_mpi_t_p);

/* Get the input values */
void Get_input(int my_rank, int comm_sz, double* a_p, double* b_p, int* n_p);

/* Calculate local integral */
double Trap(double left_endpt, double right_endpt, int trap_count, double base_len);

/* Function we’re integrating */
double f(double x);

int main(void) {
    int my_rank, comm_sz, n, local_n, source;
    double a, b, h, local_a, local_b, local_int, total_int;

    /* Let the system do what it needs to start up MPI */
    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank); /* Get my process rank */
    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz); /* Find out how many processes are being used */

    Get_input(my_rank, comm_sz, &a, &b, &n);
    
    h = (b - a) / n; /* h is the same for all processes */
    local_n = n/comm_sz; /* So is the number of trapezoids */
    /* Length of each process’ interval of integration = local_n*h. So my interval starts at: */
    local_a = a + my_rank * local_n * h;
    local_b = local_a + local_n * h;
    local_int = Trap(local_a, local_b, local_n, h);
    
    /* Add up the integrals calculated by each process */
    if (my_rank != 0) {
        printf("PE[%d] SEND: For %d trapezoids, local estimate=%f\n",my_rank, local_n, local_int);
        MPI_Send(&local_int, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
    }
    else {
        total_int = local_int;
        for (source = 1; source < comm_sz; source++) {
            MPI_Recv(&local_int, 1, MPI_DOUBLE, source, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            printf("PE[%d] RECV from PE[%d]: local estimate=%f \n", my_rank,source, local_int);
            total_int += local_int;
        } 
    }

    /* Print the result */
    if (my_rank == 0)
    printf("With n = %d trapezoids, our estimate of the integral from %f to %f = %.15e\n", n, a, b, total_int);

    MPI_Finalize(); /* Shut down MPI */
    
    return 0;
} /* main */

/*------------------------------------------------------------------
* Function: Trap
* Purpose: Serial function for estimating a definite integral
* using the trapezoidal rule
* Input args: left_endpt
* right_endpt
* trap_count
* base_len
* Return val: Trapezoidal rule estimate of integral from
* left_endpt to right_endpt using trap_count
* trapezoids
*/
double Trap(double left_endpt, double right_endpt, int trap_count, double base_len) {
    double estimate, x;
    int i;
    
    estimate = (f(left_endpt) + f(right_endpt))/2.0;
    
    for (i = 1; i <= trap_count-1; i++) {
        x = left_endpt + i*base_len;
        estimate += f(x);
    }

    estimate = estimate*base_len;
    return estimate;
} /* Trap */

/*------------------------------------------------------------------
* Function: f
* Purpose: Compute value of function to be integrated
* Input args: x
*/
double f(double x) {
    return x*x;
} /* f */


void Build_mpi_type(double* a_p, double* b_p, int* n_p, MPI_Datatype* input_mpi_t_p) {
    int array_of_blocklengths[3] = {1, 1, 1};
    
    MPI_Datatype array_of_types[3] = {MPI_DOUBLE, MPI_DOUBLE, MPI_INT};
    MPI_Aint a_addr, b_addr, n_addr;
    MPI_Aint array_of_displacements[3] = {0};

    MPI_Get_address(a_p, &a_addr);
    MPI_Get_address(b_p, &b_addr);
    MPI_Get_address(n_p, &n_addr);
    
    array_of_displacements[1] = b_addr - a_addr;
    array_of_displacements[2] = n_addr - a_addr;

    MPI_Type_create_struct(3, array_of_blocklengths, array_of_displacements, array_of_types, input_mpi_t_p);
    MPI_Type_commit(input_mpi_t_p);
}

/*------------------------------------------------------------------
* Function: Get_input
* Purpose: Get the user input: the left and right endpoints
* and the number of trapezoids
* Input args: my_rank: process rank in MPI_COMM_WORLD
* comm_sz: number of processes in MPI_COMM_WORLD
* Output args: a_p: pointer to left endpoint
* b_p: pointer to right endpoint
* n_p: pointer to number of trapezoids
*/
void Get_input(int my_rank, int comm_sz, double* a_p, double* b_p, int* n_p)
{
    MPI_Datatype input_mpi_t;
    
    Build_mpi_type(a_p , b_p , n_p , &input_mpi_t);
    if(my_rank == 0) {
        printf(" Enter a, b, and n\n");
        scanf("%lf %lf %d", a_p , b_p , n_p);
    }   
    
    MPI_Bcast(a_p , 1, input_mpi_t , 0, MPI_COMM_WORLD);
    MPI_Type_free(&input_mpi_t);
} 