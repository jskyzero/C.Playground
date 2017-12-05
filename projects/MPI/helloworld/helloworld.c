#include <mpi.h>
#include <stdio.h>

int main (int argc, char **argv) {

  // 通过MPI_Init函数进入MPI环境并完成所有的初始化工作，标志并行代码的开始。
  MPI_Init(&argc, &argv);

  printf("%s\n", "helloworld");

  // 通过MPI_Finalize函数从MPI环境中退出，标志并行代码的结束，
  // 如果不是MPI程序最后一条可执行语句，则运行结果不可知。
  MPI_Finalize();

  return 0;
}