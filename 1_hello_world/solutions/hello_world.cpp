#include <iostream>
#include <mpi.h>

int main(int argc, char * argv[]){
     int err;

     err = MPI_Init(&argc, &argv);

     std:: cout << "Hello world (C++ version)!" << std::endl;

     err = MPI_Finalize();

     return 0;
}
