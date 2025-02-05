program hello

  use mpi

  implicit none

  integer ierr, me, nprocs
  integer status(MPI_STATUS_SIZE)

  integer,parameter :: ndata = 10000
  real              :: a(ndata)
  real              :: b(ndata)

  call MPI_INIT(ierr)
  call MPI_COMM_SIZE(MPI_COMM_WORLD, nprocs, ierr)
  call MPI_COMM_RANK(MPI_COMM_WORLD, me, ierr)

  !$ Initialize data 
  a = me
  !$ Protect against the use with a number of processes != 2
  if (nprocs .ne. 2) then
     FIXME
  endif
  
  !$ Send and Receive data    
  FIXME

  print *,'I am proc ',me,' and I have received b(1) = ',b(1)
  call MPI_FINALIZE(ierr)

end program hello
