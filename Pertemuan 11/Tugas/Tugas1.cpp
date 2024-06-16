#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Graph
{
public:
    vector<vector<int>> adj_matrix;
    vector<char> vertex_data;
    int size;

    Graph(int size)
    {
        this->size = size;
        adj_matrix.resize(size, vector<int>(size, 0));
        vertex_data.resize(size);
    }

    void tambahBobot(int u, int v, int bobot)
    {
        if (u >= 0 && u < size && v >= 0 && v < size)
        {
            adj_matrix[u][v] = bobot;
            adj_matrix[v][u] = bobot; // untuk graph tidak berarah
        }
    }

    void tambahDataSimpul(int vertex, char data)
    {
        if (vertex >= 0 && vertex < size)
        {
            vertex_data[vertex] = data;
        }
    }
};

void dijkstra(Graph &g, int simpul_awal, vector<int> &jarak, vector<int> &predecessors)
{
    vector<bool> visited(g.size, false);
    jarak.assign(g.size, INT_MAX);
    predecessors.assign(g.size, -1);
    jarak[simpul_awal] = 0;

    for (int count = 0; count < g.size - 1; count++)
    {
        int min = INT_MAX, min_index = -1;

        for (int v = 0; v < g.size; v++)
        {
            if (!visited[v] && jarak[v] <= min)
            {
                min = jarak[v];
                min_index = v;
            }
        }

        if (min_index == -1)
            break; // tidak lagi ada simpul yang diproses

        int u = min_index;
        visited[u] = true;

        for (int v = 0; v < g.size; v++)
        {
            if (!visited[v] && g.adj_matrix[u][v] && jarak[u] != INT_MAX &&
                jarak[u] + g.adj_matrix[u][v] < jarak[v])
            {
                jarak[v] = jarak[u] + g.adj_matrix[u][v];
                predecessors[v] = u;
            }
        }
    }
}

void printOut(Graph &g, const vector<int> &predecessors, int simpul_awal, int simpul_akhir)
{
    vector<int> stack;
    int current = simpul_akhir;
    while (current != -1)
    {
        stack.push_back(current);
        current = predecessors[current];
    }
}

int get_vertex_index(char vertex)
{
    switch (vertex)
    {
    case 'A':
    case 'a':
        return 0;
    case 'B':
    case 'b':
        return 1;
    case 'C':
    case 'c':
        return 2;
    case 'D':
    case 'd':
        return 3;
    case 'E':
    case 'e':
        return 4;
    case 'F':
    case 'f':
        return 5;
    default:
        return -1;
    }
}

int main()
{
    Graph g(6);

    g.tambahDataSimpul(0, 'A');
    g.tambahDataSimpul(1, 'B');
    g.tambahDataSimpul(2, 'C');
    g.tambahDataSimpul(3, 'D');
    g.tambahDataSimpul(4, 'E');
    g.tambahDataSimpul(5, 'F');

    g.tambahBobot(0, 1, 1); // A - B, bobot 1
    g.tambahBobot(0, 2, 2); // A - C, bobot 2
    g.tambahBobot(1, 3, 5); // B - D, bobot 5
    g.tambahBobot(1, 4, 1); // B - E, bobot 1
    g.tambahBobot(2, 3, 2); // C - D, bobot 2
    g.tambahBobot(3, 4, 2); // D - E, bobot 2
    g.tambahBobot(3, 5, 2); // D - F, bobot 2
    g.tambahBobot(4, 5, 1); // E - F, bobot 1

    cout << "Representasi Matriks: \n";
    cout << "\t A -1- B\n";
    cout << "\t |     |  \\\n";
    cout << "\t2|     5   1\n";
    cout << "\t |     |    \\\n";
    cout << "\t C -2- D -2- E\n";
    cout << "\t        |    /\n";
    cout << "\t        2   1\n";
    cout << "\t        | /\n";
    cout << "\t        F\n";

    vector<int> jarak(g.size);
    vector<int> predecessors(g.size);
    char sumber, tujuan;
    cout << "Masukkan simpul asal (A-F): ";
    cin >> sumber;
    cout << "Masukkan simpul tujuan (A-F): ";
    cin >> tujuan;

    int simpul_awal = get_vertex_index(sumber);
    int simpul_akhir = get_vertex_index(tujuan);

    if (simpul_awal == -1 || simpul_akhir == -1)
    {
        cout << "Invalid vertex" << endl;
        return 1;
    }

    dijkstra(g, simpul_awal, jarak, predecessors);

    cout << "Jarak dari simpul " << sumber << " ke simpul " << tujuan << " adalah ";

    printOut(g, predecessors, simpul_awal, simpul_akhir);
    cout << jarak[simpul_akhir] << endl;

    return 0;
}
