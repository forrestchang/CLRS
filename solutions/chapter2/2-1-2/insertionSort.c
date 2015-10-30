/*
 * 2.1-2 Insertion sort with decending order
 */

#include <stdio.h>

void insertionSort(double array[], int begin, int end)
{
  int i, j;
  double temp;

  for (i = begin + 1; i <= end; i++) {
    temp = array[i];
    for (j = i - 1; j >= 0 && array[j] < temp; j--) {
      array[j+1] = array[j];
    }
    array[j+1] = temp;
  }
}

int main(void)
{
  double testArray[] = {3, 1, 4, 2};
  int begin = 0, end = 3;

  insertionSort(testArray, begin, end);

  for (int i = 0; i <= end; i++) {
    printf("%.1f ", testArray[i]);
  }
  printf("\n");

  return 0;
}
