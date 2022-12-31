/*
*   This program shows Radix Sort
*   Done By: Saishnu Ramesh Kumar
*   Student ID: 300758706
*/

#include <iostream>
#include <stdlib.h>
#include <chrono>

//Funtion Prototypes
int getMax(int arr[], int size);
void radixSort(int arr[], int size);
void countingSort(int arr[], int size, int place);
void printArray(int arr[], int size);

//Get Max Function
int getMax(int arr[], int n){
    int max = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

//Counting Sort Function
void countingSort(int arr[], int size, int place){
    const int max = 10;
    int output[size];
    int count[max];

    for(int i = 0; i < max; ++i){
        count[i] = 0;
    }

    //Calculating the elements in count 
    for(int i = 0; i < size; i++){
        count[(arr[i] / place) % 10]++;
    }

    //Calculating the cumulative count
    for(int i = 1; i < max; i++){
        count[i] += count[i - 1];
    }

    //Putting each element in its sorted position
    for(int i = size - 1; i >= 0; i--){
        output[count[(arr[i] / place) % 10] - 1] = arr[i];
        count[(arr[i] / place) % 10]--;
    }

    for(int i = 0; i < size; i++){
        arr[i] = output[i];
    }
}

//Radix Sort Function
void radixSort(int arr[], int size){
    int max = getMax(arr, size); //Obtaining the maximum element from the list

    //Applying counting sort to sort the element based their respective place value
    for(int place = 1; max / place > 0; place *= 10){
        countingSort(arr, size, place);
    }
}

//Print Array Function
void printArray(int arr[], int size){

    for (int i = 0; i < size; i++){
        std::cout << arr[i] << " ";
    }
}

//Main Function
int main(){

    int arr[] = {11, 54, 888, 23, 9, 15, 60};
    int n = sizeof(arr)/ sizeof(arr[0]);

    std::cout << "\nBefore Radix Sort: " << std::endl; //Before sorting
    printArray(arr, n);

    auto start_time = std::chrono::high_resolution_clock::now(); //Start time
    radixSort(arr, n); //Calling the radix sort function
    auto end_time = std::chrono::high_resolution_clock::now(); //End time

    std::chrono::duration<double> elapsed = end_time - start_time; //Total time

    std::cout << "\n\nAfter Radix Sort: " << std::endl; //After sorting
    printArray(arr, n);

    std::cout << "\n\nElapsed time: " << elapsed.count() << std::endl; //Outputs the time taken in seconds

    return 0;
}