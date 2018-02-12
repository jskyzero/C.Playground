#include <stdio.h>
#include <time.h>

/*
 既然决定了还是好好看下去吧w
 半途而废又算什么呢?
*/
typedef void(*void_func)(void);

void check_time(void_func func){
  clock_t begin_time = clock();
  func();
  clock_t end_time = clock();
  printf("use time %f", (float)(end_time - begin_time)/CLOCKS_PER_SEC); 
}

void select_problem() {
  int k = 1<<30;
  while(k--) {
    k = k;
  }
}

int main() {
  check_time(select_problem);
  return 0;  
}