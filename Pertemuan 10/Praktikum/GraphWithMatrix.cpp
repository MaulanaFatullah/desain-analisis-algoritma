#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100;

int graph[MAX][MAX];
int n;

void addEdge(int x, int y)
{
    graph[x][y] = 1;
    graph[y][x] = 1;
}

void displayGraph()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << graph[i][j] << " ";
        }

        cout << endl;
    }
}

int main()
{
    cout << "Masukkan jumlah dimensi array: ";
    cin >> n;

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(2, 3);

    displayGraph();

    return 0;
}