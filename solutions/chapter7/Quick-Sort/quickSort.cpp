/*
 * Quick Sort
 */

#include <iostream>

using namespace std;

void exchange(int * a, int * b);
int partition(int array[], int p, int r);
void quickSort(int array[], int p, int r);

int main(void) {
  int arraySize;
  int testArray[100];

  cin >> arraySize;
  for (int i = 0; i < arraySize; i++) {
    cin >> testArray[i];
  }

  quickSort(testArray, 0, arraySize - 1);

  for (int i = 0; i < arraySize; i++) {
    cout << testArray[i] << " ";
  }
  cout << endl;

  return 0;
}

void exchange(int * a, int * b) {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int array[], int p, int r) {
  int x = array[r];
  int i = p - 1;

  for (int j = p; j <= r - 1; j++) {
    if (array[j] <= x) {
      i++;
      exchange(&array[i], &array[j]);
    }
  }
  exchange(&array[i + 1], &array[r]);

  return (i + 1);
}

void quickSort(int array[], int p, int r) {
  if (p < r) {
    int q = partition(array, p, r);
    quickSort(array, p, q - 1);
    quickSort(array, q + 1, r);
  }
}
