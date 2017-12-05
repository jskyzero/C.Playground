#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv) {
  int myid, numprocs;
  double start, finish;

  MPI_Init(&argc, &argv);

  MPI_Comm_rank(MPI_COMM_WORLD, &myid);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);

  start = MPI_Wtime();
  MPI_Barrier(MPI_COMM_WORLD);
  printf("I'm rank %d of %d", myid, numprocs);
  finish = MPI_Wtime();
  printf("running %f seconds.\n", finish - start);

  MPI_Finalize();
  return 0;
}