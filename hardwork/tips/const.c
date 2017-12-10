#include <stdio.h>

/*
 * So today, let's talk about const in C
 *
 * You can find more reference on stackoverflow
 * https://stackoverflow.com/questions/1143262/what-is-the-difference-between-const-int-const-int-const-and-int-const
 */

int main() {
  int num0 = 0;
  /* this is same to const int */
  int const num2 = 2;
  const int num1 = 1;

  /* this is a const pointer(int *); */
  int* const p1 = &num0;
  /* this is a const int */
  int const* p2 = &num0;
  /*
   * this is a const int
   * const int * == int const *
   * const int * const == int const * const
   *
   */
  const int* p3 = &num0;

  *p1 = -1;

  fprintf(stdout, "num0 = %d\n", num0);

  return 0;
}