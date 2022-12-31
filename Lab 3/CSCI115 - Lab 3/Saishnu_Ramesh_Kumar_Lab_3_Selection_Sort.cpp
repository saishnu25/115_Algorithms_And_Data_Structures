/*  
*   This program deals with Selection Sort.
*   Done By: Saishnu Ramesh Kumar
*   Student ID:300758706
*/

#include <iostream>
#include <stdlib.h>
#include <chrono>
#define ARRLEN 6 //Macro for array length

//Function Prototypes
void swap(int *x, int *y);
void selectionSort(int arr[], int len);
void print_array(int arr[], int size);

//Swap Function
void swap(int *x, int *y)
{

    int temp = *x;
    *x = *y;
    *y = temp;
}

//Selection Sort Function
void selectionSort(int arr[], int len){

    int i, j, min;

    for(i = 0; i < len-1; i++){
        min = i;
        for(j = i+1; j < len; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }   

        //Swap Function called
        swap(&arr[min], &arr[i]);
    }

}

//Print Function
void printArray(int *arr, int size){

    int i;
    for(i = 0; i < size; i++){
        std::cout << arr[i] << " "; //Prints out the sorted list
    }
}

//Main Function
int main(){

    std::chrono::time_point<std::chrono::high_resolution_clock> start_time, end_time; //Initializing the start and end time

    int arrOriginal[] = {28, 16, 78, 20, 37, 12};
    int arrSemiSorted[] = {11, 12, 22, 30, 25, 21};
    int arrReverse[] = {9, 5, 4, 3, 2, 1};

    std::cout << "\nBEFORE Selection Sort: ";

    std::cout << "\nArray BEFORE Selection Sort: ";
    printArray(arrOriginal, ARRLEN); //Print Array Function called

    std::cout << "\nSemi Sorted Array BEFORE Selection Sort: ";
    printArray(arrSemiSorted, ARRLEN);

    std::cout << "\nReverse Array BEFORE Selection Sort: ";
    printArray(arrReverse, ARRLEN);

    // Original Sorted
    start_time = std::chrono::high_resolution_clock::now(); //Start time
    selectionSort(arrOriginal, ARRLEN); //Selection Sort Function called
    end_time = std::chrono::high_resolution_clock::now(); //End time
    std::chrono::duration<double> elapsed_original = end_time - start_time; // Time Elapsed

    // Semi Sorted
    start_time = std::chrono::high_resolution_clock::now(); //Start time
    selectionSort(arrSemiSorted, ARRLEN); //Selection Sort Function called
    end_time = std::chrono::high_resolution_clock::now(); //End time
    std::chrono::duration<double> elapsed_semi_sorted = end_time - start_time; //Time Elapsed

    // Reverse Sorted
    start_time = std::chrono::high_resolution_clock::now(); //Start time
    selectionSort(arrReverse, ARRLEN); //Selection Sort Function called
    end_time = std::chrono::high_resolution_clock::now(); //End time
    std::chrono::duration<double> elapsed_reverse = end_time - start_time; //Time Elapsed

    std::cout << "\n\nAFTER Selection Sort: ";

    std::cout << "\nArray AFTER Selection Sort: ";
    printArray(arrOriginal, ARRLEN);

    std::cout << "\nSemi Sorted Array AFTER Selection Sort: ";
    printArray(arrSemiSorted, ARRLEN);

    std::cout << "\nReverse Sorted Array AFTER Selection Sort: ";
    printArray(arrReverse, ARRLEN);

    std::cout << "\n\nEXECUTION TIMES: ";
    std::cout << "\n\nExecution Time For Original: " << elapsed_original.count() << std::endl; //Outputs the time taken in seconds
    std::cout << "\nExecution Time For Semi Sorted: " << elapsed_semi_sorted.count() << std::endl; //Outputs the time taken in seconds
    std::cout << "\nExecution Time For Reverse: " << elapsed_reverse.count() << std::endl; //Outputs the time taken in seconds
    
    return 0;
}