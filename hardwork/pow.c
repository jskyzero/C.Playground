#include <stdio.h> // for scanf() printf()
#include <math.h> // for pow()

int k, N, n;
double ans;
int a[32];

void f(int _N, int _n) {
  if (_n < 0 || _N < 1) return;

  if (_N >= a[_n]) {
    f(_N - a[_n], _n);
    ans += pow(k, _n);
  } else
    f(_N, _n - 1);
}

int main() {
  scanf("%d %d", &k, &N);
  a[0] = 1;
  for (int i = 1; i < 32; i++) {
    a[i] = 2 * a[i - 1];
    if (a[i] > N) {
      n = i - 1;
      break;
    }
  }
  f(N, n);
  printf("%.0lf\n", ans);
}
