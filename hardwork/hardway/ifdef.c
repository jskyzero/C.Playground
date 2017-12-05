#include <stdio.h>
#define Cprog
int main() {
  int a = 2;
#ifdef Cprog
  a = 1;
  printf("%d", Cprog);
}
