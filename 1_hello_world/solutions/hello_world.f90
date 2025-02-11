program my_prog
   use mpi
   implicit none

   integer :: ierr

   call mpi_init(ierr)

   write(*,*) "Hello world (Fortran version)!"

   call mpi_finalize(ierr)
end program my_prog
