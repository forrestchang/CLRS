#include <iostream>
#include <cstdlib>

using namespace std;

void countingSort(int array[], int arraySize, int result[], int k);
int max(int array[], int arraySize);

int main(void) {
  int testArray[1000];
  int resultArray[1000];
  int arraySize;

  cin >> arraySize;
  for (int i = 0; i < arraySize; i++) {
    cin >> testArray[i];
  }

  int k = max(testArray, arraySize);
  countingSort(testArray, arraySize, resultArray, k);

  for (int i = 0; i < arraySize; i++) {
    cout << resultArray[i] << " ";
  }
  cout << endl;

  return 0;
}

int max(int array[], int arraySize) {
  int largest = array[0];
  for (int i = 0; i < arraySize; i++) {
    largest = largest > array[i] ? largest : array[i];
  }

  return largest;
}

void countingSort(int array[], int arraySize, int result[], int k) {
  int * countArray = (int *)malloc((k + 1) * sizeof(int));
  int countArraySize = k + 1;

  // 初始化临时数组为0
  for (int i = 0; i < countArraySize; i++) {
    countArray[i] = 0;
  }

  // 如果一个输入元素的值为i，则对应增加countArray[i]的值，countArray[i]中保存的是元素i的个数
  for (int i = 0; i < arraySize; i++) {
    countArray[array[i]]++;
  }

  // 包含小于或等于i个元素的个数
  for (int i = 1; i < countArraySize; i++) {
    countArray[i] += countArray[i - 1];
  }

  for (int i = arraySize - 1; i >= 0; i--) {
    result[countArray[array[i]] - 1] = array[i];
    countArray[array[i]]--;
  }

  free(countArray);
}
