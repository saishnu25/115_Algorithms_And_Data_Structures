/* 
*
*       This program deals with Dynamic Programming
*       Done By: Saishnu Ramesh Kumar
*       Student ID: 300758706
*
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#define INF 99999999

//Function Prototypes
int matrixChainOrder(int p[], int n);
void printOptParens(int i, int j, int n, int *DP, char &name);

//Matrix Chain Order Function
int matrixChainOrder(int p[], int n){

    int m[n][n];
    int DP[n][n];

    for (int i = 1; i < n; i++){
        m[i][i] = 0;
        DP[i][i] = 0;
    }

    for (int S = 2; S < n; S++){

        for (int i = 1; i < n - S + 1; i++){

            int j = i + S - 1;
            m[i][j] = INF;
            // Finding the breakpoint such that the cost is minimum
            for (int k = i; k <= j - 1; k++){

                // Cost of multiplying two matrices
                int cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < m[i][j]){
                    m[i][j] = cost;
                    DP[i][j] = k;
                }
            }
        }
    }

    // First matrix is A, next B and etc...
    char name = 'A';
    printOptParens(1, n - 1, n, (int *)DP, name);
    return m[1][n - 1];
}

//Print Opt Parents Function
void printOptParens(int i, int j, int n, int *DP, char &name){

    if (i == j){
        std::cout << name++;
        return;
    }

    std::cout << "(";
    int x = *((DP + i * n) + j);
    //Recursion call of the function
    printOptParens(i, x, n, DP, name);
    printOptParens(x + 1, j, n, DP, name);
    std::cout << ")";
    std::cout << " ";
}

//Main Function
int main(){
    
    int n;
    std::cout << "Enter number of matrices : ";
    std::cin >> n;
    n += 1; // Chain contains n + 1 of the items
    int p[n];
    std::cout << "Enter numbers for the array chain:\n";
    for (int i = 0; i < n; i++){
        std::cin >> p[i];
    }

    std::cout << "\nOptimal Parenthesization and Cost: " << matrixChainOrder(p, n) << std::endl;
}
