program my_prog
   use mpi
   implicit none
   integer :: ierr, nprocs, my_rank, i
   integer, parameter :: cnt = 10000
   real, dimension(cnt) :: a, b
   integer, dimension(cnt) :: status
   
   call mpi_init(ierr)
   call mpi_comm_size(mpi_comm_world, nprocs, ierr)
   call mpi_comm_rank(mpi_comm_world, my_rank, ierr)

   IF( my_rank .EQ. 0 ) THEN
      DO i = 1, cnt, 1
         a(i) = 2.0*i
      END DO
               
      CALL MPI_RECV(b, cnt, MPI_REAL, 1, 11, MPI_COMM_WORLD, status, ierr)
      CALL MPI_SEND(a, cnt, MPI_REAL, 1, 10, MPI_COMM_WORLD, ierr) 
   ELSE IF( my_rank .EQ. 1 ) THEN
      DO i = 1, cnt, 1
         a(i) = 2.0*i + 1.0
      END DO

      CALL MPI_SEND(a, cnt, MPI_REAL, 0, 11, MPI_COMM_WORLD, ierr)
      CALL MPI_RECV(b, cnt, MPI_REAL, 0, 10, MPI_COMM_WORLD, status, ierr)
   END IF
   
   write(*,*) "Hello I am rank number ", my_rank, " and my a array is ", a(1), " ", a(2)
   write(*,*) "Hello I am rank number ", my_rank, " and my b array is ", b(1), " ", b(2)
   call mpi_finalize(ierr)
end program my_prog
