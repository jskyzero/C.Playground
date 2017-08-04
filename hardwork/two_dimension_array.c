#include <stdio.h>
int a[3][2] = {1, 2, 3, 4, 5, 6};

int main() {
  int* p = a[0];
  for (p; p < a[0] + 6; p++) {
    printf("%d\n", p[0]);
  }
}
