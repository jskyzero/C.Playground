/*

I don't know what is use for... orz


*/
#include <stdio.h>

long int a[500005];

int main() {
  int t = 0;
  int z = 0;
  long int x = 0;
  long int y = 0;

  long int x0 = 0;
  long int y0 = 0;

  long int n = 0;
  long int m = 0;
  long int _x = 0;
  scanf("%d", &t);
  for (int _t = 0; _t < t; _t++) {
    scanf("%ld %ld", &n, &m);
    for (int _n = 1; _n <= n; _n++) a[_n] = _n;
    for (int _m = 0; _m < m; _m++) {
      scanf("%d %ld %ld", &z, &x0, &y0);
      for (int i = 1; i <= n; i++) {
        if (x0 == a[i]) x = i;
        if (y0 == a[i]) y = i;
      }
      if (x < y) {
        for (int i = x; i <= y - 2; i++) {
          a[i] = a[i + 1];
        }
        if (1 == z) {
          a[y - 1] = x0;
          a[y] = a[y];
        }
        if (2 == z) {
          a[y - 1] = a[y];
          a[y] = x0;
        }
      } else {
        for (int i = x; i >= y + 2; i--) {
          a[i] = a[i - 1];
        }
        if (1 == z) {
          a[y + 1] = a[y];
          a[y] = x0;
        }
        if (2 == z) {
          a[y + 1] = x0;
          a[y] = a[y];
        }
      }
    }
    for (int _n = 1; _n <= n; _n++) printf("%ld ", a[_n]);
    printf("\n");
  }
  return 0;
}
