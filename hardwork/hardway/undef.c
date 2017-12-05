#include <stdio.h>
int foo(int, int);
#define foo(x, y) x / y + x
int main() {
  int i = -6, j = 3;
  printf("%d ", foo(i + j, 3));
#undef foo
  printf("%d\n", foo(i + j, 3));
}
int foo(int x, int y) { return x / y + x; }
