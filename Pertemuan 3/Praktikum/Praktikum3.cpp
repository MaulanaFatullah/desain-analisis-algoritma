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
    Mahasiswa mhs;

    string nama, npm;

    cout << "Masukkan nama Mahasiswa: ";
    getline(cin, nama);
    mhs.setNama(nama);

    cout << "Masukkan NPM Mahasiswa: ";
    getline(cin, npm);
    mhs.setNPM(npm);

    cout << "\nData Mahasiswa: \n";
    cout << "Nama: " << mhs.getNama() << endl;
    cout << "NPM: " << mhs.getNPM() << endl;

    return 0;
}
