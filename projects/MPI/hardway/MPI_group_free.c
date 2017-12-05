// 既然有了组的构造，那么与之对应也存在组的析构。

#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv) {
  int myid, numprocs;
  MPI_Group group_world;
  int size0;

  MPI_Init(&argc, &argv);

  MPI_Comm_rank(MPI_COMM_WORLD, &myid);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);

  MPI_Comm_group(MPI_COMM_WORLD, &group_world);

  MPI_Group_size(group_world, &size0);

  if (myid == 0) {
    printf("Now the size is %d\n", size0);
  }

  // int MPI_Group_free(MPI_Group *group)
  // 调用函数会标记一个被释放的组对象，组句柄被调用置为MPI_GROUP_NULL。
  // 任何正在使用此组的操作将正常完成。
  MPI_Group_free(&group_world);

  if (myid == 0) {
    if (group_world == MPI_GROUP_NULL) printf("Now the group is freed.\n");
  }

  MPI_Finalize();
  return 0;
}