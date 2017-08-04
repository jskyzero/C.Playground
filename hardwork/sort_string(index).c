#include <stdio.h> // for scanf()
#include <string.h>  // for printf()

int a[128];
char *sortString(const char *const s) {
  int n = strlen(s);
  static char str[100005];

  for (int i = 0; i < 128; i++) {
    a[i] = 0;
  }

  for (int i = 0; i < n; i++) {
    a[s[i]]++;
  }
  int j = 0;
  for (int i = 0; i < 128; i++) {
    while (a[i] != 0) {
      str[j] = i;
      a[i]--;
      j++;
    }
  }
  return str;
}
void sortString2(const char *const s, char *s1) {
  int n = strlen(s);
  for (int i = 0; i < 128; i++) {
    a[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    a[s[i]]++;
  }
  int j = 0;
  for (int i = 0; i < 128; i++) {
    while (a[i] != 0) {
      s1[j] = i;
      a[i]--;
      j++;
    }
  }
  return;
}

int main() {
  char a[] = "123456";
  char *p = sortString(a);
  for (int i = 0; p[i] != '\0'; i++) {
    printf("%c", p[i]);
  }
  putchar('\n');
  char *p2 = a;
  sortString2(a, p2);
  for (int i = 0; p[i] != '\0'; i++) {
    printf("%c", p[i]);
  }
  putchar('\n');
  return 0;
}
