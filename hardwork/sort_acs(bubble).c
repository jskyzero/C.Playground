#include <stdio.h> // for scanf() printf()

int *sortAsc(int *n, int _n) {
  int temp;
  for (int i = 0; i < _n - 1; i++) {
    for (int j = 0; j < _n - 1; j++) {
      if (n[j] > n[j + 1]) {
        temp = n[j + 1];
        n[j + 1] = n[j];
        n[j] = temp;
      }
    }
  }
  return n;
}

int main() {
  int arr[5];
  int j;
  for (j = 0; j < 5; j++) {
    scanf("%d", &arr[j]);
  }
  int *p = sortAsc(arr, 5);
  int i;
  for (i = 0; i < 5; i++) printf("%d ", *(p + i));
  printf("\n");
  return 0;
}
