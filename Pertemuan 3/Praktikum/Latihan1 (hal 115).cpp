#include <iostream>

using namespace std;

class Buku {
	private:
		string judul;
		string penulis;
		
		public:
			void setJudul (string j) {
				judul = j;
			}
			
			void setPenulis (string p) {
				penulis = p;
			}
			
			string getJudul () {
				return judul;
			}
			
			string getPenulis() {
				return penulis;
			}
};

int main () {
	Buku buku;
    string judul;
    string penulis;

    cout << "-- Buku --" << endl;
    cout << "Masukkan judul: ";
    getline(cin, judul);
    buku.setJudul(judul);
    cout << "Masukkan penulis: ";
    getline(cin, penulis);

    buku.setPenulis(penulis);
	
	cout << "Nama: " << buku.getJudul() << endl;
	cout << "Spesies: " << buku.getPenulis() << endl;
	return 0;
}