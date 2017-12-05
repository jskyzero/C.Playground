/*
 * jskyzero 2017(R) in SYSU
 * create 10 thread and calcute
 */

#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define THREAD_NUMBER 10

// initial mutex
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
// glabal data store
int sum = 0;

// thread function
void *inc(void *arg) {
  int i = (*(int *)arg);
  // lock
  pthread_mutex_lock(&mutex);
  sum = sum + i;
  // unlock
  pthread_mutex_unlock(&mutex);
  return NULL;
}

int main(int argc, char *argv[]) {
  pthread_t pt[THREAD_NUMBER];
  int args[THREAD_NUMBER];
  for (int i = 0; i < THREAD_NUMBER; i++) {
    args[i] = i;
    if (pthread_create(&pt[i], NULL, inc, (void *)&args[i]) != 0)
    {
      printf("pthread_create error\n");
      exit(1);
    }
  }
  
  for (int i = 0; i < THREAD_NUMBER; i++)
  {
    if (pthread_join(pt[i], NULL) != 0) {
      printf("pthread_join error\n");
      exit(1);
    }
  }

  printf("sum is %d\n", sum);
  // distory mutex
  pthread_mutex_destroy(&mutex);
  return 0;
}
