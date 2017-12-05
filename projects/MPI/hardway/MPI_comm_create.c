#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv) {
  int myid, numprocs, new_numprocs;
  MPI_Group group_world, odd_group;
  MPI_Comm new_comm;
  int i;
  int members[10];

  MPI_Init(&argc, &argv);

  MPI_Comm_rank(MPI_COMM_WORLD, &myid);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);

  MPI_Comm_group(MPI_COMM_WORLD, &group_world);

  for (i = 0; i < numprocs / 2; i++) {
    members[i] = 2 * i + 1;
  }

  MPI_Group_incl(group_world, numprocs / 2, members, &odd_group);

  // int MPI_Comm_create(MPI_Comm comm, MPI_Group group, MPI_Comm *newcomm)
  MPI_Comm_create(MPI_COMM_WORLD, group_world, &new_comm);

  if (myid % 2 != 0) {
    MPI_Comm_size(new_comm, &new_numprocs);

    printf("The new comm's size is %d.\n", new_numprocs);
  }

  MPI_Finalize();
  return 0;
}