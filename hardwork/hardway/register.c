#include <stdio.h>
void m();
int main() {
  register int x = 5;
  m();
  printf("x is %d", x);
}
void m() { x++; }
