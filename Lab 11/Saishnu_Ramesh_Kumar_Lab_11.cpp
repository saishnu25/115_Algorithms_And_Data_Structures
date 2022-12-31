/* 
*
*   This program deals with Depth and Breath First Search
*   Done By: Saishnu Ramesh Kumar
*   Student ID: 300758706
*
*/
#include <iostream>
#include <vector>
#include <list>

using namespace std;

//Depth First Search Class
class DepthFirstSearch{

    int U; // Vertices
    list<int> *adj; // Store adjacency lists

    //DFS_Util Function
    void DFS_Util(int u, bool visited[]){
        visited[u] = true; // Mark it as true and print it out
        cout << u << " ";  

        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i){
            if (!visited[*i]){ // If the adjacent node is not visited
                DFS_Util(*i, visited); // Recursively explore as deep as possible
            }
        }
    }

    public:
        //Constructor
        DepthFirstSearch(int U){
            this->U = U;
            adj = new list<int>[U];
        }

        //addEdge Function
        void addEdge(int u, int v){
            adj[u].push_back(v); // Adding v to u's list
        }

        //DFS Function
        void DFS(int u){
            bool *visited = new bool[U];
            for (int i = 0; i < U; i++){
                visited[i] = false; // Mark all vertices as NOT visited
            }
            DFS_Util(u, visited); // Traverse the graph recursively
        }
};

//Breath First Search Class
class BreadthFirstSearch{

    int U; // Vertices
    list<int> *adj; // Vector to store adjacents

    public:
        //Constructor
        BreadthFirstSearch(int U){ 
            this->U = U;
            adj = new list<int>[U];
        }

        //addEdge Function
        void addEdge(int u, int v){
            adj[u].push_back(v); // Push v into u's list
        }

        //BFS Function
        void BFS(int u){
            bool *visited = new bool[U];
            for (int i = 0; i < U; i++){
                visited[i] = false; // Mark all vertices as not visited first
            }
            list<int> queue;    // Create a queue for BFS
            visited[u] = true;  // Mark as visited
            queue.push_back(u); // Enqueue the node

            list<int>::iterator i;
            while (!queue.empty()){
                u = queue.front();
                cout << u << " ";
                queue.pop_front(); // Dequeue the vertex from queue

                for (i = adj[u].begin(); i != adj[u].end(); ++i){
                    if (!visited[*i]){ // Push the adjacents of vertices into the queue
                        visited[*i] = true; // Repeat until the last vertex
                        queue.push_back(*i);
                    }
                }
            }
        }
};

//Main Function
int main(){
    int n = 10; //Max size of 10

    //DFS
    DepthFirstSearch d(n);
    d.addEdge(0, 1);
    d.addEdge(0, 2);
    d.addEdge(1, 3);
    d.addEdge(1, 2);
    d.addEdge(2, 0);
    d.addEdge(2, 3);
    d.addEdge(3, 5);
    d.addEdge(1, 7);
    d.addEdge(6, 8);
    d.addEdge(8, 9);
    d.addEdge(7, 5);
    cout<<"Depth First Search Output: ";
    d.DFS(1);
    cout<<endl;

    //BFS
    BreadthFirstSearch b(n);
    b.addEdge(0, 1);
    b.addEdge(0, 2);
    b.addEdge(1, 3);
    b.addEdge(1, 2);
    b.addEdge(2, 0);
    b.addEdge(2, 3);
    b.addEdge(3, 5);
    b.addEdge(1, 7);
    b.addEdge(6, 8);
    b.addEdge(8, 9);
    b.addEdge(4, 3);
    cout<<"Breath First Search Output: ";
    b.BFS(1);
    cout<<endl;

    return 0;
}