#include <stdio.h>

int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    gcd(b, a % b);
}

int main() {
  struct ans {
    int left;
    int right;
    float x;
  } a[10000];

  int N;
  scanf("%d", &N);
  int k = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (gcd(i, j) == 1) {
        if (i < j) {
          a[k].left = i;
          a[k].right = j;
          a[k].x = (float)i / j;
          k++;
        }
      }
    }
  }
  int temp, num[10000] = {0};
  for (int i = 0; i < k; i++) num[i] = i;
  for (int i = 0; i < k - 1; i++) {
    for (int j = 0; j < k - 1; j++) {
      if (a[num[j]].x > a[num[j + 1]].x) {
        temp = num[j];
        num[j] = num[j + 1];
        num[j + 1] = temp;
      }
    }
  }

  printf("0/1\n");
  for (int i = 0; i < k; i++)
    printf("%d/%d\n", a[num[i]].left, a[num[i]].right);
  printf("1/1\n");
  return 0;
}
