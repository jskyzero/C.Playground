#include <stdio.h>

int main() {
  unsigned int i = 23;
  signed char c = -23;
  if (i > c)
    printf("Yes\n");
  else if (i < c) {
    printf("%d", c - i);
    printf("No\n");
  }
}
