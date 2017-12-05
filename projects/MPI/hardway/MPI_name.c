#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv) {
  int len;
  char name[MPI_MAX_PROCESSOR_NAME];
  MPI_Init(&argc, &argv);

  // int MPI_Get_processor_name ( char *name, int *resultlen)
  // char *name : 实际节点的唯一说明字;
  // int *resultlen：在name中返回结果的长度;
  MPI_Get_processor_name(name, &len);

  printf("Hello, world. I am %s.\n", name);

  MPI_Finalize();
  return 0;
}