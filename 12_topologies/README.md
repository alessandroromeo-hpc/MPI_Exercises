# 12.1 Create a 4 x 4 Cartesian topology from 16 processors and have each process exchange its rank with four neighbors. Create a cartesian virtual topology. Make each process print out the ranks of their neighbours (up, down, left, right). 


## How to compile

# Leo Booster
mpicc 12.1_cartesian.c -o cart_c.exe

# Leo DCGP
mpiicx 12.1_cartesian.c -o cart_c.exe



# 12.2 Create a communicator representing a 2D torus topology.  Ask MPI to decompose our processes in a 2D cartesian grid for us and remember to make both dimensions periodic. Print each process location in the 2D torus.

## How to compile

# Leo Booster
mpicc 12.2_torus.c -o torus_c.exe

# Leo DCGP
mpiicx 12.2_torus.c -o torus_c.exe
