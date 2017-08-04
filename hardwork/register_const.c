#include <stdio.h>
int main() {
  register const int i = 10;
  i = 11;
  printf("%d\n", i);
}
