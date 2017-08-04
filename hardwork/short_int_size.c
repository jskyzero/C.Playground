#include <stdio.h>
int main() {
  int x = 1;
  short int i = 2;
  float f = 3;
  if (sizeof((x == 2) ? f : i) == sizeof(float)) {
    printf("float\n");
    printf("%ld %ld", sizeof((x == 2) ? f : i), sizeof(float));
  } else if (sizeof((x == 2) ? f : i) == sizeof(short int)) {
    printf("short int\n");
    printf("%ld %ld", sizeof((x == 2) ? f : i), sizeof(float));
  }
}
