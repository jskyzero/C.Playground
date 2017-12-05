#include <stdio.h>
int main(int argc, char** argv) {
  char s[] = "myworld";
  int i = 3;
  printf("%10.*s %%", i, s);
}