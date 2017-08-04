#include <stdio.h>  // for scanf() prinf()

int a[1005];
int main() {
  int N, n, i, j;
  // OK now I know memset and global vlaue is initial valued 0
  for (j = 1; j; j++) {
    for (i = 0; i <= 1000; i++) {
      a[i] = 0;
    }

    // Now I will use while loop
    scanf("%d", &N);
    if (0 == N)
      break;
    else
      for (i = 0; i < N; i++) {
        scanf("%d", &n);
        a[n]++;
      }

    // print ans part
    printf("Case %d:\n", j);
    for (i = 0; i <= 1000; i++) {
      if (0 == a[i])
        continue;
      else
        printf("%d %d\n", i, a[i]);
    }
  }
  return 0;
}
