/*  
*   This program deals with Merge Sort.
*   Done By: Saishnu Ramesh Kumar
*   Student ID:300758706
*/

#include <iostream>
#include <stdlib.h>
#include <chrono>
#define ARRLEN 6 //Macro for array length

//Function Prototypes
void swap(int *x, int *y);
void merge(int arr[], int left, int middle, int right);
void mergeSort(int arr[], int left, int right);
void printArray(int *arr, int size);

//Swap Function
void swap(int *x, int *y){

    int temp = *x;
    *x = *y;
    *y = temp;
}

//Merge Function
void merge(int arr[], int left, int middle, int right){

    // If there are only two elements that need to be merged, swap them
    if (right - left == 1){
        if (arr[right] < arr[left]){
            swap(&arr[right], &arr[left]);
        }
        return;
    }

    //Initializing a new array to store our merged array
    int *mergedArray = (int *)malloc(sizeof(int) * (right - left + 1));
    
    int startLeft = left; // Starting index for our left array
    int stopLeft = middle; // Stopper is when left is middle

    int startRight = middle + 1; // Starting index for right array
    int stopRight = right; // Stopper is right
    
    int counter = 0;
    while (startLeft <= stopLeft || startRight <= stopRight){
        if (startLeft > stopLeft){
            mergedArray[counter] = arr[startRight];
            startRight++;
        }

        else if (startRight > stopRight){
            mergedArray[counter] = arr[startLeft];
            startLeft++;
        }
        
        else if (arr[startLeft] < arr[startRight]){
            mergedArray[counter] = arr[startLeft];
            startLeft++;
        }
        else if (arr[startLeft] >= arr[startRight]){
            mergedArray[counter] = arr[startRight];
            startRight++;
        }
        counter++;
    }

    counter = 0;
    for(int i = left; i <= right; i++){
        arr[i] = mergedArray[counter]; //Updates the array list in order
        counter++;
    }
        
    free(mergedArray);
}

//Merge Sort Function
void mergeSort(int arr[], int left, int right){

    if (left >= right){
        return;
    }

    int middle = left + ((right - left) / 2);
    mergeSort(arr, left, middle);
    mergeSort(arr, middle + 1, right);
    merge(arr, left, middle, right);
    
}

//Print Function
void printArray(int *arr, int size){

    int i;
    for (i = 0; i < size; i++){
        std::cout << arr[i] << " "; //Prints out the sorted list
    }
}

//Main Function
int main(){

    std::chrono::time_point<std::chrono::high_resolution_clock> start_time, end_time;

    int arrOriginal[] = {28, 16, 78, 20, 37, 12};
    int arrSemiSorted[] = {11, 12, 22, 30, 25, 21};
    int arrReverse[] = {9, 5, 4, 3, 2, 1};

    std::cout << "\nBEFORE Merge Sort: ";

    std::cout << "\nArray BEFORE Merge Sort: ";
    printArray(arrOriginal, ARRLEN);

    std::cout << "\nSemi Sorted Array BEFORE Merge Sort: ";
    printArray(arrSemiSorted, ARRLEN);

    std::cout << "\nReverse Array BEFORE Merge Sort: ";
    printArray(arrReverse, ARRLEN);

    // Original Sorted
    start_time = std::chrono::high_resolution_clock::now(); //Start time
    mergeSort(arrOriginal, 0, ARRLEN - 1);
    end_time = std::chrono::high_resolution_clock::now(); //End time
    std::chrono::duration<double> elapsed_original = end_time - start_time; // Time Elapsed

    // Semi Sorted
    start_time = std::chrono::high_resolution_clock::now(); //Start time
    mergeSort(arrSemiSorted, 0, ARRLEN - 1);
    end_time = std::chrono::high_resolution_clock::now(); //End time
    std::chrono::duration<double> elapsed_semi_sorted = end_time - start_time; //Time Elapsed

    // Reverse Sorted
    start_time = std::chrono::high_resolution_clock::now(); //Start time
    mergeSort(arrReverse, 0, ARRLEN - 1);
    end_time = std::chrono::high_resolution_clock::now(); //End time
    std::chrono::duration<double> elapsed_reverse = end_time - start_time; //Time Elapsed

    std::cout << "\n\nAFTER Merge Sort: ";

    std::cout << "\nArray AFTER Merge Sort: ";
    printArray(arrOriginal, ARRLEN);

    std::cout << "\nSemi Sorted Array AFTER Merge Sort: ";
    printArray(arrSemiSorted, ARRLEN);

    std::cout << "\nReverse Sorted Array AFTER Merge Sort: ";
    printArray(arrReverse, ARRLEN);

    std::cout << "\n\nEXECUTION TIMES: ";
    std::cout << "\n\nExecution Time For Original: " << elapsed_original.count() << std::endl;     //Outputs the time taken in seconds
    std::cout << "\nExecution Time For Semi Sorted: " << elapsed_semi_sorted.count() << std::endl; //Outputs the time taken in seconds
    std::cout << "\nExecution Time For Reverse: " << elapsed_reverse.count() << std::endl;         //Outputs the time taken in seconds

    return 0;
}