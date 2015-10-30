/*
 * 2.1 Insertion Sort with ascending order
 */

#include <stdio.h>

void insertionSort(double array[], int begin, int end)
{
  int i, j;
  double temp;

  for (i = begin + 1; i <= end; i++) {
    temp = array[i];
    for (j = i - 1; j >= begin && array[j] > temp; j--) {
      array[j+1] = array[j];
    }
    array[j+1] = temp;
  }
}

int main(void)
{
  double testArray[] = {-1, 0.9, 0, 2, 0.5, 7, 3};
  int begin = 0, end = 6;

  insertionSort(testArray, begin, end);

  for (int i = begin; i <= end; i++) {
    printf("%.1f ", testArray[i]);
  }
  printf("\n");

  return 0;
}
