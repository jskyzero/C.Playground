// 对于两个集合，我们经常对其进行各种各样的集合操作，例如交/并。
// MPI同样提供了对组的集合类操作。

#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv) {
  int myid, numprocs, union_rank;
  MPI_Group group_world, odd_group, even_group, union_group;
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
  MPI_Group_excl(group_world, numprocs / 2, members, &even_group);

  // int MPI_Group_union(MPI_Group group1, MPI_Group group2, MPI_Group *newgroup)
  // int MPI_Group_intersection(MPI_Group group1,MPI_Group group2,MPI_Group *newgroup) 
  // int MPI_Group_difference(MPI_Group group1,MPI_Group group2,MPI_Group *newgroup)
  MPI_Group_union(odd_group, even_group, &union_group);

  MPI_Group_rank(union_group, &union_rank);

  printf("In process %d: union rank is %d\n", myid, union_rank);

  MPI_Finalize();
  return 0;
}