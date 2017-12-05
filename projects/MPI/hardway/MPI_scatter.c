// 与收集（gather）相对应也有一个相反的集合通信操作，
// 即根进程向所有进程发送缓冲区的数据，称为散发。

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  int myid, numprocs;
  int source = 0;
  int *sbuf;
  int rbuf[5];
  int i;

  MPI_Init(&argc, &argv);

  MPI_Comm_rank(MPI_COMM_WORLD, &myid);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);

  if (myid == source) {
    sbuf = (int *)malloc(numprocs * 5 * sizeof(int));

    for (int i = 0; i < numprocs * 5; i++) {
      sbuf[i] = i;
    }
  }

  // int MPI_Scatter(void* sendbuf, int sendcount, MPI_Datatype sendtype,
                  // void* recvbuf, int recvcount, MPI_Datatype recvtype,
                  // int root, MPI_Comm comm)
  MPI_Scatter(sbuf, 5, MPI_INT,
              rbuf, 5, MPI_INT,
              source, MPI_COMM_WORLD);

  printf("Now is process %d: ", myid);
  for (i = 0; i < 5; i++) {
    printf("array[%d]=%d\t", i, rbuf[i]);
  }
  printf("\n");

  MPI_Finalize();
  return 0;
}