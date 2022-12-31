/*
*   This program shows Counting Sort
*   Done By: Saishnu Ramesh Kumar
*   Student ID: 300758706
*/

#include <iostream>
#include <stdlib.h>
#include <chrono>

//Function Prototypes
void countingSort(int arr[], int size);
void printArray(int arr[], int size);

//Counting Sort Function
void countingSort(int arr[], int size){

    int output[10];
    int count[10];
    int max = arr[0];

    //Get the largest element in the array
    for (int i = 1; i < size; i++){
        if (arr[i] > max)
            max = arr[i];
    }

    //Initializing all the elements in the count array with zeros
    for (int i = 0; i <= max; ++i){
        count[i] = 0;
    }

    //Storing each element inside the count list
    for (int i = 0; i < size; i++){
        count[arr[i]]++;
    }

    //Stores the cumulative count in the array
    for (int i = 1; i <= max; i++){
        count[i] += count[i - 1];
    }

    //Locate each index of each element of the original array in count and then put them into the output array
    for (int i = size - 1; i >= 0; i--){
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    //Copying the sorted elements back into the original array
    for (int i = 0; i < size; i++){
        arr[i] = output[i];
    }
}

//Print Array Function
void printArray(int arr[], int size){

    for(int i = 0; i < size; i++){
        std::cout << arr[i] << " ";
    }

}

//Main Function
int main(){

    int arr[] = {4, 2, 11, 8, 5, 13, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "\nBefore Counting Sort: " << std::endl; //Before sorting
    printArray(arr, n);

    auto start_time = std::chrono::high_resolution_clock::now(); //Start time
    countingSort(arr, n); //Calling the counting sort function
    auto end_time = std::chrono::high_resolution_clock::now(); //End time

    std::chrono::duration<double> elapsed = end_time - start_time; //Total time

    std::cout << "\n\nAfter Counting Sort: " << std::endl; //After sorting
    printArray(arr, n);

    std::cout << "\n\nElapsed time: " << elapsed.count() << std::endl; //Outputs the time taken in seconds

    return 0;
}