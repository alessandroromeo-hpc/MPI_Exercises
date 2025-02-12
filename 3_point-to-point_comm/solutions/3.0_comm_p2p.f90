program my_prog
   use mpi
   implicit none
   integer :: ierr, nprocs, my_rank, a
   integer status(MPI_STATUS_SIZE)
   call mpi_init(ierr)
   call mpi_comm_size(mpi_comm_world, nprocs, ierr)
   call mpi_comm_rank(mpi_comm_world, my_rank, ierr)

   if (nprocs .NE. 2 .AND. my_rank .EQ. 0) then
      write (*,*) "ERROR: this fortran code should be run with exactly two tasks"
      call exit(1)
   end if
   
   IF( my_rank .EQ. 0 ) THEN
      a = 10
      CALL MPI_SEND(a, 1, MPI_INTEGER, 1, 10, MPI_COMM_WORLD, ierr)
   ELSE IF( my_rank .EQ. 1 ) THEN
      a = 3
      CALL MPI_RECV(a, 1, MPI_INTEGER, 0, 10, MPI_COMM_WORLD, status, ierr)
   END IF
   
   write(*,*) "Hello I am rank number ", my_rank, " and my value of a is ", a
   call mpi_finalize(ierr)
end program my_prog
