#include <iostream>
#include <string>

using namespace std;

class Mahasiswa {
private:
    string nama;
    string npm;

public:
    void setNama(string n) {
        nama = n;
    }

    void setNPM(string s) {
        npm = s;
    }

    string getNama() {
        return nama;
    }

    string getNPM() {
        return npm;
    }
};

int main() {
    Mahasiswa Mahasiswa;

    string nama, npm;

    cout << "Masukkan nama Mahasiswa: ";
    getline(cin, nama);
    Mahasiswa.setNama(nama);

    cout << "Masukkan NPM Mahasiswa: ";
    getline(cin, npm);
    Mahasiswa.setNPM(npm);

    cout << "\nData Mahasiswa: \n";
    cout << "Nama: " << Mahasiswa.getNama() << endl;
    cout << "NPM: " << Mahasiswa.getNPM() << endl;

    return 0;
}
