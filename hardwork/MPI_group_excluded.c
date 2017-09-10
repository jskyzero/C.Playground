// 基于旧进程组创建一个新的组的时候，可能希望排除一些成员进程。
#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv) {
  int myid, numprocs, even_rank;
  MPI_Group group_world, even_group;
  int i;
  int nonmembers[10];

  MPI_Init(&argc, &argv);

  MPI_Comm_rank(MPI_COMM_WORLD, &myid);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);

  MPI_Comm_group(MPI_COMM_WORLD, &group_world);

  for (i = 0; i < numprocs / 2; i++) {
    nonmembers[i] = 2 * i + 1;
  }

  // int MPI_Group_excl(MPI_Group old_group, int count, 
                     // int *nonmembers, MPI_Group *new_group)
  MPI_Group_excl(group_world, numprocs / 2, nonmembers, &even_group);

  MPI_Group_rank(even_group, &even_rank);

  printf("In process %d: even rank is %d\n", myid, even_rank);

  MPI_Finalize();
  return 0;
}

