// 有时候我们希望根据拓扑来创建不同的域，例如创建一个二维数组，显然一个个创建是很不方便的，
// 这时候我们需要用到一个新的函数来进行划分。

#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv) {
  int myid, numprocs;
  MPI_Comm row_comm, column_comm;
  int myrow, mycolumn;
  int color = 3;

  MPI_Init(&argc, &argv);

  MPI_Comm_rank(MPI_COMM_WORLD, &myid);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);

  myrow = myid / color;
  mycolumn = myid % color;

  // int MPI_Comm_split(MPI_Comm comm, int color, int key, MPI_Comm *newcomm)
  MPI_Comm_split(MPI_COMM_WORLD, mycolumn, myrow, &row_comm);
  MPI_Comm_split(MPI_COMM_WORLD, myrow, mycolumn, &column_comm);

  int rowsum, columnsum;

  rowsum = myid;
  columnsum = myid;

  MPI_Allreduce(MPI_IN_PLACE, &rowsum, 1, MPI_INT, MPI_SUM, row_comm);
  MPI_Allreduce(MPI_IN_PLACE, &columnsum, 1, MPI_INT, MPI_SUM, column_comm);

  printf(
      "I'm process %d, my coordinates are (%d, %d), row sum is %d, column sum "
      "is %d\n",
      myid, myrow, mycolumn, rowsum, columnsum);

  MPI_Finalize();
  return 0;
}