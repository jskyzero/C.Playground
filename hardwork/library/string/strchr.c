#include <stdio.h>
#include <string.h>

int main() {

  const char str[] = "Hello World!";
  char const * const index = strchr(str, 'e');
  fprintf(stdout, "%c", *index);

  return 0;
}