/*
 *   This program deals with Quicksort
 *   Done By: Saishnu Ramesh Kumar
 *   Student ID: 300758706
 *
 */

#include <iostream>
#include <math.h>
#include <cstdlib>
#include <chrono>

// Swap Function
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// ---- FIRST ELEMENT FUNCTIONS ----

// Partition First Element Function
int partitionFirstElement(int arr[], int low, int high)
{

    int pivot = arr[low]; // Pivot set to the first element of list
    int i = (low - 1);
    int j = high + 1;

    while (true)
    {
        if (arr[j] > pivot)
        {
            j--;
        }

        if (arr[i] < pivot)
        {
            i++;
        }

        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }

        else
        {
            return j;
        }
    }
}

// QuickSort First Element Function
void quickSortFirst(int arr[], int leftIndex, int rightIndex)
{

    if (leftIndex < rightIndex)
    {
        int splitFirst = partitionFirstElement(arr, leftIndex, rightIndex);

        quickSortFirst(arr, leftIndex, splitFirst - 1);
        quickSortFirst(arr, splitFirst + 1, rightIndex);
    }
}

// ---- RANDOM ELEMENT FUNCTIONS ----

// Partition Random Element Function
int partitionRandomElement(int arr[], int low, int high)
{

    int i = low - 1;
    int j = high + 1;
    int pivot = arr[low];

    while (true)
    {
        if (arr[j] > pivot)
        {
            j--;
        }

        if (arr[i] < pivot)
        {
            i++;
        }

        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }

        else
        {
            return j;
        }
    }
}

int partitionRandomElement2(int arr[], int low, int high){

    int n = high - low + 1;
    int pivot = rand() % n; //Pivot set to a random element in the list

    swap(&arr[pivot], &arr[low]);
    return partitionRandomElement(arr, low, high);
}

// QuickSort Random Element Function
void quickSortRand(int arr[], int leftIndex, int rightIndex)
{

    if (leftIndex < rightIndex)
    {

        int splitRand = partitionRandomElement2(arr, leftIndex, rightIndex);

        quickSortRand(arr, leftIndex, splitRand - 1);
        quickSortRand(arr, splitRand + 1, rightIndex);
    }
}

// ---- MEDIAN ELEMENT FUNCTIONS ----

// Partition Median Element Function
int partitionMedianElement(int arr[], int low, int high)
{

    int i = low - 1;
    int j = high + 1;
    int pivot = arr[low];

    while (true)
    {
        if (arr[j] > pivot)
        {
            j--;
        }

        if (arr[i] < pivot)
        {
            i++;
        }

        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }

        else
        {
            return j;
        }
    }
}

int partitionMedianElement2(int arr[], int low, int high){

    int n = high - low + 1;
    int pivot;

    if (n % 2 == 0)
    {
        pivot = low + (n / 2); //Pivot set to median
    }
    else
    {
        pivot = low + ((n - 1)/ 2); //Pivot set to median
    }
    swap(&arr[pivot], &arr[low]);
    return partitionMedianElement(arr, low, high);
}

// QuickSort Median Function
void quickSortMedian(int arr[], int leftIndex, int rightIndex)
{

    if (leftIndex < rightIndex)
    {

        int splitMedian = partitionMedianElement2(arr, leftIndex, rightIndex);

        quickSortMedian(arr, leftIndex, splitMedian - 1);
        quickSortMedian(arr, splitMedian + 1, rightIndex);
    }
}

// Print Array Function
void printArray(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
}

// Main Function
int main()
{

    int choice;
    int arr[] = {10, 4, 6, 25, 30, 16};
    int n = sizeof(arr) / sizeof(arr[0]);

    while (true)
    {

        std::cout << "\n\nWelcome to the Quicksort Program, please enter a number below." << std::endl;
        std::cout << "1. Quicksort using the first element in the list" << std::endl;
        std::cout << "2. Quicksort using a random element in the array" << std::endl;
        std::cout << "3. Quicksort using the median of the first, middle, and last elements in the array" << std::endl;
        std::cout << "0. EXIT" << std::endl;
        std::cin >> choice;

        switch (choice)
        {

        // Quicksort using the first element in the list
        case 1:
        {

            std::cout << "\nBefore QuickSort:" << std::endl;
            printArray(arr, n);

            auto start_time = std::chrono::high_resolution_clock::now(); // Start time
            quickSortFirst(arr, 0, n - 1);
            auto end_time = std::chrono::high_resolution_clock::now(); // End time

            std::chrono::duration<double> elapsed = end_time - start_time; // Total time

            std::cout << "\nAfter QuickSort:" << std::endl;
            printArray(arr, n);

            std::cout << "\n\nElapsed time: " << elapsed.count() << std::endl; // Outputs the time taken in seconds
            break;
        }

        // Quicksort using a random element in the array
        case 2:
        {

            std::cout << "\nBefore QuickSort:" << std::endl;
            printArray(arr, n);

            auto start_time = std::chrono::high_resolution_clock::now(); // Start time
            quickSortRand(arr, 0, n - 1);
            auto end_time = std::chrono::high_resolution_clock::now(); // End time

            std::chrono::duration<double> elapsed = end_time - start_time; // Total time

            std::cout << "\nAfter QuickSort:" << std::endl;
            printArray(arr, n);

            std::cout << "\n\nElapsed time: " << elapsed.count() << std::endl; // Outputs the time taken in seconds
            break;
        }

        // Quicksort using the median of the first, middle, and last elements in the array
        case 3:
        {

            std::cout << "\nBefore QuickSort:" << std::endl;
            printArray(arr, n);

            auto start_time = std::chrono::high_resolution_clock::now(); // Start time
            quickSortMedian(arr, 0, n - 1);
            auto end_time = std::chrono::high_resolution_clock::now(); // End time

            std::chrono::duration<double> elapsed = end_time - start_time; // Total time

            std::cout << "\nAfter QuickSort:" << std::endl;
            printArray(arr, n);

            std::cout << "\n\nElapsed time: " << elapsed.count() << std::endl; // Outputs the time taken in seconds
            break;
        }

        // Exit Program
        case 0:
            std::cout << "\nProgram has ended..." << std::endl;
            return 0;

        // Default Case to catch menu input error
        default:
            std::cout << "\nInvalid number, please try again!" << std::endl;
            break;
        }
    }

    return 0;
}