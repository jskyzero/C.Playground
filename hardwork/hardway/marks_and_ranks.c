#include <stdio.h>
float a[105];
int b[6];
int main() {
  int n;
  scanf("%d", &n);
  double temp = 0;
  int min = 0;
  int max = 0;
  for (int i = 0; i < n; i++) {
    scanf("%f", &a[i]);
    temp += a[i];
    if (a[i] > a[max]) max = i;
    if (a[i] < a[min]) min = i;
    if ((a[i] >= 0) && (a[i] < 60)) b[1]++;
    if ((a[i] >= 60) && (a[i] < 75)) b[2]++;
    if ((a[i] >= 75) && (a[i] < 85)) b[3]++;
    if ((a[i] >= 85) && (a[i] < 95)) b[4]++;
    if ((a[i] >= 95) && (a[i] <= 100)) b[5]++;
  }
  temp = (temp - a[max] - a[min]) / (n - 2);
  printf("%.2lf\n", temp);
  for (int i = 1; i <= 5; i++) {
    printf("%d\n", b[i]);
  }
  return 0;
}
