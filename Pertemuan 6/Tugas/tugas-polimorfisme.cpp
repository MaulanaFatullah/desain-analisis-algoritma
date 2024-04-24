#include <iostream>
#include <string>

using namespace std;

// Base class Mahasiswa
class Mahasiswa {
protected:
    string nama;
    int umur;
    string jurusan;
    string fakultas;

public:
    Mahasiswa(string _nama, int _umur, string _jurusan, string _fakultas)
        : nama(_nama), umur(_umur), jurusan(_jurusan), fakultas(_fakultas) {}

    virtual void displayInfo() {
        cout << "Nama: " << nama << endl;
        cout << "Umur: " << umur << " tahun" << endl;
        cout << "Jurusan: " << jurusan << endl;
        cout << "Fakultas: " << fakultas << endl;
    }

    virtual string getStatus() = 0; // Pure virtual function
};

// Derived class untuk mahasiswa aktif
class MahasiswaAktif : public Mahasiswa {
public:
    MahasiswaAktif(string _nama, int _umur, string _jurusan, string _fakultas)
        : Mahasiswa(_nama, _umur, _jurusan, _fakultas) {}

    void displayInfo() override {
        cout << "Status: Mahasiswa Aktif" << endl;
        Mahasiswa::displayInfo();
    }

    string getStatus() override {
        return "Mahasiswa Aktif";
    }
};

// Derived class untuk alumni
class Alumni : public Mahasiswa {
public:
    Alumni(string _nama, int _umur, string _jurusan, string _fakultas)
        : Mahasiswa(_nama, _umur, _jurusan, _fakultas) {}

    void displayInfo() override {
        cout << "Status: Alumni" << endl;
        Mahasiswa::displayInfo();
    }

    string getStatus() override {
        return "Alumni";
    }
};

int main() {
    int maxMahasiswa;
    cout << "Masukkan jumlah maksimum mahasiswa: ";
    cin >> maxMahasiswa;

    Mahasiswa** daftarMahasiswa = new Mahasiswa*[maxMahasiswa];
    int jumlahMahasiswa = 0;

    string nama, jurusan, fakultas;
    int umur;
    char status;

    while (jumlahMahasiswa < maxMahasiswa) {
        cout << "Masukkan nama: ";
        cin.ignore();
        getline(cin, nama);
        cout << "Masukkan umur: ";
        cin >> umur;
        cout << "Masukkan jurusan: ";
        cin.ignore();
        getline(cin, jurusan);
        cout << "Masukkan fakultas: ";
        cin.ignore();
        getline(cin, fakultas);
        cout << "Masukkan status (A untuk Alumni, M untuk Mahasiswa Aktif): ";
        cin >> status;

        Mahasiswa *mahasiswa;
        if (status == 'A' || status == 'a') {
            mahasiswa = new Alumni(nama, umur, jurusan, fakultas);
        } else if (status == 'M' || status == 'm') {
            mahasiswa = new MahasiswaAktif(nama, umur, jurusan, fakultas);
        } else {
            cout << "Input tidak valid, status default diatur sebagai Mahasiswa Aktif." << endl;
            mahasiswa = new MahasiswaAktif(nama, umur, jurusan, fakultas);
        }

        daftarMahasiswa[jumlahMahasiswa] = mahasiswa;
        jumlahMahasiswa++;
    }

    // Menampilkan informasi semua mahasiswa
    for (int i = 0; i < jumlahMahasiswa; ++i) {
        daftarMahasiswa[i]->displayInfo();
        cout << endl;
    }

    // Membersihkan memori
    for (int i = 0; i < jumlahMahasiswa; ++i) {
        delete daftarMahasiswa[i];
    }

    delete[] daftarMahasiswa;

    return 0;
}
