program my_prog
   use mpi
   implicit none
   integer :: ierr, nprocs, my_rank
   real a(2), b(2)
   integer req0(2), req1(2)
   
   call mpi_init(ierr)
   call mpi_comm_size(mpi_comm_world, nprocs, ierr)
   call mpi_comm_rank(mpi_comm_world, my_rank, ierr)

   
   IF( my_rank .EQ. 0 ) THEN
      a(1) = 2.0
      a(2) = 4.0
      CALL MPI_ISEND(a, 2, MPI_REAL, 1, 10, MPI_COMM_WORLD, req0(1), ierr) 
      CALL MPI_IRECV(b, 2, MPI_REAL, 1, 11, MPI_COMM_WORLD, req0(2), ierr)
      !b(1) = b(1) + 10.0
      CALL MPI_WAITALL(2, req0, MPI_STATUSES_IGNORE, ierr)
      !b(1) = b(1) + 10.0
   ELSE IF( my_rank .EQ. 1 ) THEN
      a(1) = 3.0
      a(2) = 5.0
      CALL MPI_ISEND(a, 2, MPI_REAL, 0, 11, MPI_COMM_WORLD, req1(1), ierr)
      CALL MPI_IRECV(b, 2, MPI_REAL, 0, 10, MPI_COMM_WORLD, req1(2), ierr)
      CALL MPI_WAITALL(2, req1, MPI_STATUSES_IGNORE, ierr)
   END IF
   
   write(*,*) "Hello I am rank number ", my_rank, " and my a array is ", a(1), " ", a(2)
   write(*,*) "Hello I am rank number ", my_rank, " and my b array is ", b(1), " ", b(2)
   call mpi_finalize(ierr)
end program my_prog
