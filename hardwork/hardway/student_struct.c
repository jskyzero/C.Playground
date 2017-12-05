#include <stdio.h>

struct student {
  int n;
  int math;
  int english;
  int C;
  int total;
} a[1005];

int main() {
  int N, i;
  scanf("%d", &N);
  for (i = 1; i <= N; i++) {
    scanf("%d %d %d %d", &a[i].n, &a[i].math, &a[i].english, &a[i].C);
    a[i].total = a[i].n + a[i].math + a[i].english + a[i].C;
  }

  return 0;
}
