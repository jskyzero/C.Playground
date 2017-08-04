#include <stdio.h> // for printf()
#include <ctype.h>

int countLetters(const char* const str) {
  int i = 0;
  int n = 0;
  while (*(str + i) != '\0') {
    if ((*(str + i) >= 'A' && *(str + i) <= 'Z') ||
        ((*(str + i) >= 'a') && *(str + i) <= 'z'))
      n++;
    i++;
  }
  return n;
}

int* count(const char* const s) {
  static int a[15];
  long long i = 0;
  while (*(s + i) != '\0') {
    if (*(s + i) == '0') a[0]++;
    if (*(s + i) == '1') a[1]++;
    if (*(s + i) == '2') a[2]++;
    if (*(s + i) == '3') a[3]++;
    if (*(s + i) == '4') a[4]++;
    if (*(s + i) == '5') a[5]++;
    if (*(s + i) == '6') a[6]++;
    if (*(s + i) == '7') a[7]++;
    if (*(s + i) == '8') a[8]++;
    if (*(s + i) == '9') a[9]++;
    i++;
  }
  return a;
}

int main() {
  char list[] = {'a', 'b', 'a', 'c', '\0', 'a'};
  int i = countLetters(list);
  char a[] = {'1', '2', '2', '\0', '3', 'A', 'B', '3'};

  int* counts = count(a);
  for (int i = 0; i < 2 * 5; i++) printf("%d ", counts[i]);
  return 0;
}
