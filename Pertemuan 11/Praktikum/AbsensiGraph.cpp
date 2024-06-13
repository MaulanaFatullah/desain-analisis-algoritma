#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
    int jumlahSimpul;
    vector<vector<int> > adjList;

public:
    Graph(int simpul);
    void tambahkanTepi(int src, int dest);
    void cetakGraf();
};

Graph::Graph(int simpul) {
    jumlahSimpul = simpul;
    adjList.resize(simpul);
}

void Graph::tambahkanTepi(int src, int dest) {
    adjList[src].push_back(dest);
    adjList[dest].push_back(src); // Untuk graf tak berarah
}

void Graph::cetakGraf() {
    for (int i = 0; i < jumlahSimpul; ++i) {
        cout << "Simpul " << i << ": ";
        for (size_t j = 0; j < adjList[i].size(); ++j) {
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    Graph g(5);
    queue<pair<int, int> > edges;

    edges.push(make_pair(0, 1));
    edges.push(make_pair(0, 4));
    edges.push(make_pair(1, 2));
    edges.push(make_pair(1, 3));
    edges.push(make_pair(1, 4));
    edges.push(make_pair(2, 3));
    edges.push(make_pair(3, 4));

    while (!edges.empty()) {
        pair<int, int> edge = edges.front();  // Menggunakan tipe data eksplisit
        g.tambahkanTepi(edge.first, edge.second);
        edges.pop();
    }

    cout << "Graf dengan daftar adjasi:" << endl;
    g.cetakGraf();

    return 0;
}