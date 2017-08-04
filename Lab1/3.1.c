#include <stdio.h> // for printf()
#include <unistd.h> // for fork()
#include <sys/shm.h> // for shmget() shmat()
#include <sys/stat.h> // for S_IRUSR, S_IWUSR
#include <stdlib.h>  // for exit()
#include <assert.h> // for assert()

#define MAX_SEQUENCE 10

// share memory structure
typedef struct {
  long fib_sequence[MAX_SEQUENCE];
  int sequence_size;
} share_data;

int main(int argv, char *args[])
{
  // run with only one num 
  assert(argv == 2);
  // get size 
  int size = atoi(args[1]);
  // check size
  if (size >= MAX_SEQUENCE) {
    puts("args size too big\n");
    exit(1);
  }
  // begin to store info about shm
  int pid;
  int segment_id;
  share_data *share;
  // ask shm and connecte
  segment_id = shmget(IPC_PRIVATE, sizeof(share_data), S_IRUSR | S_IWUSR);
  share = (share_data *) shmat(segment_id, NULL, 0);
  // initial size
  share->sequence_size = size;
  // fork()
  if ((pid = fork())) {
    // wait sub process finished
    wait(NULL);
    // father process print and 
    for (int i = 0 ; i < share->sequence_size; i++) {
      printf("%ld ", share->fib_sequence[i]);
    }
    puts("\n");
    // close connection
    shmdt(share);
    // free shm
    shmctl(segment_id, IPC_RMID, NULL);
  } else {
    // sub process
    // intial fib[0] and fib[1]
    share->fib_sequence[0] = 0;
    share->fib_sequence[1] = 1;
    // calculate later fib[i] 
    for (int i = 2 ; i < share->sequence_size; i++) {
      share->fib_sequence[i] = share->fib_sequence[i-1] + share->fib_sequence[i-2];
    }
    // close connection
    shmdt(share);

    // why no connection ? 
    // sub process have a connection from father process
  }
}
