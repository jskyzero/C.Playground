#include <stdio.h> // for printf()
#include <string.h>

char a[10005];
char* p;
char* prefix(const char* const s1, const char* const s2) {
  for (int i = 0; i < 10005; i++) {
    a[i] = 0;
  }
  int n1 = strlen(s1);
  int n2 = strlen(s2);
  int n3 = n2 < n1 ? n2 : n1;
  int n4 = 0;
  for (int i = 0; i < n3; i++) {
    n4 = i;
    if (s1[i] == s2[i])
      a[i] = s1[i];
    else
      break;
  }
  if (0 == n4)
    return a;
  else
    return a;
}
int main() {
  char s1[] = "distance";
  char s2[] = "tlike";
  char* p = prefix(s1, s2);
  for (int i = 0; p[i] != '\0'; i++) {
    printf("%c", p[i]);
  }
  putchar('\n');
  return 0;
}
