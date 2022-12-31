/*
*
*       Heap Sort Program
*       Done By: Saishnu Ramesh Kumar 
*       Student ID: 300758706
*
*/

#include <iostream>

#define MAX 1000 //Max array size

//Function Prototype - Print Array
void printArray();

//Function Prototypes -  MAX HEAP
void modifyValMax(int i, int val);                      //Modify value
void insert_value_maxHeap(int val);                     //Adds value at the end of array and calls max_heapify
void max_heapify(int i);                                //Maintains the max heap property
int extract_maximum();                                  //Return the maximum element in heap and swap last element with first element
void ascendingHeapSort(int n);                          //Prints the array in ascending order
void buildMaxHeap();                                    //Heapifies entire list

//Function Prototypes - MIN HEAP
void modifyValMin(int n, int i, int val);               //Modify value
void insert_value_minHeap(int val, int &n);             //Adds value at the end of array and calls min_heapify
void min_heapify(int i);                                //Maintains min heap property
int extract_minimum(int &n);                            //Return the minimum element in heap and swap last element with first element
void descendingHeapSort(int n);                         //Prints the array in descending order
void buildMinHeap();                                    //Heapifies entire list


//Heap Class 
class Heap{

    public:
    int Arr[MAX];
    int size;
    
    //Heap Constructor
    Heap(int Arr[], int size){

        for (int i = 0; i < size; i++){

            this->Arr[i] = Arr[i];
        }
        this->size = size;
    
    };

    //Swap Function
    int swap(int *x, int *y){
            
        int temp = *x;
        *x = *y;
        *y = temp;

        return 0;
    }

    /*---- MAX HEAP FUNCTIONS ----*/
    
    //Modify Max Value
    void modifyValMax(int i, int val){
        this->Arr[i] = val;

        for (int last = i; last >= 0; last--){
            this->max_heapify(last);
        }
    }

    
    //Adds value at the end of array and calls max_heapify
    void insert_value_maxHeap(int val){
        
        this->size = this->size + 1; //Adding an extra space

        Arr[this->size - 1] = val;  // Inserting val into extra space

        this->buildMaxHeap(); // Preserves the max heap structure after inserting
    }
    
    //Maintains the max heap property - Max Heapify Function
    //We heapify the tree based on a specific node
    void max_heapify(int i){
            
        int left = (2 * i) + 1;
        int right = (2 * i) + 2;
        int largestNode = i;

        // Performs swapping between parent node and child nodes
        if(left < this->size && this->Arr[left] > this->Arr[largestNode]){
            largestNode = left;
        }

        if(right < this->size && this->Arr[right] > this->Arr[largestNode]){
            largestNode = right;
        }

        // We want to swap
        if(largestNode != i){
            swap(&this->Arr[i], &this->Arr[largestNode]); // Perform the swap

            max_heapify(largestNode); // Want to continuously max heapify if we did swap
        }
    }


    //Return the maximum element in heap and swap last element with first element 
    int extract_maximum(){
        int temp = this->Arr[0]; // Assigns root of heap to temporary variable
        this->Arr[0] = this->Arr[this->size - 1]; // Assigns root of heap to last element of heap
        this->size--; // Decreases heap size by one
        this->max_heapify(0); // Heapify root node

        return temp; // Return max
    }

    //Prints the array in ascending order
    void ascendingHeapSort(){
        
        this->buildMaxHeap();

        int size = this->size;

        for(int i = size; i > 0; i--){
            this->Arr[i-1] = extract_maximum(); //Extracting the array list in order to sort it in ascending order
        }

        this->size = size; //Resetting the size again

    }        

    //Heapifies entire list
    void buildMaxHeap(){

        // Gets the last non-leaf node
        int n = this->size;
        int last = (n/2) - 1;

        // Heapifies the array for every single non leaf node - Goes from bottom to top
        for(int i = last; i >= 0; i--){
            max_heapify(i);
        }
    }
    
    /*---- END OF MAX HEAP FUNCTIONS ----*/


    /*---- MIN HEAP FUNCTIONS ----*/
    
    //Modifying the min value
    void modifyValMin(int i, int val){

        this->Arr[i] = val;

        for (int last = i; last >= 0; last--){
            this->min_heapify(last);
        }
    }

    // Adds value at the end of array and calls min_heapify
    void insert_value_minHeap(int val){
        
        this->size = this->size + 1; //Adding an extra space

        Arr[this->size - 1] = val; // Inserting val into extra space

        this->buildMinHeap(); // Preserves the min heap structure after inserting
    }

    //Min Heapify Function 
    void min_heapify(int i){ 

            int left = (2 * i) + 1;
            int right = (2 * i) + 2;
            int smallestNode = i;

            if(left < this->size && this->Arr[left] < this->Arr[smallestNode]){
                smallestNode = left;
            }

            if(right < this->size && this->Arr[right] < this->Arr[smallestNode]){
                smallestNode = right;
            }

            if(smallestNode != i){
                swap(&this->Arr[i], &this->Arr[smallestNode]); // Perform the swap

                min_heapify(smallestNode); // Want to continuously min heapify if we did swap
            }

    }

    //Return the minimum element in heap and swap last element with first element
    int extract_minimum(){

        int temp = this->Arr[0];                  // Assigns root of heap to temporary variable
        this->Arr[0] = this->Arr[this->size - 1]; // Assigns root of heap to last element of heap
        this->size--;                             // Decreases heap size by one
        this->min_heapify(0);                     // Heapify root node

        return temp; // Return max
    }             

    //Lists the arrays in descending order, from smallest to largest value
    void descendingHeapSort(){ 

        this->buildMinHeap();

        int size = this->size;

        for(int i = size; i > 0; i--){
            this->Arr[i-1] = extract_minimum(); //Extracting the minimum in order to sort in descending order
        }      

        this->size = size; //Resetting the size       

    }             
    
    //Build Min Heap function, heapifies the entire list
    void buildMinHeap(){

        // Gets the last non-leaf node
        int n = this->size;
        int last = (n / 2) - 1;

        // Heapifies the array for every single non leaf node - Goes from bottom to top
        for (int i = last; i >= 0; i--){
            min_heapify(i);
        }
    }

    /*---- END OF MIN HEAP FUNCTIONS ----*/

    //Print Array Function
    void printArray(){
        for (int i = 0; i < this->size; i++){
            std::cout << this->Arr[i] << " ";
        }
        std::cout << "\n";
    }
};

//Main Function
int main(){

    int Arr [] = {3, 6, 10, 1, 15, 22, 37};
    int choice;

    int n = sizeof(Arr) / sizeof(Arr[0]);

    while(true){

        //Menu system to allow user to pick which type of heap sort they would like to execute
        std::cout <<"\n\n*Welcome to the Heap Sort program*"<<std::endl;
        std::cout <<"Press 1 for Ascending order heap sort."<<std::endl;
        std::cout <<"Press 2 for Descending order heap sort."<<std::endl;
        std::cout <<"Press 0 to EXIT program."<<std::endl;
        std::cin >> choice;

        switch(choice){

            //Case 1 - Heap sort in ascending order (Max Heap)
            //Will list the numbers from the biggest to the smallest
            case 1:
                {
                    std::cout << "Maximum heap sort:" << std::endl;
                    Heap *heap = new Heap(Arr, n); //Heap object
                    std::cout<< "\nOriginal List:" <<std::endl;
                    heap->printArray();

                    //Building the Max Heap 
                    heap->buildMaxHeap();
                    std::cout<< "\nArray after Max Heapify:"<<std::endl;
                    heap->printArray();

                    //Inserting an element into the heap
                    heap->insert_value_maxHeap(40);
                    std::cout << "\nArray after inserting 40 in heap" << std::endl;
                    heap->printArray();

                    //Modifying the current element in the heap
                    heap->modifyValMax(3, 100);
                    std::cout<< "\nArray after modifying 4th element to a value of 100 in heap" << std::endl;
                    heap->printArray();

                    //Extracting element from max heap by switching the maximum and minimum elements
                    heap->extract_maximum();
                    std::cout<< "\nArray after extracting element from max heap and inserting new element:"<<std::endl;
                    heap->printArray();

                    //Ascending heap sort function
                    heap->ascendingHeapSort();
                    std::cout<< "\nArray after calling ascending heap sort:"<<std::endl;
                    heap->printArray();

                } 
                break;

            //Case 2 - Heap sort in descending order (Min Heap)
            //Will list the numbers from the smallest to the biggest 
            case 2:
                {
                    std::cout << "Minimum heap sort:" << std::endl;
                    Heap *heap = new Heap(Arr, n); //Heap object
                    std::cout << "\nOriginal List:" << std::endl;
                    heap->printArray();

                    //Building the Min Heap
                    heap->buildMinHeap();
                    std::cout << "\nArray after Min Heapify:" << std::endl;
                    heap->printArray();

                    //Inserting an element into the heap
                    heap->insert_value_minHeap(30);
                    std::cout << "\nArray after inserting 30 in heap" << std::endl;
                    heap->printArray();

                    //Modifying the current element in the heap
                    heap->modifyValMin(3, 11);
                    std::cout << "\nArray after modifying 4th element to a value of 11 in heap" << std::endl;
                    heap->printArray();

                    //Extracting element from max heap by switching the maximum and minimum elements
                    heap->extract_minimum();
                    std::cout << "\nArray after extracting element from max heap and inserting new element:" << std::endl;
                    heap->printArray();

                    //Descending heap sort function
                    heap->descendingHeapSort();
                    std::cout << "\nArray after calling ascending heap sort:" << std::endl;
                    heap->printArray();
                    
                }
                break;

            //Case 0 - Exit
            case 0:
                std::cout<<"This program has ended..."<<std::endl;
                return 0;

        }
    }

    return 0;
}