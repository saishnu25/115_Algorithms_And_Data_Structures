//This exercise deals with the Fibonnaci Sequence using two different algorithms

#include <iostream>
#include <chrono>
#include <math.h>

//Recursive Function - **Remove comment lines to use this function

long long fibRec(int n){
    if(n <= 1){
        return n;
    }

    return fibRec(n - 1) + fibRec(n - 2);
}


//Variable Function - **Remove comment lines to use this function
/*
long long fibVar(int n){

    long long prev = 0;
    long long current = 1;

    for(long long i = 1; i <= n ; i++){

        long long temp = current;
        current = current + prev;
        prev = temp;
    }
    return prev;

}
*/


//Main Function
int main(){
    
    int n;

    std::cout << "Input a number: " << std::endl;
    std::cin >> n;

    auto start_time = std::chrono::high_resolution_clock::now(); //Start time

    long long resultRec = fibRec(n); //Calling fibRec Function - **Remove comment lines to use this line
    //long long resultVar = fibVar(n); //Calling fibVar Function - **Remove comment lines to use this line

    auto end_time = std::chrono::high_resolution_clock::now(); //End time

    std::chrono::duration<double> elapsed = end_time - start_time; //Total time

    std::cout<<"Result for fibRec: " << resultRec; //Outputs the function fibRec - **Remove comment lines to use this line
    //std::cout<<"Result for fibVar: "<< resultVar; //Outputs the function fibVar - **Remove comment lines to use this line

    std::cout << "\nElapsed time: " << elapsed.count() << std::endl; //Outputs the time taken in seconds

    return 0;
}