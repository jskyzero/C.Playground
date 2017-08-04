#include <stdio.h>
#define SYSTEM 20
int main() {
  int a = 20;
#if SYSTEM == a
  printf("HELLO ");
#endif
#if SYSTEM == 20
  printf("WORLD\n");
#endif
}
