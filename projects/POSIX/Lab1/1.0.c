#include <stdio.h>
#include <unistd.h>

int main() {
  int pid_1 = fork();
  printf("**1**\n");

  int pid_2 = fork();
  printf("**2**\n");

  if (pid_1 == 0) {
    int pid_3 = fork();
    printf("**3**\n");
  } else {
    printf("**4**\n");
  }
  return 0;
}