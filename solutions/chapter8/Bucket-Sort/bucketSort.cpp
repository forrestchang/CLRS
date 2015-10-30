#include <iostream>

using namespace std;

int * append(int * array, int arraySize, int value);
void sort(int array[], int arraySize);
void bucketSort(float array[], int arraySize);

int main(void) {
  int arraySize;
  cin >> arraySize;
  float * array = new float[arraySize];

  for (int i = 0; i < arraySize; i++) {
    cin >> array[i];
  }

  bucketSort(array, arraySize);


  return 0;
}

void bucketSort(float array[], int arraySize) {
  int bucketArraySize = arraySize;
  int ** bucketArray = (int **)new int *[bucketArraySize];
  int flag[arraySize];

  for (int i = 0; i < arraySize; i++) {
    flag[i] = 0;
  }

  for (int i = 0; i < bucketArraySize; i++) {
    bucketArray[i] = NULL;
  }

  for (int i = 0; i < arraySize; i++) {
    bucketArray[(int)(arraySize * array[i])] = append(bucketArray[(int)(arraySize * array[i])], flag[(int)(arraySize * array[i])], array[i]);
  }

  for (int i = 0; i < bucketArraySize; i++) {
    // test
    for (int j = 0; j < flag[i]; j++) {
      bucketArray[i][j] *= 100;
    }

    sort(bucketArray[i], flag[i]);

    // test
    for (int j = 0; j < flag[i]; j++) {
      bucketArray[i][j] *= 100;
    }

  }

  // print test
  for (int i = 0; i < bucketArraySize; i++) {
    for (int j = 0; j < flag[i]; j++) {
      cout << bucketArray[i][j] << " ";
    }
  }
  cout << endl;

}

int * append(int * array, int arraySize, int value) {
  int size = arraySize + 1;
  int * tempArray = new int[size];

  for (int i = 0; i < arraySize; i++) {
    tempArray[i] = array[i];
  }
  tempArray[size - 1] = value;

  return tempArray;
}

void sort(int array[], int arraySize) {
  int i, j;
  int temp;

  for (i = 1; i < arraySize; i++) {
    temp = array[i];
    for (j = i - 1; j >= 0 && array[j] > temp; j--) {
      array[j + 1] = array[j];
    }
    array[j + 1] = temp;
  }
}
