#include <stdio.h>
#include <string.h>

char *sortString(const char *const s) {
  int i, j, a;
  int len = strlen(s);
  char *str = new char[len];
  strcpy(str, s);
  for (i = 0; i < len; i++)
    for (j = 0; j < len; j++)
      if (str[i] < str[j]) {
        a = str[i];
        str[i] = str[j];
        str[j] = a;
      }
  return str;
}

void sortString(const char *const s, char *s1) { strcpy(s1, sortString(s)); }

int main() {
  char a[] = "123456";
  char *p = sortString(a);
  for (int i = 0; p[i] != '\0'; i++) {
    printf("%c", p[i]);
  }
  putchar('\n');
  char *p2 = a;
  sortString(a, p2);
  for (int i = 0; p[i] != '\0'; i++) {
    printf("%c", p[i]);
  }
  putchar('\n');
  return 0;
}
