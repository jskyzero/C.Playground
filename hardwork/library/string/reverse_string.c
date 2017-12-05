#include <stdio.h> // for printf(), puts() 
#include <string.h> // for strlen()

// 操作字符串函数实践
char* reverseString(char* s) {
  int n = strlen(s); // string length
  int i = 0; // for loop

  char p[n]; // store reversed string

  for (i = n - 1; i >= 0; i--) {
    p[n - 1 - i] = s[i];
  }
  puts(p);
  
  for (i = n - 1; i >= 0; i--) {
    s[i] = p[i];
  }

  puts(s);
  return s;
}

int main() {
  char s[] = "hello";
  char* p = reverseString(s);
  printf("%s", p);
}
