#include <iostream>
#include <string>
#include <limits> // Menambahkan header ini untuk membersihkan newline di buffer

using namespace std;

class Mahasiswa {
public:
    // Constructor
    Mahasiswa(string nama, int umur, string alamat) {
        nama_ = nama;
        umur_ = umur;
        alamat_ = alamat;
    }

    void TampilkanBiodata() {
        cout << "======================" << endl;
        cout << "Informasi Biodata:" << endl;
        cout << "Nama: " << nama_ << endl;
        cout << "Umur: " << umur_ << endl;
        cout << "Alamat: " << alamat_ << endl;
    }

private:
    // Data member
    string nama_;
    int umur_;
    string alamat_;
};

int main() {
    string nama, alamat;
    int umur;
    
    cout << "Masukkan nama: ";
    getline(cin, nama);
    
    cout << "Masukkan umur: ";
    cin >> umur;
    
    // Membersihkan newline di buffer input
    cin.ignore();
    
    cout << "Masukkan alamat: ";
    getline(cin, alamat);

    Mahasiswa mhs(nama, umur, alamat);
    mhs.TampilkanBiodata();

    return 0;
}

