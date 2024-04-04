#include <iostream>
#include <string>

using namespace std;

class Mahasiswa {
public:
    // Constructor
    Mahasiswa(string nama[], int jumlah) {
        // Menyimpan semua nama yang diinput ke dalam variabel nama_
        for (int i = 0; i < jumlah; ++i) {
            nama_[i] = nama[i];
        }
        jumlah_ = jumlah;
    }

    void TampilkanBiodata() {
        cout << endl << "Informasi Kontak:" << endl;
        // Menampilkan semua nama yang disimpan dalam variabel nama_
        for (int i = 0; i < jumlah_; ++i) {
            cout << "Nama kontak ke-" << i + 1 << ": " << nama_[i] << endl;
        }
    }

private:
    // Data member
    string nama_[14]; // Array untuk menyimpan nama
    int jumlah_; // Menyimpan jumlah nama yang diinput
};

int main() {
    string nama[14]; // Array untuk menyimpan input nama
    int jumlahNama;

    cout << "Masukkan nama kontak (maksimal 14):" << endl;
    for (jumlahNama = 0; jumlahNama < 14; ++jumlahNama) {
        cout << "Masukkan nama kontak ke-" << jumlahNama + 1 << ": ";
        getline(cin, nama[jumlahNama]);

    }

    Mahasiswa mhs(nama, jumlahNama); // Menggunakan array nama dan jumlah nama yang diinput
    mhs.TampilkanBiodata();

    return 0;
}
