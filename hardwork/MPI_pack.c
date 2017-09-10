
// [Surface-Pro-3:8772] *** An error occurred in MPI_Unpack
// [Surface-Pro-3:8772] *** reported by process [1590624257,1]
// [Surface-Pro-3:8772] *** on communicator MPI_COMM_WORLD
// [Surface-Pro-3:8772] *** MPI_ERR_TRUNCATE: message truncated
// [Surface-Pro-3:8772] *** MPI_ERRORS_ARE_FATAL (processes in this communicator will now abort,
// [Surface-Pro-3:8772] ***    and potentially your MPI job)

#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv) {
  int myid, numprocs, source;
  MPI_Status status;
  int i, j, position;
  int k[2];
  int buf[1000];

  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &myid);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);

  i = 1;
  j = 2;

  if (myid == 0) {
    position = 0;

    MPI_Pack(&i, 1, MPI_INT, buf, 1000, &position, MPI_COMM_WORLD);
    MPI_Pack(&j, 1, MPI_INT, buf, 1000, &position, MPI_COMM_WORLD);

    MPI_Send(buf, position, MPI_PACKED, 1, 99, MPI_COMM_WORLD);
  } else if (myid == 1) {
    MPI_Recv(k, 2, MPI_INT, 0, 99, MPI_COMM_WORLD, &status);

    position = 0;
    i = j = 0;

    // your code here
    MPI_Unpack(k, 2, &position, &i, 1, MPI_INT, MPI_COMM_WORLD);
    MPI_Unpack(k, 2, &position, &j, 1, MPI_INT, MPI_COMM_WORLD);
    // end of your code

    printf("The number is %d and %d", i, j);
  }

  MPI_Finalize();
  return 0;
}
