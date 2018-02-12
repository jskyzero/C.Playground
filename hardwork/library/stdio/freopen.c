#include <stdio.h>

int main() {
  freopen("printf.c", "r", stdin);
  freopen("1", "w", stdout);

  char ch;
  while ((ch = getchar()) != EOF) {
    putchar(ch);
  }
  
  return 0;
}