#include <stdio.h>
#include <stdarg.h>
void func(int, ...);
int main() {
  func(2, 3, 5, 7, 11, 13);
  return 0;
}
void func(int n, ...) {
  int number, i = 0;
  va_list start;
  va_start(start, n);
  while (i != 3) {
    number = va_arg(start, int);
    i++;
  }
  printf("%d", number);
}
