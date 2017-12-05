// 编制一段程序，使用系统调用fork()创建两个子程序，再用系统调用signal()让父进程捕捉键盘上来的中断信号(即按Ctrl
// C键)，当捕捉到中断信号后，父进程调用kill()向两个子进程发出信号，子进程捕捉到信号后，分别输出下面信息后终止：
// child process 1 is killed by parent!
// child process 2 is killed by parent!
// 父进程等待两个子进程终止后，输出以下信息后终止：
// parent process is killed!

#include <signal.h>  // for signal()
#include <stdio.h>   // for puts()
#include <stdlib.h>  // for exit()
#include <unistd.h>  // for fork()

int pid_1, pid_2;

void process_signal(int sign_num) {
  // printf("%d %d \n", pid_1, pid_2);
  if (pid_1 > 0 && pid_2 > 0) {
    // int kill(pid_t pid, int sig);
    kill(pid_1, SIGINT);
    kill(pid_2, SIGINT);
    // pid_t wait(int *wstatus);
    while ((wait(NULL))!= -1)
      ;
    puts("parent process is killed!\n");
    exit(0);
  } else if (pid_1 == 0) {
    puts("child process 1 is killed by parent!\n");
    exit(0);
  } else if (pid_2 == 0) {
    puts("child process 2 is killed by parent!\n");
    exit(0);
  }
}

int main() {
  signal(SIGINT, process_signal);
  if ((pid_1 = fork())) {
    pid_2 = fork();
  }
  while (1)
    ;
}