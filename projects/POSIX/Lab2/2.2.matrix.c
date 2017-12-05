#include <assert.h>   // for assert()
#include <pthread.h>  // for pthread_*
#include <stdio.h>    // for printf(),fopen(), fgets()
#include <stdlib.h>   // for atoi(), malloc(), free()
#include <string.h>   // for memset()

#define MATRIX_MAX_SIZE 1000
#define BUFFER_SIZE (4 * MATRIX_MAX_SIZE)
#define DATA_FILE_NAME "2.2.data.csv"
#define KEY_STR ","

// don't need test now
// #define READ_TEST 1
#define ANS_TEST 1

// argument struct type
struct ARGU {
  int row;
  int column;
  int ans;
};

typedef struct ARGU ARGU_TYPE;

// global data
int A[MATRIX_MAX_SIZE][MATRIX_MAX_SIZE], B[MATRIX_MAX_SIZE][MATRIX_MAX_SIZE];
int A_row, A_B, B_column;

void read_file();
void *calcute(void *);

int main() {
  read_file();
  void *return_value;  // actually no use
  int ans[MATRIX_MAX_SIZE][MATRIX_MAX_SIZE];
  ARGU_TYPE argu;

  for (argu.row = 0; argu.row < A_row; argu.row++) {
    for (argu.column = 0; argu.column < B_column; argu.column++) {
      // produce every thread
      pthread_t thread;
      pthread_attr_t attr;
      pthread_attr_init(&attr);
      assert(0 == pthread_create(&thread, &attr, calcute, &argu));
      pthread_join(thread, &return_value);
      ans[argu.row][argu.column] = argu.ans;
    }
  }

#ifdef ANS_TEST
  // print ans in csv format
  printf("%d,%d\n", A_row, B_column);
  for (argu.row = 0; argu.row < A_row; argu.row++) {
    for (argu.column = 0; argu.column < B_column; argu.column++) {
      printf("%d", ans[argu.row][argu.column]);
      if (argu.column < B_column - 1) printf(",");
    }
    printf("\n");
  }
#endif

  return 0;
}

void *calcute(void *argu) {
  // just calcute each value
  ARGU_TYPE *data_p = (ARGU_TYPE *)argu;
  data_p->ans = 0;
  for (int i = 0; i < A_B; i++) {
    data_p->ans += A[data_p->row][i] * B[i][data_p->column];
  }
  // test to use return value
  return (void *)1;
}

void read_file() {
  // read file part is a little long for the csv file format
  // you can use define to let it print read result to check it
  char *line, *buffer = malloc(sizeof(char) * BUFFER_SIZE);
  if (buffer == NULL) {
    perror("malloc faile\n");
    exit(-1);
  }

  FILE *data = fopen(DATA_FILE_NAME, "r");
  if (data == NULL) {
    perror("File open failed\n");
    exit(-1);
  }

  // read A_row, A_B, B_column
  if ((line = fgets(buffer, BUFFER_SIZE, data)) != NULL) {
    char *pch = strtok(buffer, KEY_STR);
    A_row = atoi(pch);
    pch = strtok(NULL, KEY_STR);
    A_B = atoi(pch);
    pch = strtok(NULL, KEY_STR);
    B_column = atoi(pch);
#ifdef READ_TEST
    printf("%d,%d,%d\n", A_row, A_B, B_column);
#endif
  }

  // read matrix A
  for (int i = 0;
       ((i < A_row) && (line = fgets(buffer, BUFFER_SIZE, data)) != NULL);
       i++) {
    char *pch = strtok(buffer, KEY_STR);
    for (int j = 0; pch != NULL; j++) {
      A[i][j] = atoi(pch);
#ifdef READ_TEST
      printf("%d", A[i][j]);
      if (j < A_B - 1) printf(",");
#endif
      pch = strtok(NULL, KEY_STR);
    }
#ifdef READ_TEST
    printf("\n");
#endif
  }
  // read matrix B
  for (int i = 0;
       ((i < A_B) && (line = fgets(buffer, BUFFER_SIZE, data)) != NULL); i++) {
    char *pch = strtok(buffer, KEY_STR);
    for (int j = 0; pch != NULL; j++) {
      B[i][j] = atoi(pch);
#ifdef READ_TEST
      printf("%d", B[i][j]);
      if (j < B_column - 1) printf(",");
#endif
      pch = strtok(NULL, KEY_STR);
    }
#ifdef READ_TEST
    printf("\n");
#endif
  }
  free(buffer);
}