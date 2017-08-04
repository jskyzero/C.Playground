#include <stdio.h> // for scanf() printf()

void swap(int *i, int *j) {
  int temp;
  temp = *i;
  *i = *j;
  *j = temp;
}

int main() {
  int a, b;

  scanf("%d%d", &a, &b);
  swap(&a, &b);  // ����a��b������ֵ
  printf("%d %d\n", a, b);

  return 0;
}
