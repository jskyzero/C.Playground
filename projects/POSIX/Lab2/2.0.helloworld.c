#include <stdio.h>    // for printf()
#include <pthread.h>  // for pthread_*, thread_*
#include <assert.h> // for assert()

// 
void* pthread_work(void* arguement) {
  // use type cast to get data from arguement
  char* print_str = (char*)arguement;
  // process data
  printf("%s\n", print_str);


  return NULL;
}

int main(int argc, char *argv[]) {
  pthread_t thread;
  pthread_attr_t attr;
  char thread_argument[] = "Hello World!";  
  pthread_attr_init(&attr);

  // Attention :
  // this will cause a abort in my macOS Sierra 10.12.02
  // I dont know why it can't set scope to process
  // Update: linux / Mac OS X 仅允许设置PTHREAD SCOPE SYSTEM。
  // assert(pthread_attr_setscope(&attr, PTHREAD_SCOPE_PROCESS) == 0 );

  // int s, i;
  // s = pthread_attr_getscope(&attr, &i);

  // printf("%sScope               = %s\n", "|",
  //         (i == PTHREAD_SCOPE_SYSTEM)  ? "PTHREAD_SCOPE_SYSTEM" :
  //         (i == PTHREAD_SCOPE_PROCESS) ? "PTHREAD_SCOPE_PROCESS" :
  //         "???");

  // Create pthread
  int result_code = pthread_create(&thread, &attr, pthread_work, thread_argument);
  
  // printf("result code = %d\n", result_code);

  printf("In Main All threads completed\n");
  // block call 
  // pthread_join(thread, NULL);
  // printf("Exit\n");
  
  return 0;
}
