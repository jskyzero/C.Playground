#include <iostream>
#include <cstdio>
#include <cstring>

int a[128];
char* sortString(const char* const s) {
  int n = strlen(s);
  static char str[10005];

  for (int i = 0; i < 128; i++) {
    a[i] = 0;
  }

  for (int i = 0; i < n; i++) {
    a[*(s + i)]++;
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
void sortString(const char* const s, char* s1) {
  int n = strlen(s);
  for (int i = 0; i < 128; i++) {
    a[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    a[*(s + i)]++;
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
  char* str = "bca";
  char* s1 = sortString(str);
  std::cout << s1 << std::endl;

  char s2[100];
  sortString(str, s2);
  std::cout << s2 << std::endl;
}
