#include <stdio.h> // for scanf() printf()

long long f(long long n) {
  if (n == 0)
    return 1;
  else if (n == 1)
    return 1;
  else if (n == 2)
    return 2;
  else
    return (f(n - 1) + f(n - 2));
}

int main() {
  long long n;
  scanf("%lld", &n);
  if (n > 20) n = n % 21;
  if (0 == n) n = 1;
  printf("%lld\n", f(n));
  return 0;
}
