/*
 * jskyzero 2017(R) in SYSU
 * learn to use semaphore
 */

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 3

int nitems;
typedef struct sto {
  int buffer[BUFF_SIZE];
  sem_t mutex, nempty, nstored;
} sto_type;
sto_type shared;

void *produce(void *);
void *consume(void *);

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage: prodcons number\n");
    exit(0);
  }
  pthread_t tid_produce, tid_consumer;
  nitems = atoi(argv[1]);
  sem_init(&shared.mutex, 0, 1);
  sem_init(&shared.nempty, 0, BUFF_SIZE);
  sem_init(&shared.nstored, 0, 0);
  pthread_create(&tid_produce, NULL, produce, NULL);
  pthread_create(&tid_consumer, NULL, consume, NULL);
  pthread_join(tid_produce, NULL);
  pthread_join(tid_consumer, NULL);
  sem_destroy(&shared.mutex);
  sem_destroy(&shared.nempty);
  sem_destroy(&shared.nstored);
  exit(0);
}

void *produce(void *arg) {
  int i;
  for (i = 0; i < nitems; i++) {
    sem_wait(&shared.nempty);
    sem_wait(&shared.mutex);
    shared.buffer[i % BUFF_SIZE] = i;
    printf("%s %d\n", "Product", shared.buffer[i % BUFF_SIZE]);
    sem_post(&shared.mutex);
    sem_post(&shared.nstored);
  }
  return (NULL);
}

void *consume(void *arg) {
  int i;
  for (i = 0; i < nitems; i++) {
    sem_wait(&shared.nstored);
    sem_wait(&shared.mutex);
    if (shared.buffer[i % BUFF_SIZE] != i) {
      printf("buffer[%d] %d\n", i, shared.buffer[i % BUFF_SIZE]);
    } else {
      printf("Consumer: %d\n", shared.buffer[i % BUFF_SIZE]);
    }
    sem_post(&shared.mutex);
    sem_post(&shared.nempty);
  }
  return (NULL);
}
