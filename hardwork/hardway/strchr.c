#include <stdio.h> // for printf()
#include <string.h> // for strchr()
#include <math.h> // for pow()
char a[10] = "abcdefghi";

int main() {
  char* p = strchr(a, 'c');
  printf("%s", p);

  printf("%lf", pow(128, 8) / 60);
}
