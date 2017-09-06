#include <mpi.h>
#include <stdio.h>

int main (int argc, char **argv) {
  MPI_Init(&argc, &argv);

  printf("%s\n", "helloworld");

  MPI_Finalize();

  return 0;
}