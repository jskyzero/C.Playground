// 在一个进程中从所有进程获取信息，
// 例如将所有进程中的一个数组都收集到根进程中作进一步的处理，这样的集合通信我们叫做收集。

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  int myid, numprocs;
  int dest = 0;
  int array[5] = {1, 2, 3, 4, 5};
  int *rbuf;
  int i, j;

  MPI_Init(&argc, &argv);

  MPI_Comm_rank(MPI_COMM_WORLD, &myid);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);

  if (myid == dest) {
    rbuf = (int *)malloc(numprocs * 5 * sizeof(int));
  }

  // int MPI_Gather(void* sendbuf, int sendcount, MPI_Datatype sendtype, 
                 // void* recvbuf, int recvcount, MPI_Datatype recvtype, 
                 // int root, MPI_Comm comm)your code here
  MPI_Gather(array, 5, MPI_INT,
             rbuf,  5, MPI_INT,
             dest, MPI_COMM_WORLD);

  if (myid == dest) {
    for (i = dest + 1; i < numprocs; i++) {
      printf("Now is process %d's data: ", i);
      for (j = 0; j < 5; j++) {
        printf("array[%d]=%d\t", j, rbuf[i * 5 + j]);
      }
      printf("\n");
    }
  }

  MPI_Finalize();
  return 0;
}