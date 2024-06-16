#include <iostream>
using namespace std;
#include <limits.h>

#define Node 6

int minDistance(int dist[], bool sptSet[])
{

    int min = INT_MAX, min_index;
    for (int v = 0; v < Node; v++)
    {
        if (sptSet[v] == false && dist[v] <= min)
        {
            min = dist[v], min_index = v;
        }
    }
    return min_index;
}

void printResult(int dist[])
{
    cout << "Jarak Terpendek ke setiap simpul: \n" << endl;
        cout << "Simpul \t Simpul 1 ke Simpul 2-6" << endl;
    for (int i = 0; i < Node; i++)
        cout << i+1 << " \t\t\t\t" << dist[i] << endl;
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

        for (int v = 0; v < Node; v++)
        {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printResult(dist);
}

int main()
{
    int graph[Node][Node] = {
        {0,  7,  9,  0,  0, 14},
        {7,  0,  10, 15, 0, 0},
        {9,  10, 0,  11, 0, 2},
        {0,  15, 11, 0,  6, 0},
        {0,  0,  0,  6,  0, 9},
        {14, 0,  2,  0, 9, 0}};

    dijkstra(graph, 0);

    return 0;
}
