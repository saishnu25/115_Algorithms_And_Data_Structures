/* 
*       This program deals with using Hash Tables for the play Romeo and Juliet
*       Done By: Saishnu Ramesh Kumar
*       Student ID: 300758706
*
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#define HASHSIZE 4001 // Macro for the total number of unique words

// Hash Array Class
class hashArray{
private:
    std::string key;
    std::string hashTable[HASHSIZE];
    float update[HASHSIZE];
    float cost[HASHSIZE];

public:
    hashArray();
    ~hashArray();
    int hash(std::string key);
    void updates(std::string word);

    int temp = 0;
    int probes = 0;
    int size();
    void ratio();
};

//Constructor for Hash Array
hashArray::hashArray()
{
    while (temp != HASHSIZE){
        hashTable[temp] = "NULL";
        update[temp] = NULL; // Setting elements in array update to NULL
        cost[temp] = NULL;   // Setting elements in array costs to NULL
        temp++;
    }
}

// Destructor for Hash Array
hashArray::~hashArray(){

}

// Hash Function to return index for string key
int hashArray::hash(std::string key){
    
    int sum = 0;
    int index;

    for (int i = 0; i < key.length(); i++){
        sum = sum + (int)key[i];
    }

    index = sum % HASHSIZE;
    return index;
}

// Updates Function
void hashArray::updates(std::string key){
    std::string temp;
    int index = hash(key);
    if (hashTable[index] == "NULL"){ // If slot is empty at that index

        hashTable[index] = key; // Insert the string key at that index
        update[index] = 1;      // If the slot is empty, then update and cost will be just 1
        cost[index] = 1;       
    }
    else{
        if (key != hashTable[index]){
            while ((hashTable[index] != "NULL") && (hashTable[index] != key)){
                index++;
                probes++;
                if (index > HASHSIZE){       // If index is larger than the table size
                    index = 0; //Index will be set back to 0 and increment until it finds an empty slot
                }
                cost[index] = cost[index]++; // Increment cost when probes needed
            }
        }
        else{
            
            cost[index] = cost[index]++; // Increment cost if the string is same with the one at hashTable
            probes++;
        }
        update[index] = update[index]++;
        hashTable[index] = key;
    }
}

// Size Function to return unique words
int hashArray::size(){

    int arraySize = 0;
    for (int i = 0; i < HASHSIZE; i++){

        if (hashTable[i] != "NULL"){
            arraySize++;
        }
    }
    return arraySize;
}

// Ratio Function
void hashArray::ratio(){
    
    float ratio;
    
    std::cout << "\n\nRatio: " << std::endl;
    for (int a = 1; a < HASHSIZE; a++){

        if (update[a] != NULL){

            ratio = (cost[a] / update[a]);
            std::cout << std::fixed;
            std::cout << std::setprecision(2);
            std::cout << ratio << ", ";
        }
    }
}

// Main Function
int main()
{
    hashArray h;

    std::ifstream fileInput;

    fileInput.open("RomeoAndJuliet.txt"); //Reading the Romeo and Juliet txt file
    std::string key;

    key.clear(); // Clears the string

    while (fileInput >> key){
        h.updates(key);
        key.clear();
    }

    std::cout << "Total number of unique words:" << h.size() << std::endl;
    h.ratio();

    std::cout << "\n\nEnd of program..." << std::endl;

    fileInput.close();

    return 0;
}