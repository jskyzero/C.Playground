#include <stdio.h>
int a[500005];
int n, m, z, x, y, t;

void dodo(int n, int m) {
  for (int i = 0; i < n; i++) a[i] = i + 1;
  while (m--) {
    scanf("%d %d %d", &z, &x, &y);
  }
  int index = a[0];
  for (int i = 0; i < n; i++) {
    printf("%d ", index);
    index = a[index];
  }
  putchar('\n');
}

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &m);
    dodo(n, m);
  }
  return 0;
}
