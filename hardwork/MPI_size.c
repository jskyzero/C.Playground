#include <mpi.h>
#include <stdio.h>

int main(int argc, char**argv) {
  int process_num;
  MPI_Init(&argc, &argv);
  
  // int MPI_Comm_size(MPI_Comm comm, int *rank)
  // 获取指定通信域的进程个数。
  // 第一个参数是通信子，第二个参数返回进程的个数。
  MPI_Comm_size(MPI_COMM_WORLD, &process_num);
  
  printf("the process num is %d\n", process_num);

  MPI_Finalize();
  return 0;
}