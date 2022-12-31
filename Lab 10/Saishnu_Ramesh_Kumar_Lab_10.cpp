/* 
*
*   This program deals with the Longest Common Subsequence example in Dynamic Programming
*   Done By: Saishnu Ramesh Kumar
*   Student ID: 300758706
*
*/

#include <iostream>
#include <iomanip>
#include <chrono>

//LCS Function
void LCS(std::string x, std::string y, int m, int n){

    //Creating a 2D array
    int **matrix = new int *[m + 1];
    for (int i = 0; i < m + 1; i++){
        matrix[i] = new int[n + 1];
    }

    //Nested for loop
    for (int i = 0; i <= m; i++){
        for (int j = 0; j <= n; j++){ 

            //Conditional statements for the matrix c[i,j]
            //First case
            if (i == 0 || j == 0){
                matrix[i][j] = 0;
            }

            //Second case
            else if (x[i - 1] == y[j - 1]){
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            }

            //Third case
            else{
                matrix[i][j] = std::max(matrix[i - 1][j], matrix[i][j - 1]);
            }
        }
    }

    int index = matrix[m][n];
    char *longest = new char[index + 1];
    longest[index] = '\0';

    //Reassigning m and n
    int i = m;
    int j = n;

    while (index > 0){
        
        if (matrix[i - 1][j] == matrix[i][j]){
            i--;
        }

        else if (matrix[i][j - 1] == matrix[i][j]){
            j--;
        }

        else{
            longest[index - 1] = x[i - 1];
            i--;
            j--;
            index--;
        }
    }
    std::cout << "LCS of " << x << " and " << y << " is: " << matrix[m][n] <<", (" << longest << ") "<< std::endl;
}

//Main Function
int main(){

    //First Try
    std::string x1 = "ABCDA";
    std::string y1 = "BCAD";

    int m1 = x1.length();
    int n1 = y1.length();

    //Calling LCS Function
    LCS(x1, y1, m1, n1);
    std::cout << std::endl;

    //Second Try
    std::string x2 = "ACBBAD";
    std::string y2 = "ABC";

    int m2 = x2.length();
    int n2 = y2.length();

    //Calling LCS Function
    LCS(x2, y2, m2, n2);
    std::cout << std::endl;

    std::cout << "End of program..." <<std::endl;


    return 0;
}
