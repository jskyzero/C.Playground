#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv) {
  int myid, numprocs;
  MPI_Group group_world;
  int rank_of_group;

  MPI_Init(&argc, &argv);

  MPI_Comm_rank(MPI_COMM_WORLD, &myid);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);

  // int MPI_Comm_group(MPI_Comm comm, MPI_Group *group)
  // MPI_Comm_group用来建立一个通信组对应的新进程组
  // int MPI_Group_rank(MPI_Group group, int *rank)
  // MPI_Group_rank查询调用进程在进程组里的rank
  MPI_Comm_group(MPI_COMM_WORLD, &group_world);
  MPI_Group_rank(group_world, &rank_of_group);

  printf("myid: %d rank: %d\n", myid, rank_of_group);

  MPI_Finalize();
  return 0;
}