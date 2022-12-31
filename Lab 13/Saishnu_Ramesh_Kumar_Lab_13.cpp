/* 
*   This program deals with the Dijkstra Algorithm.
*   Done By: Saishnu Ramesh Kumar
*   Student ID: 300758706
*
*/

#include <iostream>
#include <limits.h>
#include <climits>

using namespace std;

#define V 9 //Macro

//Function Prototypes
int minDistance(int dist[], bool spt[]);
void dijkstra(int graph[V][V], int src);
void print(int dist[]);

// MinDistance Function
int minDistance(int dist[], bool spt[]){

    int min = INT_MAX, minIndex;

    for(int v = 0; v < V; v++){
        if(spt[v] == false && dist[v] <= min){
            min = dist[v], minIndex = v;
        }
    }
    return minIndex;
}

//Dijkstra Function
void dijkstra(int graph[V][V], int src){
    
    int dist[V];

    bool spt[V];

    for(int i = 0; i < V; i++){
        dist[i] = INT_MAX, spt[i] = false;
    }

    dist[src] = 0;

    for(int count = 0; count < V - 1; count++){

        int u = minDistance(dist, spt);

        spt[u] = true;

        for(int v = 0; v < V; v++){

            if(!spt[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]){
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    print(dist);
}

//Print Function
void print(int dist[]){

    cout<<"Vertex \t Distance from Source Vertex" <<endl;
    for(int i = 0; i < V; i++){
        cout<< i <<" \t\t" << dist[i] << endl;
    }
}

//Main Function
int main(){

    int graph[V][V] = {
                       {0, 4, 0, 1, 0, 2, 0, 7, 0},
                       {5, 1, 8, 0, 0, 0, 0, 2, 0},
                       {0, 5, 0, 1, 0, 4, 7, 0, 2},
                       {0, 22, 7, 0, 9, 4, 0, 6, 16},
                       {0, 1, 0, 9, 0, 10, 0, 0, 0},
                       {0, 8, 4, 15, 9, 0, 22, 0, 0},
                       {15, 1, 0, 0, 0, 3, 0, 31, 26},
                       {8, 1, 0, 0, 0, 0, 41, 0, 17},
                       {1, 0, 12, 0, 5, 0, 0, 7, 0}
    };

    dijkstra(graph, 0);

    return 0;
}