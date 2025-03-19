#ifndef ARROP_H
#define ARROP_H

void initializeArray(int arr[], int size, int value);

void printArray(int arr[], int size);

int findMax(int arr[], int size);

int findMin(int arr[], int size);

int sumArray(int arr[], int size);

double averageArray(int arr[], int size);

bool isSorted(int arr[], int size);

void reverseArray(int arr[], int size);

void countEvenOdd(int arr[], int size, int* evenCount, int* oddCount);

int secondLargest(int arr[], int size);

void elementFrequency(int arr[], int size);

int removeDuplicates(int arr[], int size);

int binarySearch(int arr[], int size, int target);

int linearSearch(int arr[], int size, int target);

void leftShift(int arr[], int size, int rotations);

void rightShift(int arr[], int size, int rotations);

void bubbleSort(int arr[], int size);

void selectionSort(int arr[], int size);

void insertionSort(int arr[], int size);

#endif
