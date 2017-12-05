// 对两个进程组做最基本的判断，例如成员是否相同，次序是否一致等等。

#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv) {
  int myid, numprocs;
  MPI_Group group_world, new_group_world;
  int members[5];
  int result;

  MPI_Init(&argc, &argv);

  MPI_Comm_rank(MPI_COMM_WORLD, &myid);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);

  MPI_Comm_group(MPI_COMM_WORLD, &group_world);

  members[0] = 0;

  MPI_Group_incl(group_world, 1, members, &new_group_world);

  if (myid == 0) {
    // int MPI_Group_compare(MPI_Group group1, MPI_Group group2, int *result)
    MPI_Group_compare(group_world, group_world, &result);

    if (result == MPI_IDENT) {
      printf("Now the groups are identical.\n");
    } else if (result == MPI_SIMILAR) {
      printf("Now the groups are similar.\n");
    } else {
      printf("Now the groups are unequal.\n");
    }

    // 如果在两个组中成员和次序完全相等，返回MPI_IDENT。
      // 例如在group1和group2是同一句柄时就会发生这种情况。
    // 如果组成员相同而次序不同则返回MPI_SIMILAR，否则返回MPI_UNEQUAL。
    MPI_Group_compare(new_group_world, group_world, &result);
    

    if (result == MPI_IDENT) {
      printf("Now the groups are identical.\n");
    } else if (result == MPI_SIMILAR) {
      printf("Now the groups are similar.\n");
    } else {
      printf("Now the groups are unequal.\n");
    }
  }

  MPI_Finalize();
  return 0;
}