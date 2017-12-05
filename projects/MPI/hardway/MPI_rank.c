#include <mpi.h>
#include <time.h>
#include <stdio.h>

void print_now_time() {
  time_t rawtime;
  struct tm * timeinfo;

  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  printf ( "Current local time and date: %s", asctime (timeinfo) );

  printf("Current Timer: %f\n\n", ((float)clock())/CLOCKS_PER_SEC);
}


int main(int argc, char **argv) {

  int process_id, process_num;
  
  MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &process_num);
    MPI_Comm_rank(MPI_COMM_WORLD, &process_id);
    printf("total has %d, now is %d\n", process_num, process_id);
    print_now_time();
  MPI_Finalize();
  
  return 0;
}