#include <stdio.h>

int GCD(int a, int b) { return (0 == b) ? a : GCD(b, a % b); }
int main() { printf("%d", GCD(5, 25)); }
