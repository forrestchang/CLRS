/*
 * 2.2-2: Selection sort
 */

#include <stdio.h>

void selectionSort(int array[], int length);
void swapTwoNumbers(int *a, int *b);

void selectionSort(int array[], int length)
{
  int minimumNumberIndex;
  for (int i = 0; i < length; i++) {
    minimumNumberIndex = i;
    for (int j = i + 1; j < length; j++) {
      if (array[j] < array[minimumNumberIndex]) {
        minimumNumberIndex = j;
      }
    }
    swapTwoNumbers(&array[i], &array[minimumNumberIndex]);
  }
}

void swapTwoNumbers(int *a, int *b) {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int main(void)
{
  int array[] = {1, 0, 3, 2, 7, 4, -1, 0};
  int length = 8;

  selectionSort(array, length);

  for (int i = 0; i < length; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  return 0;
}
