#include <stdio.h>

#define foo(m, n) (m)* (n)

int main() {
  printf("in main\n");
  printf("%d", foo(1, 2));
}
