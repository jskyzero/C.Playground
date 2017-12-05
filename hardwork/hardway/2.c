#include <stdio.h>
int left[500005], right[500005];
int n, m, z, x, y, t;

void dodo(int n, int m) {
  for (int i = 0; i <= n; i++) {
    left[i] = i - 1;
    right[i] = i + 1;
  }
  while (m--) {
    scanf("%d %d %d", &z, &x, &y);
    right[left[x]] = right[x];
    left[right[x]] = left[x];
    if (1 == z) {
      right[left[y]] = x;
      left[x] = left[y];
      left[y] = x;
      right[x] = y;
    } else {
      left[right[y]] = x;
      right[x] = right[y];
      right[y] = x;
      left[x] = y;
    }
  }
  int index = 0;
  for (int i = 0; i < n; i++) {
    index = right[index];
    printf("%d ", index);
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
