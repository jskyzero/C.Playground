// 如果知道了在组MPI_COMM_WORLD中某些进程的编号，
//    如何根据这些编号来操作在不同组的同一进程来完成不同的任务呢？

#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv) {
  int myid, numprocs;
  MPI_Group group_world, group1, group2;
  int i;
  int ranks1[10];
  int ranks2[10];
  int ranks_output[10];

  MPI_Init(&argc, &argv);

  MPI_Comm_rank(MPI_COMM_WORLD, &myid);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);

  MPI_Comm_group(MPI_COMM_WORLD, &group_world);

  for (i = 0; i < numprocs - 1; i++) {
    ranks1[i] = i;
    ranks2[i] = i + 1;
  }

  MPI_Group_incl(group_world, numprocs - 1, ranks1, &group1);
  MPI_Group_incl(group_world, numprocs - 1, ranks2, &group2);

  // int MPI_Group_translate_ranks(MPI_Group group1, int count, int *ranks1, 
  //                               MPI_Group group2, int *ranks2)
  MPI_Group_translate_ranks(group1, numprocs - 1, ranks1,
                            group2, ranks_output);

  if (myid == 0) {
    for (i = 0; i < numprocs - 1; i++) {
      printf("The group1 rank %d in group2 is: %d\n", ranks1[i], ranks_output[i]);
    }
  }

  MPI_Finalize();
  return 0;
}