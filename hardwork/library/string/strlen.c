#include <stdio.h>
#include <string.h>

int main() {

  int array[] = {1, 2, 3};
  // maybe will cause stackoverflow, but who cares
  printf("%lu", strlen((char const *)array));

  return 0;
}