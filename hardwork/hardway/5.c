#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char a[505][30];

int strcmp2(const char *str1, const char *str2) {
  char ch1, ch2;
  while (*str1 == *str2 || abs(*str1 - *str2) == 32) {
    if (*str1 == '\0') return 0;
    str1++;
    str2++;
  }
  if (*str1 < 'Z')
    ch1 = *str1 + 32;
  else
    ch1 = *str1;
  if (*str2 < 'Z')
    ch2 = *str2 + 32;
  else
    ch2 = *str2;

  return ch1 - ch2;
}

void sort(int n) {
  char temp[30];
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - 1; j++) {
      if (strcmp2(a[j], a[j + 1]) > 0) {
        strcpy(temp, a[j]);
        strcpy(a[j], a[j + 1]);
        strcpy(a[j + 1], temp);
      }
    }
  }
}
int main() {
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%s", a[i]);
  }
  sort(N);
  for (int i = 0; i < N; i++) {
    if (abs(strcmp(a[i], a[i + 1])) == 32 || strcmp(a[i], a[i + 1]) == 0) {
      continue;
    } else
      printf("%s\n", a[i]);
  }
}
