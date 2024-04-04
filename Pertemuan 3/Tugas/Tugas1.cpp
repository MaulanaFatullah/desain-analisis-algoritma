#include <iostream>
#include <string>

using namespace std;
const int jumlah_data = 14; // Menyimpan jumlah data yang dimasukkan

class Mahasiswa
{
private:
    string nama[jumlah_data];
    string npm[jumlah_data];

public:
    void setNama(int index, string n)
    {
        nama[index] = n;
    }

    void setNPM(int index, string s)
    {
        npm[index] = s;
    }

    string getNama(int index)
    {
        return nama[index];
    }

    string getNPM(int index)
    {
        return npm[index];
    }
};

int main()
{
    Mahasiswa mhs;

    cout << "Masukkan data mahasiswa (maksimal jumlah_data):" << endl;
    for (int i = 0; i < jumlah_data; ++i)
    {
        string nama, npm;
        cout << "======================================" << endl;
        cout << "Masukkan nama mahasiswa ke-" << i + 1 << ": ";
        getline(cin, nama);
        mhs.setNama(i, nama); // Langsung set nama ke array
        cout << "Masukkan NPM mahasiswa ke-" << i + 1 << ": ";
        getline(cin, npm);
        mhs.setNPM(i, npm); // Langsung set NPM ke array
    }

    cout << "\nData Mahasiswa: \n";
    for (int i = 0; i < jumlah_data; ++i)
    { // Gunakan jumlah_data untuk loop
        cout << "Mahasiswa ke-" << i + 1 << ":" << endl;
        cout << "Nama: " << mhs.getNama(i) << endl;
        cout << "NPM: " << mhs.getNPM(i) << endl;
    }

    return 0;
}
