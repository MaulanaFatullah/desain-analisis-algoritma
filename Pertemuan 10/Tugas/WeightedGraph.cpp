#include <iostream>
#include <vector>

using namespace std;

struct Edge
{
  int neighbor;
  int weight;
};

class Graph
{
private:
  vector<vector<Edge> > adjList;

public:
  Graph(const vector<vector<Edge>> &adjList)
  {
    this->adjList = adjList;
  }

  void displayAdjacencyList() const
  {
    cout << "Daftar Ketetanggaan (Weighted Graph): \n\n";
    for (int i = 0; i < adjList.size(); ++i)
    {
      cout << "Simpul " << i << ": ";
      bool firstNeighbor = true;
      for (const Edge &edge : adjList[i])
      {
        if (firstNeighbor)
        {

          firstNeighbor = false;
        }
        else
        {
          cout << "-> ";
        }
        if (edge.weight != -1)
        {
          cout << "(" << edge.neighbor << ", " << edge.weight << ") ";
        }
      }
      cout << endl;
    }
  }
};

int main()
{

  vector<vector<Edge>> adjList = {
      {{1, 10}, {4, 20}},
      {{2, 30}, {3, 40}, {4, 50}},
      {{3, 60}},
      {{4, 70}},
      {}};

  Graph graph(adjList);

  graph.displayAdjacencyList();

  return 0;
}
