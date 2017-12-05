#include <stdio.h>    //for printf()
#include <stdarg.h>   //for va_start(), va_end(), va_arg() 

void print_many(int argc, ...) {
  int num;
  va_list argv;
  va_start(argv, argc);
  for (int i = 0; i < argc; i++) {
    num = va_arg(argv, int);
    printf("%d is %d \n", i, num);
  }
  va_end(argv);
}

int main() {
  print_many(3, 1, 2, 3);
  return 0;
}