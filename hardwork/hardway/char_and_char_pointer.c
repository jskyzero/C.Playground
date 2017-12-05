#include <stdio.h>

int main() {
  char* p1[4][4] = {"abc", "def", "efg", "hij"};
  printf("%s\n", p1[0]);
  printf("%c\n", *(p1[1] + 1));

  char*(p2[4]) = {"abc", "def", "efg", "hij"};
  printf("%s\n", p2[0]);
  printf("%c\n", *(p2[1] + 1));

  int a[4] = {1, 2, 3, 4};
  char(*p3)[4] = a;
  printf("%d\n", *a++);
  printf("%d\n", *a);
}
