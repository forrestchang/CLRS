/*
 * 2.1-3: Linear search
 */

#include <stdio.h>

int linearSearch(double array[], int begin, int end, double value)
{
  for (int i = begin; i <= end; i++){
    if (value == array[i]) {
      return i;
    }
  }
  return -1;
}

int main(void)
{
  double testArray[] = {0, 3, 4, 2};
  int begin = 0, end = 3;
  double searchValue = 3;
  int index;

  index = linearSearch(testArray, begin, end, searchValue);

  printf("%d\n", index);

  return 0;
}
