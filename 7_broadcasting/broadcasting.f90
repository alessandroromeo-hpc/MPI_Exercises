PROGRAM main

IMPLICIT NONE

 include 'mpif.h'

 INTEGER :: ierr, my_id, num_procs,inserted_num,modified_num,buffer

 CALL MPI_INIT( ierr )
 CALL MPI_COMM_RANK( MPI_COMM_WORLD, my_id, ierr )
 CALL MPI_Comm_size ( MPI_COMM_WORLD, num_procs, ierr )

 IF( my_id == 0) THEN
! WRITE(*,*) "Insert an integer value : " ! In case of interactive run 
! READ(*,*) inserted_num
 inserted_num = FIXME 
 modified_num = FIXME
 ELSE
 inserted_num = FIXME
 modified_num = FIXME
 ENDIF

 CALL MPI_FIXME(FIXME, FIXME, FIXME, FIXME, FIXME, FIXME)

 WRITE(*,*) "my_id", my_id, "inserted_num", inserted_num, "modified_num", modified_num

 CALL MPI_FINALIZE(ierr)

END PROGRAM main
