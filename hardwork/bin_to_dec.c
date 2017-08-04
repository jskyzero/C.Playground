#include <stdio.h> // for printf()
#include <string.h> // for strlen()

int parseBinary(const char* const binaryString) {
  int i = 0;

  int ans = 0;
  while (*(binaryString + i) != '\0') {
    ans *= 2;
    ans += ((*(binaryString + i)) - 48);
    i++;
  }
  return ans;
}

int main() {
  char a[] = "111";
  printf("%d", parseBinary(a));
  return 0;
}
