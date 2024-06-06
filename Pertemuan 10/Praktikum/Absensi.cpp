#include <iostream>
#include <vector>

using namespace std;

class Graph
{
private:
    int jumlahSimpul;// Jumlah Simpul dalam graf
    vector<vector<int> > matriksKetetanggaan; // Matriks ketetanggaan

public:
    Graph(int simpul): jumlahSimpul(simpul){
        // Inisialisasi matriks ketetanggaan dengan nol
        for (int i = 0; i < simpul; i++)
        {
            // vector<vector<int> > baris(simpul, 0);
            vector<int> baris(simpul, 0);
            matriksKetetanggaan.push_back(baris);
            // vector<baris<simpul, 0>>;
        }
    }

    void tambahSisi(int u, int v)
    {
        if (u >= 0 && u < jumlahSimpul && v >= 0 && v < jumlahSimpul)
        {
            
            matriksKetetanggaan[u][v] = 1;
            matriksKetetanggaan[v][u] = 1; // For undirected graph
        } else {
            cout << "Sisi tidak valid!" << endl;
        }
    }

    // Menghapus sisi (edge) dari graf
    void hapusSisi(int u, int v)
    {
        if (u >= 0 && u < jumlahSimpul && v >= 0 && v < jumlahSimpul)
        {
            matriksKetetanggaan[u][v] = 0;
            matriksKetetanggaan[v][u] = 0; // For undirected graph
        }
        else
        {
            cout << "Sisi tidak valid!";
        }
    }

    // Menampilkan matriks ketetanggaan
    void tampilkan()
    {
        for (int i = 0; i < jumlahSimpul; i++)
        {
            for (int j = 0; j < jumlahSimpul; j++)
            {
                cout << matriksKetetanggaan[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int simpul = 5;
    Graph j(simpul);

    j.tambahSisi(0, 1);
    j.tambahSisi(0, 4);
    j.tambahSisi(1, 2);
    j.tambahSisi(1, 4);
    j.tambahSisi(2, 3);
    j.tambahSisi(3, 4);

    // Menampilkan matriks ketetanggaan
    cout << "Matriks Ketetanggaan: " << endl;
    j.tampilkan();

    j.hapusSisi(1, 2);
    cout << "Matriks Ketetanggaan setelah menghapus sisi antara 1 dan 2: " << endl;
    j.tampilkan();

    return 0;
}
