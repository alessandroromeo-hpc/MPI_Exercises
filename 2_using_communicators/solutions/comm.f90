program my_prog
   use mpi
   implicit none
   integer :: ierr, nprocs, my_rank
   call mpi_init(ierr)
   call mpi_comm_size(mpi_comm_world, nprocs, ierr)
   call mpi_comm_rank(mpi_comm_world, my_rank, ierr)
   write(*,*) "Hello I am ",my_rank," of ", nprocs
   call mpi_finalize(ierr)
end program my_prog
