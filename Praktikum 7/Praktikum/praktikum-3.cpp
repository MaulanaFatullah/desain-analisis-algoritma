#include <iostream>
#include <string>
using namespace std;

class Barang
{
    string namaBarang;
    int hargaBarang;

public:
    Barang(string _namaBarang, int _hargaBarang) : namaBarang(_namaBarang), hargaBarang(_hargaBarang) {}

    void display()
    {
        cout << "Barang " << namaBarang << " ditemukan dengan harga "
             << "Rp. " << hargaBarang << endl;
    }
    string getNamaBarang() const
    {
        return namaBarang;
    }
};

int main()
{
    int n = 5;
    string namaBarang;
    char lanjut;
    Barang daftarBarang[5] = {
        {"Buku", 5000},
        {"Pensil", 1000},
        {"Pulpen", 2000},
        {"Penghapus", 500},
        {"Penggaris", 1500}};

    do
    {
        bool ketemu = false;
        cout << "Masukkan nama barang: ";
        cin >> namaBarang;
        for (int i = 0; i < n; i++)
        {
            if (daftarBarang[i].getNamaBarang() == namaBarang)
            {
                ketemu = true;
                daftarBarang[i].display();
                break;
            }
        }

        if (!ketemu)
        {
            cout << "Barang tidak ditemukan." << endl;
        }
        cout << "\nCari lagi? Y/t" << endl;
        cin >> lanjut;
    } while (lanjut == 'Y' || lanjut == 'y');
    return 0;
}
