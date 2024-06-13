#include <iostream>
#include <vector>
#include <queue>

#define M 1000

using namespace std;

const int N = 5;

void djikstra(int graph[N][N], int source, int destination)
{
    vector<pair<int, int>> adj[N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (graph[i][j] != M)
            {
                adj[i].push_back(make_pair(j, graph[i][j]));
            }
        }
    }

    int Q[N], R[N];
    for (int i = 0; i < N; i++)
    {
        Q[i] = M;
        R[i] = -1;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, source - 1));
    Q(source - q) = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        
    }
    
}