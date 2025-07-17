#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
void initArray(int* arr, int size, int minVal, int maxVal) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = minVal + rand() % (maxVal - minVal + 1);
    }
}

void inputArray(int* arr, int size) {
    cout << "Введите " << size << " элементов массива:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int findMinIndex(int* arr, int size) {
    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

int findMaxIndex(int* arr, int size) {
    int maxIndex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

int countBetweenMinMax(int* arr, int size) {
    int minIndex = findMinIndex(arr, size);
    int maxIndex = findMaxIndex(arr, size);
    
    if (abs(maxIndex - minIndex) <= 1) return 0;
    
    return abs(maxIndex - minIndex) - 1;
}

int findFirstExtremum(int* arr, int size) {
    for (int i = 1; i < size - 1; i++) {
        if ((arr[i] > arr[i-1] && arr[i] > arr[i+1]) || 
            (arr[i] < arr[i-1] && arr[i] < arr[i+1])) {
            return i;
        }
    }
    return -1;
}

int findLastExtremum(int* arr, int size) {
    for (int i = size - 2; i > 0; i--) {
        if ((arr[i] > arr[i-1] && arr[i] > arr[i+1]) || 
            (arr[i] < arr[i-1] && arr[i] < arr[i+1])) {
            return i;
        }
    }
    return -1;
}

void trimToExtremums(int* arr, int& size) {
    int first = findFirstExtremum(arr, size);
    int last = findLastExtremum(arr, size);
    
    if (first == -1 || last == -1) return;
    
    int newSize = last - first + 1;
    for (int i = 0; i < newSize; i++) {
        arr[i] = arr[first + i];
    }
    size = newSize;
}

int* getBetweenExtremums(int* arr, int size, int& newSize) {
    int first = findFirstExtremum(arr, size);
    int last = findLastExtremum(arr, size);
    
    if (first == -1 || last == -1) {
        newSize = 0;
        return nullptr;
    }
    
    newSize = last - first + 1;
    int* newArr = new int[newSize];
    
    for (int i = 0; i < newSize; i++) {
        newArr[i] = arr[first + i];
    }
    
    return newArr;
}

int main() {
    const int SIZE = 10;
    int arr[SIZE];
    
    initArray(arr, SIZE, 0, 100);
    cout << "Исходный массив: ";
    printArray(arr, SIZE);
    
    cout << "Индекс минимального: " << findMinIndex(arr, SIZE) << endl;
    cout << "Индекс максимального: " << findMaxIndex(arr, SIZE) << endl;
    cout << "Элементов между min и max: " << countBetweenMinMax(arr, SIZE) << endl;

    int arr2[SIZE] = {1, 3, 2, 5, 4, 6, 3, 2, 7, 1};
    cout << "\nМассив для работы с экстремумами: ";
    printArray(arr2, SIZE);
    
    int size2 = SIZE;
    trimToExtremums(arr2, size2);
    cout << "После удаления элементов вне экстремумов: ";
    printArray(arr2, size2);
    
    int newSize;
    int* newArr = getBetweenExtremums(arr, SIZE, newSize);
    if (newArr) {
        cout << "\nНовый массив между экстремумами: ";
        printArray(newArr, newSize);
        delete[] newArr;
    }
    
    return 0;
}