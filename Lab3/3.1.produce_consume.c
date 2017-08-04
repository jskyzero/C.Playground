/*
 * 生产者消费者问题
 * 读入测试数据文件，按照要求运行进程。
 * jskyzero 2017(R)
 */

#include <stdio.h>      // for fopen(), perror()
#include <stdlib.h>     // for exit(), atoi(), malloc(), free()
#include <string.h>     // for strtok()
#include <unistd.h>     // for sleep()
#include <pthread.h>    // for pthread_create(), pthread_exit()
#include <semaphore.h>  // for sem_t, sem_wait(), sem_post()

// buffer size
#define BUFFER_SIZE 5
// max 4 num, each max 10 char, so we let buffer be 50
#define LINE_BUFFER_SIZE 50
// this file is copy from powerpoint
#define FILE_NAME "3.1.testfile"
// for strtok()
#define KEY_STR " "
// for product_id
#define HAVA_PRODUCT_ID_TYPE 'P'
// if you need DEBUG, then uncomment it
// #define DEBUG_TAG 1

// buffer item type
typedef int buffer_data_type;
// test data store type
typedef struct test_data {
  int index;  // 正整数，表示线程序号。
  char type;  // 相应线程角色，P表示生产者，C表示消费者。
  int begin_time;  // 正数，表示存放或取出操作的开始时间
  int duration;    // 正数，表示操作的持续时间。
  buffer_data_type product_id;  // 正数（仅生产者有），表示生产的产品号。
} test_data_type;

int buffer_index;
buffer_data_type buffer[BUFFER_SIZE];
sem_t empty, full, mutex;

void read_file_work();
void line_buffer_to_test_data(char *, test_data_type *);
void print_test_data(test_data_type *);
void work_with_test_data(test_data_type *);
void *produce(void *data);
void *consume(void *data);
int insert_item(buffer_data_type);
int remove_item(buffer_data_type *);

int main() {
  // empty 与full 将采用标准计数信号量，而mutex 将采用二进制信号量。
  sem_init(&mutex, 0, 1);            // empty (以记录有多少空位)
  sem_init(&empty, 0, BUFFER_SIZE);  // full (以记录有多少满位)
  sem_init(&full, 0, 0);             // 保护对缓冲插入与删除的操作
  // Main Part
  read_file_work();
  // creat and then destory
  sem_destroy(&mutex);
  sem_destroy(&empty);
  sem_destroy(&full);
  // wait wait for all pthreads to complete
  pthread_exit(0);
}

int insert_item(buffer_data_type item) {
  if (buffer_index < BUFFER_SIZE) {
    buffer[buffer_index] = item;
    buffer_index++;
    return 0;
  } else {
    return -1;
  }
}

int remove_item(buffer_data_type *item) {
  if (buffer_index > 0) {
    *item = buffer[--buffer_index];
    return 0;
  } else {
    return -1;
  }
}

void *produce(void *arg) {
  test_data_type *data = (test_data_type *)arg;
  sleep(data->begin_time);
  sem_wait(&empty);
  sem_wait(&mutex);
  printf("ProduceID:%10d ", data->index);
  if (insert_item(data->product_id)) {
    perror("INSERT ERROR\n");
  } else {
    printf("InsertData:%10d\n", data->product_id);
  }
  free(data);
  sleep(data->duration);
  sem_post(&mutex);
  sem_post(&full);
  return (NULL);
}

void *consume(void *arg) {
  test_data_type *data = (test_data_type *)arg;
  sleep(data->begin_time);
  sem_wait(&full);
  sem_wait(&mutex);
  buffer_data_type buffer_item;
  printf("ConsumeID:%10d ", data->index);
  if (remove_item(&buffer_item)) {
    perror("REMOVE ERROR\n");
  } else {
    printf("RemoveData:%10d\n", buffer_item);
  }
  free(data);
  sleep(data->duration);
  sem_post(&mutex);
  sem_post(&empty);
  return (NULL);
}

void work_with_test_data(test_data_type *data) {
  pthread_t thread;
  if (data->type == HAVA_PRODUCT_ID_TYPE) {
    pthread_create(&thread, NULL, produce, (void *)data);
  } else {
    pthread_create(&thread, NULL, consume, (void *)data);
  }
}

void print_test_data(test_data_type *data) {
  printf("|index:%10d|type:%c|begin_time:%10d|duration:%10d|product_id%10d|\n",
         data->index, data->type, data->begin_time, data->duration,
         data->product_id);
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
  if (data->type == HAVA_PRODUCT_ID_TYPE) {
    pch = strtok(NULL, KEY_STR);
    data->product_id = atoi(pch);
  } else {
    data->product_id = 0;
  }
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