#include <iostream>
#include <vector>

using namespace std;

class Graph
{
private:
  vector<vector<int>> adjList;

public:
  Graph(const vector<vector<int> > &adjList)
  {
    this->adjList = adjList;
  }

  void displayAdjacencyList() const
  {
    cout << "Daftar Ketetanggaan (Graf berarah): \n\n";
    for (int i = 0; i < adjList.size(); ++i)
    {
      cout << "Simpul " << i << ": ";

      for (int neighbor : adjList[i])
      {
        cout << "-> ";
        if (neighbor != -1)
        {
          cout << neighbor << " ";
        }
      }
      cout << endl;
    }
  }
};

int main()
{

  vector<vector<int>> adjList = {
      {1, 4},
      {2, 3, 4},
      {3},
      {4},
      {}};

  Graph graph(adjList);

  graph.displayAdjacencyList();

  return 0;
}
