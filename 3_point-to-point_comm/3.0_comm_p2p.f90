program my_prog
   use FIXME
   implicit none
   integer :: ierr, nprocs, my_rank, a
   integer status(FIXME)
   FIXME
   call mpi_FIXME(mpi_comm_world, nprocs, ierr)
   call mpi_FIXME(mpi_comm_world, my_rank, ierr)

   if (nprocs .NE. 2 .AND. my_rank .EQ. 0) then
      write (*,*) "ERROR: this fortran code should be run with exactly two tasks"
      call exit(1)
   end if
   
   IF( my_rank .EQ. FIXME ) THEN
      a = 10
      CALL MPI_SEND(FIXME)
   ELSE IF( my_rank .EQ. FIXME ) THEN
      a = 3
      CALL MPI_RECV(FIXME)
   END IF
   
   write(*,*) "Hello I am rank number ", my_rank, " and my value of a is ", a
   FIXME
end program my_prog
