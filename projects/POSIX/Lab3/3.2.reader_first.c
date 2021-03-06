/*
 * jskyzero 2017(R)
 */

#include <pthread.h>    // for pthread_create(), pthread_exit()
#include <semaphore.h>  // for sem_t, sem_wait(), sem_post()
#include <stdio.h>      // for fopen(), perror()
#include <stdlib.h>     // for exit(), atoi(), malloc(), free()
#include <string.h>     // for strtok()
#include <unistd.h>     // for sleep()

// max 3 num, each max 10 char, so we let buffer be 40
#define LINE_BUFFER_SIZE 40
// this file is copy from powerpoint
#define FILE_NAME "3.2.testfile"
// for strtok()
#define KEY_STR " "
// if you need DEBUG, then uncomment it
// #define DEBUG_TAG 1

// test data store type
typedef struct test_data {
  int index;  // 正整数，表示线程序号。
  char type;  // 相应线程角色，P表示生产者，C表示消费者。
  int begin_time;  // 正数，表示存放或取出操作的开始时间
  int duration;    // 正数，表示操作的持续时间。
} test_data_type;

int readcount;
sem_t wrt, mutex;

void read_file_work();
void line_buffer_to_test_data(char *, test_data_type *);
void print_test_data(test_data_type *);
void work_with_test_data(test_data_type *);
void *reader(void *data);
void *writer(void *data);
int read_item();
int write_item();

int main() {
  sem_init(&mutex, 0, 1);  
  sem_init(&wrt, 0, 1);    
  // Main Part
  read_file_work();
  // creat and then destory
  sem_destroy(&mutex);
  sem_destroy(&wrt);
  // wait wait for all pthreads to complete
  pthread_exit(0);
}

int read_item() {
  printf("-READING-");
  return 0;
}

int write_item() {
  printf("-WRITING-");
  return 0;
}

void *reader(void *arg) {
  test_data_type *data = (test_data_type *)arg;
  sleep(data->begin_time);
  sem_wait(&mutex);
  readcount++;
  if (readcount == 1) sem_wait(&wrt);
  sem_post(&mutex);

  printf(" readID:%10d ", data->index);
  if (read_item()) {
    perror(" READ ERROR\n");
  } else {
    printf(" READ SUCCESS\n");
  }
  sleep(data->duration);

  sem_wait(&mutex);
  readcount--;
  if (readcount == 0) sem_post(&wrt);
  sem_post(&mutex);
  free(data);
  return (NULL);
}

void *writer(void *arg) {
  test_data_type *data = (test_data_type *)arg;
  sleep(data->begin_time);
  sem_wait(&wrt);
  printf("writeID:%10d ", data->index);
  if (write_item()) {
    perror("WRITE ERROR\n");
  } else {
    printf("WRITE SUCCESS\n");
  }
  sleep(data->duration);
  sem_post(&wrt);
  free(data);
  return (NULL);
}

void work_with_test_data(test_data_type *data) {
  pthread_t thread;
  if (data->type == 'R') {
    pthread_create(&thread, NULL, reader, (void *)data);
  } else {
    pthread_create(&thread, NULL, writer, (void *)data);
  }
}

void print_test_data(test_data_type *data) {
  printf("|index:%10d|type:%c|begin_time:%10d|duration:%10d|\n", data->index,
         data->type, data->begin_time, data->duration);
}

void line_buffer_to_test_data(char *line, test_data_type *data) {
  char *pch = strtok(line, KEY_STR);
  data->index = atoi(pch);
  pch = strtok(NULL, KEY_STR);
  data->type = pch[0];
  pch = strtok(NULL, KEY_STR);
  data->begin_time = atoi(pch);
  pch = strtok(NULL, KEY_STR);
  data->duration = atoi(pch);
}

void read_file_work() {
  // malloc buffer
  char *line_buffer = (char *)malloc(sizeof(char) * LINE_BUFFER_SIZE);
  if (line_buffer == NULL) {
    perror("malloc faile\n");
    exit(-1);
  }
  // open file
  FILE *test_file = fopen(FILE_NAME, "r");
  if (test_file == NULL) {
    perror("File open failed\n");
    exit(-1);
  }
  // readfile and process
  while (fgets(line_buffer, LINE_BUFFER_SIZE, test_file) != NULL) {
    test_data_type *line_test_data =
        (test_data_type *)malloc(sizeof(test_data_type));
    line_buffer_to_test_data(line_buffer, line_test_data);
#ifdef DEBUG_TAG
    print_test_data(line_test_data);
#endif
    work_with_test_data(line_test_data);
  }
  // free malloc data
  free(line_buffer);
  // close file
  fclose(test_file);
}