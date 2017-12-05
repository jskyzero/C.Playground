#include <stdio.h> // for scanf() printf()


int check_marks_state(float n) {
  if (n < 60)
    return 0;
  else if (n < 70)
    return 1;
  else if (n < 80)
    return 2;
  else if (n < 90)
    return 3;
  else if (n > 90)
    return 4;
}
int main() {
  float n; // store the num
  while (scanf("%f", &n) != EOF) {
    printf("%d\n", check_marks_state(n));
  }
  return 0;
}
