// 在之前的学习中，我们经常使用系统帮助我们创建的初始组内通信子MPI_COMM_WORLD作为通信子的输入。
//    其实，还有两个系统默认创建的通信子，一个是COMM_SELF，另一个是COMM_NULL。
//    COMM_SELF仅仅包含了当前进程，而COMM_NULL则什么进程都没有包含。
// 在通信子的创建中，需要特别注意的是MPI中有一个"鸡生蛋, 蛋生鸡"的特点，
//   即所有MPI通信子的创建都是由基础通信子，即MPI_COMM_WORLD（是在MPI的外部被定义的），创建的。
//   而这些被创建的通信子又可以作为新的通信子创建的基础。
#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv) {
  int myid, numprocs;
  MPI_Comm new_comm;
  int result;

  MPI_Init(&argc, &argv);

  MPI_Comm_rank(MPI_COMM_WORLD, &myid);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);

  // int MPI_Comm_dup(MPI_Comm comm,MPI_Comm *newcomm)
  MPI_Comm_dup(MPI_COMM_WORLD, &new_comm);

  MPI_Comm_compare(MPI_COMM_WORLD, new_comm, &result);

  // MPI_IDENT表示上下文(context)和组(group)都相同，
  // MPI_CONGRUENT表示上下文不同(different)但组完全相同(identical)，
  // MPI_SIMILAR表示上下文不同，组的成员相同但次序不同(similar)，
  // 否则就是MPI_UNEQUAL。
  if (myid == 0) {
    if (result == MPI_IDENT) {
      printf("The comms are identical.\n");
    } else if (result == MPI_CONGRUENT) {
      printf("The comms are congruent.\n");
    } else if (result == MPI_SIMILAR) {
      printf("The comms are similar.\n");
    } else if (result == MPI_UNEQUAL) {
      printf("The comms are unequal.\n");
    }
  }

  MPI_Finalize();
  return 0;
}