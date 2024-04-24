#include <iostream>
using namespace std;

class Mahasiswa
{
private:
    string nama;
    int usia;
    float ipk;
    int size;

public:
    void setNama(string a);
    void setUsia(int b);
    void setIPK(float c);
    string getNama();
    int getUsia();
    float getIPK();
};

void Mahasiswa::setNama(string a)
{
    nama = a;
}

void Mahasiswa::setUsia(int b)
{
    usia = b;
}

void Mahasiswa::setIPK(float c)
{
    ipk = c;
}

string Mahasiswa::getNama()
{
    return nama;
}

int Mahasiswa::getUsia()
{
    return usia;
}

float Mahasiswa::getIPK()
{
    return ipk;
}

int main()
{
    int size;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> size;
	cout << endl;

	Mahasiswa ms[size];

    for (int i = 0; i < size; i++)
    {
        string nama;
        int usia;
        float ipk;

        cin.ignore(); // to clear the newline character left in the input buffer
        cout << "Nama: ";
        getline(cin, nama);
        cout << "Usia: ";
        cin >> usia;
        cout << "IPK: ";
        cin >> ipk;
		cout << "------------------------------" << endl;
		ms[i].setNama(nama);
        ms[i].setUsia(usia);
        ms[i].setIPK(ipk);
    }

	cout << "Data Mahasiswa: " << endl;
	for (int i = 0; i < size; i++)
    {
		cout << "No: " << i + 1 << endl;
		cout << "\tNama: " << ms[i].getNama() << endl;
        cout << "\tUsia: " << ms[i].getUsia() << endl;
        cout << "\tIPK: " << ms[i].getIPK() << endl;
    }

    return 0;
}
