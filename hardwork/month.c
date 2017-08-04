#include <stdio.h>
int a[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main() {
  int Y, M, D;
  scanf("%d %d %d", &Y, &M, &D);
  if (0 == Y % 400 || (0 == Y % 4 && 0 != Y % 100)) a[1]++;
  for (int i = 0; i < M - 1; i++) {
    D += a[i];
  }
  printf("%d\n", D);
  return 0;
}
