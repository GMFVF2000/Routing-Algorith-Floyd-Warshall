#include <iostream>
#include "Mtx.h"
#include "Algorithm.h"
#include <sstream>
#include <stdio.h>
#include<queue>
#include<vector>
#include <fstream>
#include <string>
#include<climits>
#define V 10


using namespace std;

// Number of vertices in the graph

/* Define Infinite as a large enough value.This value will be used for vertices not connected to each other */

#define INF 99999

// A function to print the solution matrix

void printSolution(int dist[][V]);

// Solves the all-pairs shortest path
// problem using Floyd Warshall algorithm

void floydWarshall (int graph[][V])

{
    /* dist[][] will be the output matrix that will finally have the shortest distances between every pair of vertices */

    int dist[V][V], i, j, k;

    /* Initialize the solution matrix same as input graph matrix. Or we can say the initial values of shortest distances are based on shortest paths considering no intermediate vertex. */

    for (i = 0; i < V; i++)

        for (j = 0; j < V; j++)

            dist[i][j] = graph[i][j];

    /* Add all vertices one by one to the set of intermediate vertices.
    ---> Before start of an iteration, we have shortest distances between all pairs of vertices such that the shortest distances consider only the vertices in set {0, 1, 2, .. k-1} as
    intermediate vertices.
    ----> After the end of an iteration, vertex no. k is added to the set of intermediate vertices and the set becomes {0, 1, 2, .. k} */

    for (k = 0; k < V; k++)

    {

        // Pick all vertices as source one by one

        for (i = 0; i < V; i++)

        {

            // Pick all vertices as destination for the
            // above picked source

            for (j = 0; j < V; j++)

            {
                // If vertex k is on the shortest path from
                // i to j, then update the value of dist[i][j]

                if (dist[i][k] + dist[k][j] < dist[i][j])

                    dist[i][j] = dist[i][k] + dist[k][j];

            }

        }

    }

    // Print the shortest distance matrix

    printSolution(dist);

}

/* A utility function to print solution */

void printSolution(int dist[][V])

{

    cout<<"The following matrix shows the shortest distances"

          " between every pair of vertices \n";

    for (int i = 0; i < V; i++)

    {

        for (int j = 0; j < V; j++)

        {
            if (dist[i][j] == INF)

                cout<<"INF"<<"     ";

            else

                cout<<dist[i][j]<<"     ";

        }

        cout<<endl;

    }

}

// Driver code

void getch();

using namespace std;

void floyds(int b[][7]) {

    int i, j, k;

    for (k = 0; k < 7; k++) {

        for (i = 0; i < 7; i++) {

            for (j = 0; j < 7; j++) {

                if ((b[i][k] * b[k][j] != 0) && (i != j)) {

                    if ((b[i][k] + b[k][j] < b[i][j]) || (b[i][j] == 0)) {

                        b[i][j] = b[i][k] + b[k][j];

                    }

                }

            }

        }

    }

    for (i = 0; i < 7; i++) {

        cout << "\n Minimum Cost With Respect to Node: " << i << endl;

        for (j = 0; j < 7; j++) {

            cout << b[i][j] << "\t";

        }


    }
}
    int lineValues;

    int AdjMatrix[100][100];

    int parent[100][100];

    int pathfind(int src, int dst) {

        if (src == dst)

            cout << "Path: " << src;

        return 0;

        pathfind(src, parent[src][dst]);

        cout << " " << dst;

    }

// Prints transitive closure of graph[][] using Floyd Warshall algorithm

void transitiveClosure(int graph[][V])
{
    /* reach[][] will be the output matrix that will finally have the
       shortest distances between every pair of vertices */

    int reach[V][V], i, j, k;

    /* Initialize the solution matrix same as input graph matrix. Or
       we can say the initial values of shortest distances are based
       on shortest paths considering no intermediate vertex. */

    for (i = 0; i < V; i++)

        for (j = 0; j < V; j++)

            reach[i][j] = graph[i][j];

    /* Add all vertices one by one to the set of intermediate vertices.
      ---> Before start of a iteration, we have reachability values for
           all pairs of vertices such that the reachability values
           consider only the vertices in set {0, 1, 2, .. k-1} as
           intermediate vertices.
      ----> After the end of a iteration, vertex no. k is added to the
            set of intermediate vertices and the set becomes {0, 1, .. k} */

    for (k = 0; k < V; k++)

    {

        // Pick all vertices as source one by one

        for (i = 0; i < V; i++)

        {

            // Pick all vertices as destination for the
            // above picked source

            for (j = 0; j < V; j++)

            {

                // If vertex k is on a path from i to j,
                // then make sure that the value of reach[i][j] is 1

                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);

            }

        }

    }

    // Print the shortest distance matrix
}

/* A utility function to print solution */

// driver program to test above function
    int main() {

        Mtx matrix = Mtx::fromFile("/home/fortune/CLionProjects/RoutingAlgorithm/Matrice");

        std::cout << matrix.toString() << std::endl;

        //std::cout << Algo::FloydWarshall(matrix).toString() << std::endl;

        int totalnode, node1, node2, weight;

        for (int i = 1; i <= totalnode; i++) {

            int j;

            for (j = 1; j <= totalnode; j++) {

                if (i = j)

                    AdjMatrix[i][j] = 0;

                else

                    AdjMatrix[i][j] = INF;

                parent[i][j] = i;

            }

        }

        while (node1 >> node2 >> weight) {

            AdjMatrix[node1][node2] = weight;

        }

        /*for(int i=1;i<=totalnode;i++)
        {
            for(int j=1;j<=totalnode;j++)
            {
                cout<<AdjMatrix[i][j]<<"   ";
            }
            cout<<endl;
        }
        cout<<endl;
        for(int i=1;i<=totalnode;i++)
        {
            for(int j=1;j<=totalnode;j++)
            {
                cout<<parent[i][j]<<"   ";
            }
            cout<<endl;
        }*/

        for (int k = 1; k <= totalnode; k++) {

            for (int i = 1; i <= totalnode; i++) {

                for (int j = 1; j <= totalnode; j++) {

                    if (AdjMatrix[i][k] * AdjMatrix[k][j] < AdjMatrix[i][j]) {

                        AdjMatrix[i][j] = AdjMatrix[i][k] + AdjMatrix[k][j];

                        parent[i][j] = parent[k][j];

                    }

                }

            }

        };

        int source, dest;

        cout << "Entrer source & destination : ";

        cin >> source >> dest;

        cout << "Distance: " << AdjMatrix[source][dest] << endl;

        pathfind(source, dest);

        int b[7][7];

        cout << "ENTER VALUES OF ADJACENCY MATRIX :\n\n";

        for (int i = 0; i < 7; i++) {

            cout << "enter values for " << (i + 1) << " row" << endl;

            for (int j = 0; j < 7; j++) {

                cin >> b[i][j];

            }

        }

        floyds(b);

        /* Let us create the following weighted graph
                   10
              (0)------->(3)
               |         /|\
             5 |          |
               |          | 1
              \|/         |
              (1)------->(2)
                   3           */

        int graph[V][V] = {{0,   5,   INF, 10},
                           {INF, 0,   3, INF},
                           {INF, INF, 0,   1},
                           {INF, INF, INF, 0}
        };

        // Print the solution

    transitiveClosure(graph);
    floydWarshall(graph);

        // Program to print BFS traversal from a given
// source vertex. BFS(int s) traverses vertices
// reachable from s.

        return 0;

    }

