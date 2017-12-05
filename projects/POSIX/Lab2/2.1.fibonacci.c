#include <stdio.h>    // for printf()
#include <stdlib.h>   // for atoi()
#include <string.h>   // for memset()
#include <assert.h>   // for assert()
#include <pthread.h>  // for pthread_*

// int cal_size.py we can konw 50 is enough for 4byte signed integer
#define ARRAY_SIZE 47

// argument struct type
struct FIB_ARGU {
  int size;
  int array[ARRAY_SIZE];
};

typedef struct FIB_ARGU FIB_ARGU_TYPE; 

void *calcute(void*);

// main func
int main(int argv, char *args[]) {
  // run with only one num 
  if (argv != 2)
    printf("Usage: fibonacci size\n");

  // initial argument
  FIB_ARGU_TYPE argu;
  argu.size = atoi(args[1]);
  assert(argu.size >= 0);
  assert(argu.size < ARRAY_SIZE);
  assert(sizeof(argu.array) == sizeof(int) * ARRAY_SIZE);
  memset(argu.array, 0, sizeof(argu.array));
  argu.array[0] = 0;
  argu.array[1] = 1;

  // calcute 
  pthread_t thread;
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  assert( 0 == pthread_create(&thread, &attr, calcute, &argu));
  pthread_join(thread, NULL);

  // print ans
  for (int i = 0; i <= argu.size; i++) {
    printf("%d ", argu.array[i]);
  }
  puts("");
  return 0;
}

void *calcute(void* argv) {

  FIB_ARGU_TYPE * data_p = (FIB_ARGU_TYPE *)argv;

  for (int i = 2; i <= data_p->size; i++) {
    data_p->array[i] = data_p->array[i-1] + data_p->array[i-2];
  }

  return NULL;
}