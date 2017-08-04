#include <stdio.h>
#include <unistd.h>

int main() {
  int pid_1 = fork();
  if (pid_1 != 0) {
    int pid_2 = fork();
    if (pid_2 != 0) {
      puts("a");
    } else {
      puts("c");  // second sub process print "c"
    }
  } else {
    puts("b");  // first sub process print "b"
  }
}