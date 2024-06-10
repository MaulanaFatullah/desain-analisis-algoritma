#include <iostream>
#include <vector>

using namespace std;

class Graph
{
private:
    vector<vector<int>> adjList;

public:
    Graph(const vector<vector<int>> &adjList) : adjList(adjList)
    {
    }

    void displayAdjacencyList() const
    {
        cout << "Daftar Ketetanggaan (Graf tidak berarah): \n\n";
        for (int i = 0; i < adjList.size(); ++i)
        {
            cout << "Simpul " << i << ": -> ";
            bool firstNeighbor = true;
            for (int j = 0; j < adjList[i].size(); ++j)
            {
                int neighbor = adjList[i][j];
                if (firstNeighbor)
                {
                    firstNeighbor = false;
                }
                else
                {
                    cout << "-> ";
                }
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    vector<vector<int>> adjList = {
        {1, 4},
        {0, 2, 3, 4},
        {1, 3},
        {1, 2, 4},
        {0, 1, 3}};

    Graph graph(adjList);

    graph.displayAdjacencyList();

    return 0;
}
