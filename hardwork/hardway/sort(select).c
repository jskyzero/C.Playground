#include <stdio.h>

void bubbleSort(double list[], int size) {
  double temp;
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - 1; j++) {
      if (list[j] > list[j + 1]) {
        temp = list[j];
        list[j] = list[j + 1];
        list[j + 1] = temp;
      }
    }
  }
}
void selectionSort(double list[], int arraySize) {
  double temp;
  for (int i = 0; i < arraySize - 1; i++) {
    for (int j = 0; j < arraySize - 1; j++) {
      if (list[j] > list[j + 1]) {
        temp = list[j];
        list[j] = list[j + 1];
        list[j + 1] = temp;
      }
    }
  }
}
int main() {
  double a[10] = {1, 3, 4, 5, 6, 2, 7, 8, 9, 10};
  selectionSort(a, 10);
  for (int i = 0; i < 10; i++) printf("%lf ", a[i]);
  return 0;
}
