#include <iostream>
using namespace std;
#include <limits.h>

#define Node 9

int minDistance(int dist[], bool sptSet[])
{

    int min = 99999, min_index;

    cout << "\n++++++++++++++++++++++++++++++++++++++++\n";

    for (int v = 0; v < Node; v++)
    {
            
            cout << "\n" << dist[v] << " <= " << min << endl;
        if (sptSet[v] == false && dist[v] <= min)
        {
            // cout << "\ndist[v]: " << dist[v] << "\n\n";

            min = dist[v];
            min_index = v;

            cout << "\nmin: " << min;
        }
    }
    cout << "\n\nlatest min: " << min << ", min_index: " << min_index << endl;
    return min_index;
}

void printResult(int dist[])
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < Node; i++)
        cout << i << " \t\t\t\t" << dist[i] << endl;
}

void dijkstra(int graph[Node][Node], int src)
{
    int dist[Node];

    bool sptSet[Node];

    for (int i = 0; i < Node; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0;


    for (int count = 0; count < Node; count++)
    {

        int u = minDistance(dist, sptSet);


        sptSet[u] = true;
        cout << "<sptSet[" << u << "]" << ": True>" << endl;
        for (int v = 0; v < Node; v++)
        {
            // graph[u][v] untuk memeriksa apakah ada edge yang memiliki bobot, jika bobot 0 maka tidak memenuhi kondisi
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                cout << "dist[" << u << "]" << " + " << "graph[" << u << "][" << v << "]" << " = " << dist[u] + graph[u][v] << endl;

                cout << "Jika, " << endl;
                cout << dist[u] << " + " << graph[u][v] << " = " << dist[u] + graph[u][v] << endl;
                cout << " kurang dari" << endl;
                cout << "dist[v]: " << dist[v] << endl
                     << endl;

                dist[v] = dist[u] + graph[u][v];

                cout << "ubah dist[v] menjadi -> " << dist[v] << endl
                     << endl;
                cout << "\n---------------------------------\n";
            }
        }
    }

    printResult(dist);
}

int main()
{
    int graph[Node][Node] = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    dijkstra(graph, 0);

    return 0;
}
