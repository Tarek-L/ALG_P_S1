#include <stdio.h>

void initializeArray(int arr[], int size, int value){

    for (int i = 0; i < size; i++)
        arr[i] = value;

}

void printArray(int arr[], int size){

    for (int i = 0; i < size; i++)
        printf("%d ,",arr[i]);

}

int findMax(int arr[], int size){

    int max = arr[0] //assume it is the max

    for (int i = 0; i < size; i++) //itirate through the array
        if (arr[i] > max) //check if current element is the greatest so far
            max = arr[i]; //set new max

    return max;
}

int findMin(int arr[], int size){

    int min = arr[0] //assume it is the min                                                                                                             
     
    for (int i = 0; i < size; i++) //itirate through the array
        if (arr[i] < min) //check if current element is the smallest so far
            min = arr[i]; //set new min

    return min;
}

int sumArray(int arr[], int size){

    int sum = 0;

    for (int i = 0; i < size; i++)
        sum = sum + arr[i];

    return sum;
}

double averageArray(int arr[], int size){

    double avg = sumArray(arr) / (size - 1);

    return avg;

}

bool isSorted(int arr[], int size){

    for (int i = 0; i < size - 1; i++)
        if (arr[i] > arr[i + 1])
            return false;

    return true;
}

void reverseArray(int arr[], int size){

    int tmp, i = 0;

    while (size > i){

        size --;

        tmp = arr[i];
        arr[i] = arr[size];
        arr[size] = tmp;

        i ++;

        }
    
}

void countEvenOdd(int arr[], int size, int* evenCount, int* oddCount){
 
    for (int i = 0; i < size; i++)
        if (arr[i] % 2 == 0)
            *evenCount ++;
        else
            *oddCount ++;

 }

int secondLargest(int arr[], int size){

    int max = arr[0] , max2 = 0;
    
        for (int i = 0; i < size; i++) //itirate through the array
            //check if current element is the greatest so far  
            if (arr[i] > max){
                max2 = max; //store last max
                max = arr[i]; //set new max
            }

    return max2;
}

void elementFrequency(int arr[], int size) {
    // Create a frequency array to store the count of each element
    int frequency[size]; // Frequency array
    int dup = -1; // To not revisit counted items

    // Initialize the frequency array to 0
    initializeArray(arr[],size, 0);

    // Count the frequency of each element
    for (int i = 0; i < size; i++) {
        int count = 1; // Initialize count for the current element

        // Skip if the element has already been counted
        if (frequency[i] == dup) {
            continue;
        }

        // Count occurrences of the current element
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
                frequency[j] = dup; // Mark the element as counted
            }
        }

        // Store the count in the frequency array
        frequency[i] = count;
    }

    // Print the frequency of each unique element
    printf("Element : Frequency\n");
    for (int i = 0; i < size; i++) {
        if (frequency[i] != dup) {
            printf("%d : %d\n", arr[i], frequency[i]);
        }
    }
}

int removeDuplicates(int arr[], int size){

    // If the array is empty or has only one element, no duplicates to remove
    if (size <= 1) {
        return size;
    }

    int newSize = 0; // Index for the new array without duplicates

    // Iterate through the array
    for (int i = 0; i < size; i++) {
        // If the current element is not equal to the next element, add it to the new array
        if (i == size - 1 || arr[i] != arr[i + 1]) {
            arr[newSize] = arr[i]; // Copy the element to the new position
            newSize++; // Increment the size of the new array
        }
    }

    return newSize; 
}

int binarySearch(int arr[], int size, int target){

    int high = size - 1,low = 0,mid;

    while (low <= high){
    
        mid = (high + low) / 2;

        if (arr[mid] == target)
            return mid;
        else{ 
            if (arr[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
            }
    
    }

    return - 1;
}

int linearSearch(int arr[], int size, int target){

    for (int i = 0; i < size; i++)
        if (arr[i] == target)
            return i;

    return -1;
}

void leftShift(int arr[], int size, int rotations) {
    // To avoid unnecessary shifts
    rotations = rotations % size;

    // Temporary array to store the shifted elements
    int temp[rotations];

    // Step 1: Store the first `rotations` elements in a temporary array
    for (int i = 0; i < rotations; i++) {
        temp[i] = arr[i];
    }

    // Step 2: Shift the remaining elements to the left
    for (int i = 0; i < size - rotations; i++) {
        arr[i] = arr[i + rotations];
    }

    // Step 3: Copy the elements from the temporary array to the end of the original array
    for (int i = 0; i < rotations; i++) {
        arr[size - rotations + i] = temp[i];
    }
}

void rightShift(int arr[], int size, int rotations) {
    // To avoid unnecessary shifts
    rotations = rotations % size;

    // Temporary array to store the shifted elements
    int temp[rotations];

    // Step 1: Store the first `rotations` elements in a temporary array
    for (int i = size - rotations; i < size; i++) {
        temp[i + rotations - size] = arr[i];
    }   

    // Step 2: Shift the remaining elements to the right
    for (int i = 0; i < size - rotations; i++) {
        arr[i + rotations] = arr[i];
    }   

    // Step 3: Copy the elements from the temporary array to the original array
    for (int i = 0; i < rotations; i++) {
        arr[i] = temp[i];
    }   
}   

void bubbleSort(int arr[], int size) {

  int sorted = 0;
    for (int i = 0; i < size - 1 && sorted == 0; i++) {
        sorted = 1;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                sorted = 0;
            }
        }
    }
}

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int ins = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > ins) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = ins;
    }
}

int findMissingNumber(int arr[], int size){

    bubbleSort(arr, size);

    for (int i = 1; i < size; i++)
        if (arr[i - 1] != i)
            return i;
}

void findPairsWithSum(int arr[], int size, int sum){

    int i, j;
    
    for (i = 0; i < size - 2; i++)
        for (j = i + 1; j < size;j++)
            if (arr[i] + arr[j] == sum)
                printf("(%d + %d)\n",arr[i],arr[j]);
}

void findSubArrayWithSum(int arr[], int size, int sum){

    int i, j = 0;

    while (j < size){

        int sum1 = 0;

        for (i = j;sum1 < sum && i < size;i++){ 
            sum1 = sum1 + arr[i];
        }
        
        if (sum1 == sum)
            printf("(%d , %d)\n",j,i - 1);
        if (i == size && sum1 <= sum)
            break;
    }
}

void rearrange(int arr[], int size){

    int arr1[size];

    for (int i = 0;i < size;i++) {

         



    }



}


