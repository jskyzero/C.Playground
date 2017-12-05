#include <stdio.h>

int main() {
  int a[5] = {10, 20, 30, 40, 50};
  int* p = a;
  printf("%p\n", a);
  printf("%p\n", p);
  printf("%p\n", &p);
  printf("%p\n", &a[0]);
  printf("%p\n", &a[1]);
  printf("%d\n", a[4] - a[3]);
  printf("%d\n", a[2]);
  printf("%d\n", a[-1]);
  printf("%d\n", *(p + 7));
  if ((a[1] = 2) != 2) printf("NO");
}
