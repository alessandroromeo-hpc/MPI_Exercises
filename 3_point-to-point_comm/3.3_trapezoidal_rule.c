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
/* MPI routines, definitions, etc. */

/* Calculate local integral */
double Trap(double left_endpt, double right_endpt, int trap_count, double base_len);

/* Function we’re integrating */
double f(double x);

int main(void) {
    int my_rank, comm_sz, n = 1024, local_n;
    double a = 0.0, b = 3.0, h, local_a, local_b;
    double local_int, total_int;
    int source;

    /* Let the system do what it needs to start up MPI */
    
    /* Get my process rank */
    
    /* Find out how many processes are being used */
    

    /* h is the same for all processes */
    /* So is the number of trapezoids */
    /* Length of each process’ interval of integration = local_n * h. So my interval starts at: */


    /* Add up the integrals calculated by each process */


    /* Print the result */


     /* Shut down MPI */
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
    
    for (i = 1; i <= trap_count - 1; i++) {
        x = left_endpt + i * base_len;
        estimate += f(x);
    }

    estimate = estimate * base_len;
    return estimate;
} /* Trap */

/*------------------------------------------------------------------
* Function: f
* Purpose: Compute value of function to be integrated
* Input args: x
*/
double f(double x) {
    return x * x;
} /* f */