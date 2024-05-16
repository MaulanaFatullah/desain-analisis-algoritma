#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int binarySearch(string daftarBuku[], string cariJudul, int low, int high) {

  if (high < low) {
    return -1;
  }

  int mid = low + (high - low) / 2;

  if (cariJudul == daftarBuku[mid]) {
    return mid;
  } else if (cariJudul < daftarBuku[mid]) {
    return binarySearch(daftarBuku, cariJudul, low, mid - 1);
  } else {
    return binarySearch(daftarBuku, cariJudul, mid + 1, high);
  }
}

int main() {
  string daftarBuku[5] = {"Desain dan Analisis Algoritma", "Basis Data", "Statistika", 
                          "Matematika Diskrit", "Bahasa Indonesia"};
sort(daftarBuku, daftarBuku + 5);

  string cariJudul;
  cout << "Masukkan judul buku yang akan dicari: ";
  getline(cin, cariJudul);

  int indeksBuku = binarySearch(daftarBuku, cariJudul, 0, 4);

  if (indeksBuku != -1) {
    cout << "Buku " << cariJudul << " berada di rak " << (indeksBuku + 1) << endl;
  } else {
    cout << "Buku " << cariJudul << " tidak ditemukan." << endl;
  }

  return 0;
}
