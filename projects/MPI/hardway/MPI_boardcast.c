// 一个进程的数据被发送到通信子中的所有进程，这样的集合通信叫做广播。

#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv) {
  int myid, numprocs;
  int source = 0;
  int array[5] = {0, 0, 0, 0, 0};
  int i;

  MPI_Init(&argc, &argv);

  MPI_Comm_rank(MPI_COMM_WORLD, &myid);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);

  if (myid == source) {
    for (i = 1; i <= 5; i++) array[i] = i;
  }

  // int MPI_Bcast(void* buffer, int count, MPI_Datatype datatype, int source, MPI_Comm comm)
  MPI_Bcast(array, 5, MPI_INT, source, MPI_COMM_WORLD);

  if (myid != source) {
    printf("In process %d, ", myid);
    for (i = 0; i < 5; i++) printf("arr[%d]=%d\t", i, array[i]);
    printf("\n");
  }

  MPI_Finalize();
  return 0;
}