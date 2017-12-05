#include <stdio.h> // for printf()

int *doubleCapacity(int *p, int n) {
  static int a[10000];
  for (int i = 0; i < n; i++) {
    *(a + i) = *(p + i);
  }
  for (int i = 0; i < n; i++) {
    *(a + n + i) = 0;
  }
  return a;
}

int main() {
  int list[5] = {1, 2, 3, 4, 5};
  int *newlist = doubleCapacity(list, 5);
  for (int i = 0; i < 2 * 5; i++) printf("%d ", *(newlist + i));
}
