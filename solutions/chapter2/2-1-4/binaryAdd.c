/*
 * 2.1-4: Binary add
 */

#include <stdio.h>
#include <stdlib.h>

int* binaryAdd(int binaryArrayA[], int binaryArrayB[], int length)
{
  int *binaryArrayC = malloc(sizeof(int) * length + 1);
  int temp = 0;

  for (int i = length-1; i >= 0; i--) {
    int sum = binaryArrayA[i] + binaryArrayB[i] + temp;

    if (sum == 3) {
      binaryArrayC[i+1] = 1;
      temp = 1;
    } else if (sum == 2) {
      binaryArrayC[i+1] = 0;
      temp = 1;
    } else if (sum == 1) {
      binaryArrayC[i+1] = 1;
      temp = 0;
    } else if (sum == 0) {
      binaryArrayC[i+1] = 0;
      temp = 0;
    }

    binaryArrayC[i] = temp;
  }

  return binaryArrayC;
}

int main(void)
{
  int a[4] = {0, 0, 0, 0};
  int b[4] = {0, 0, 0, 1};

  int *c = binaryAdd(a, b, 4);

  for (int i = 0; i < 5; i++) {
    printf("%d ", c[i]);
  }
  printf("\n");

  free(c);

  return 0;
}

