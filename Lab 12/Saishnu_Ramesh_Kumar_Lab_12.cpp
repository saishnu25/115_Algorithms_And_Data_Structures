/* 
*   This program deals with Prim's and Kruskal's Algorithm.
*   Done By: Saishnu Ramesh Kumar
*   Student ID: 300758706
*
*/
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define V 5 //Macro

// -- Prim's algorithm --
//Create MST Function
bool createMST(int u, int v, vector<bool> inMST){
    if (u == v){
        return false;
    }
    if (inMST[u] == false && inMST[v] == false){
        return false;
    }
    else if (inMST[u] == true && inMST[v] == true){
        return false;
    }
    return true;
}

// Prim MST Function
void primsMST(int cost[][V]){
    vector<bool> inMST(V, false);
    inMST[0] = true;
    int edge = 0;
    int MSTcost = 0;

    while (edge < V - 1){
        int min = INT_MAX, a = -1, b = -1;
        for (int i = 0; i < V; i++){
            for (int j = 0; j < V; j++){
                if (cost[i][j] < min){
                    if (createMST(i, j, inMST)){
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        if (a != -1 && b != -1){
            cout << "Edge " << edge++ << " : (" << a << "," << b << "):cost = " << min << endl;
            MSTcost += min;
            inMST[b] = inMST[a] = true;
        }
    }
    cout << "Total Cost of MST: " << MSTcost;
}

//-- Kruskal's algorithm --
int parent[V];

//Find Function
int find(int i){
    while (parent[i] != i){
        i = parent[i];
    }
    return i;
}

//Uni Function
void uni(int i, int j){
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

//Kruskal MST Function
void kruskalMST(int cost[][V]){
    int MSTcost = 0;

    for (int i = 0; i < V; i++){
        parent[i] = i;
    }

    int edge = 0;
    while (edge < V - 1){
        int min = INT_MAX, a = -1, b = -1;

        for (int i = 0; i < V; i++){
            for (int j = 0; j < V; j++){
                if (find(i) != find(j) && cost[i][j] < min){
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        uni(a, b);
        cout << "Edge " << edge++ << " : (" << a << "," << b << "):cost = " << min << endl;
        MSTcost += min;
    }
    cout << "Total cost of MST: " << MSTcost << endl;
}

//Main Function
int main(){

    int graph[][V] = {
        {INT_MAX, 15, INT_MAX, 25, INT_MAX},
        {12, INT_MAX, 11, 8, 12},
        {INT_MAX, 11, INT_MAX, INT_MAX, 16},
        {25, 8, INT_MAX, INT_MAX, 15},
        {INT_MAX, 12, 20, 15, INT_MAX},
    };

    cout << "Prim's algorithm: " << endl;
    primsMST(graph);
    cout << "\n" << endl;

    cout << "Kruskal's algorithm: " << endl;
    kruskalMST(graph);
}