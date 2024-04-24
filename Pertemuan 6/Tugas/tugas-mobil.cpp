#include <iostream>
using namespace std;

class Kendaraan
{
protected:
    string merek;
    int tahunProduksi, jumlahPintu;

public:
    Kendaraan(string _merek, int _tahunProduksi, int _jumlahPintu)
        : merek(_merek), tahunProduksi(_tahunProduksi), jumlahPintu(_jumlahPintu) {}

    // Definisi
    virtual void info()
    {
        cout << "\n--Data Kendaraan--" << endl;
        cout << "Merek: " << merek << endl;
        cout << "Tahun Produksi: " << tahunProduksi << endl;
    }
};

class Mobil : public Kendaraan
{
public:
    Mobil(string _merek, int _tahunProduksi, int _jumlahPintu) : Kendaraan(_merek, _tahunProduksi, _jumlahPintu) {}

    void info()
    {
        Kendaraan::info();
        cout << "Jumlah Pintu: " << jumlahPintu << endl;
    }
};

int main()
{
    string merekMobil;
    int tahunProduksiMobil, jumlahPintuMobil;

    cout << "Program Input Data Kendaraan\n";
    cout << "=============================\n";
    cout << "Masukkan merek kendaraan: ";
    getline(cin, merekMobil);
    cout << "Masukkan tahun produksi: ";
    cin >> tahunProduksiMobil;
    cout << "Masukkan jumlah pintu: ";
    cin >> jumlahPintuMobil;

    Mobil mobil(merekMobil, tahunProduksiMobil, jumlahPintuMobil);
    mobil.info();
    return 0;
}
