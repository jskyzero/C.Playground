#include <stdio.h>

int n[5][1005];
int num[1005];
float n5[1005];

int main() {
  int N, i, j, _n5, _num;
  scanf("%d", &N);
  for (i = 1; i <= N; i++) {
    scanf("%d %d %d %d", &n[0][i], &n[1][i], &n[2][i], &n[3][i]);
    n[4][i] = n[1][i] + n[2][i] + n[3][i];
    n5[i] = n[4][i] - n[0][i] / 1000000;
    num[i] = n[0][i];
  }
  for (i = 1; i <= N - 1; i++) {
    for (j = 1; j <= N - 1; j++) {
      if (n5[j] < n5[j + 1]) {
        _n5 = n5[j];
        n5[j] = n5[j + 1];
        n5[j + 1] = _n5;
        _num = num[j];
        num[j] = num[j + 1];
        num[j + 1] = _num;
      }
    }
  }
  for (i = 1; i <= 5; i++) {
    j = num[i];
    printf("%d %d %d %d %d\n", n[0][j], n[1][j], n[2][j], n[3][j], n[4][j]);
  }
  return 0;
}
