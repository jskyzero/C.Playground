// 基于已经存在的进程组创建一个新的组，并指明被包含(included)其中的成员进程。

#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv) {
  int myid, numprocs, odd_rank;
  MPI_Group group_world, odd_group;
  int i;
  int members[10];

  MPI_Init(&argc, &argv);

  MPI_Comm_rank(MPI_COMM_WORLD, &myid);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);

  MPI_Comm_group(MPI_COMM_WORLD, &group_world);

  for (i = 0; i < numprocs / 2; i++) {
    members[i] = 2 * i + 1;
  }

  // int MPI_Group_incl(MPI_Group old_group, int count, 
                     // int *members, MPI_Group *new_group)
  MPI_Group_incl(group_world, numprocs / 2, members, &odd_group);

  MPI_Group_rank(odd_group, &odd_rank);

  printf("In process %d: odd rank is %d\n", myid, odd_rank);

  MPI_Finalize();
  return 0;
}