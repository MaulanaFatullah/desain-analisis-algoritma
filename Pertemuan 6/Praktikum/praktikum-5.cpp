#include <iostream>
using namespace std;

class Mahasiswa
{
private:
	string nama[100];
	int usia[100];
	float ipk[100];

public:
// Setter
	void setNama(string n, int index)
	{
		nama[index] = n;
	}

	void setUsia(int u, int index)
	{
		usia[index] = u;
	}

	void setIPK(float i, int index)
	{
		ipk[index] = i;
	}
// Getter
	string getNama(int index)
	{
		return nama[index];
	}

	int getUsia(int index)
	{
		return usia[index];
	}

	float getIPK(int index)
	{
		return ipk[index];
	}
};

int main()
{
	Mahasiswa ms;

	int size;

	cout << "Masukan jumlah mahasiswa: ";
	cin >> size;

	for (int i = 0; i < size; i++)
	{
		string nama;
		int usia;
		float ipk;

		cout << "Data mahasiswa ke-" << i + 1 << endl;
		cout << "Nama : ";
		cin.ignore();
		getline(cin, nama);
		cout << "Usia: ";
		cin >> usia;
		cout << "IPK: ";
		cin >> ipk;
		cout << "---------------------" << endl;

		ms.setNama(nama, i);
		ms.setUsia(usia, i);
		ms.setIPK(ipk, i);
	}

	for (int i = 0; i < size; i++)
	{
		cout << "Nama: " << ms.getNama(i) << endl;
		cout << "Umur: " << ms.getUsia(i) << endl;
		cout << "IPK: " << ms.getIPK(i) << "\n\n";
	}

	return 0;
}
