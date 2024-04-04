#include <iostream>
#include <string>
#include <set>

using namespace std;

class Mahasiswa {
public:
    // Constructor
    Mahasiswa() {}

    // Setter untuk menambahkan nama dan NPM ke dalam set
    void TambahMahasiswa(string nama, int npm) {
        data_mahasiswa.insert({nama, npm});
    }

    // Getter untuk mendapatkan set nama
    set<pair<string, int>> GetDataMahasiswa() {
        return data_mahasiswa;
    }

    void TampilkanBiodata() {
        cout << endl << "Informasi Mahasiswa:" << endl;
        int i = 1;
        for (const auto& data : data_mahasiswa) {
            string nama_mahasiswa = data.first;
            int npm_mahasiswa = data.second;

            cout << "Mahasiswa ke-" << i << ":" << endl;
            cout << "  Nama: " << nama_mahasiswa << endl;
            cout << "  NPM: " << npm_mahasiswa << endl;
            ++i;
        }
    }

private:
    // Data member
    set<pair<string, int>> data_mahasiswa; // Set untuk menyimpan data mahasiswa
};

int main() {
    Mahasiswa mhs;

    cout << "Masukkan data mahasiswa (maksimal 14):" << endl;
    for (int i = 0; i < 5; ++i) {
        string nama;
        int npm;
        cout << "======================================" << endl;
        cout << "Masukkan nama mahasiswa ke-" << i + 1 << ": ";
        getline(cin, nama);
        cout << "Masukkan NPM mahasiswa ke-" << i + 1 << ": ";
        cin >> npm;
        cin.ignore(); // Membersihkan newline dari buffer input
        mhs.TambahMahasiswa(nama, npm);
    }

    mhs.TampilkanBiodata();

    return 0;
}
