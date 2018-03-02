# 实验1 进程和进程通信
> DDL: 2017/05/08 24:00

## Helloworld
参考教材写出helloworld，大致的流程已经清楚，不过还是踩了点坑，比如如下程序跑的话就会多输出一个'h'字符。
```C
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

  // Create pthread
  int result_code = pthread_create(&thread, &attr, pthread_work, thread_argument);
  
  printf("In Main All threads completed\n");
  // block call 
  // pthread_join(thread, NULL);
  // printf("Exit\n");
  
  return 0;
}
```
想想可能是因scope是system的缘故，于是又发现setscope失败最后才发现linux / Mac OS X 仅允许设置PTHREAD SCOPE SYSTEM，那就无解了。只能说这样初始化了线程却不使用是不可取的行为。
```C
  // Update: linux / Mac OS X 仅允许设置PTHREAD SCOPE SYSTEM。
  assert(pthread_attr_setscope(&attr, PTHREAD_SCOPE_PROCESS) == 0 );
```

## 用线程生成Fibonacci数列
> 用pthread线程库，按照第四章习题4.11的要求生成并输出Fibonacci数列

具体代码请参考2.1.fibonacci.c，思路大概就是面向过程，逐步求精，把计算那一提出到线程中完成，另外使python测试了 4byte signed int 能保存的最大，同时也可以运行2.1.cal_size.py来参考结果是否一致。

## 多线程矩阵乘法
> 给定两个矩阵A和B，其中A是具有M行、K列的矩阵， B为K行、N列的矩阵， A和B的矩阵积为矩阵C， C为M行、N列。矩阵C中第i行、第j列的元素Cij就是矩阵A第i行每个元素和矩阵B第j列每个元素乘积的和。

> 要求：每个Ci j的计算用一个独立的工作线程，因此它将会涉及生成M×N个工作线程。主线程(或称为父线程)将初始化矩阵A和B，并分配足够的内存给矩阵C，它将容纳矩阵A和B的积。这些矩阵将声明为全局数据，以使每个工作线程都能访问矩阵A、B和C。

老师之前说过会给文件读写，也没有发现文件在哪里，无奈之下自己写了生成文件的代码，使用`bash 2.2.test.sh`一键生成、编译、测试、删除。

具体代码请参考2.2.matrix.c

## Reference

[POSIX thread (pthread) libraries](http://www.yolinux.com/TUTORIALS/LinuxTutorialPosixThreads.html)

[man pthread_attr_init](http://man7.org/linux/man-pages/man3/pthread_attr_init.3.html)

[man pthread_attr_setscope](http://man7.org/linux/man-pages/man3/pthread_attr_setscope.3.html)

[man pthread_create](http://man7.org/linux/man-pages/man3/pthread_create.3.html)

[How to return a value from thread in C](http://stackoverflow.com/questions/2251452/how-to-return-a-value-from-thread-in-c)

[Read CSV file to a 2D array on C](http://stackoverflow.com/questions/20013693/read-csv-file-to-a-2d-array-on-c)

[reference-cstdio-fgets](http://www.cplusplus.com/reference/cstdio/fgets/)

[Unix diff - how to ignore line endings when comparing files?](http://stackoverflow.com/questions/40974170/unix-diff-how-to-ignore-line-endings-when-comparing-files)

