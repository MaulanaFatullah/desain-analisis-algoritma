#include <iostream>
#include <string>

using namespace std;
void ascendingBubbleSort(string arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                string temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int n;
    cout << "Masukkan jumlah judul buku yang ingin dimasukkan: ";
    cin >> n;

    string buku[n];

    cin.ignore(); // Membersihkan buffer agar getline() berfungsi dengan benar
    for (int i = 0; i < n; i++) {
        cout << "Masukkan judul buku ke-" << i+1 << ": ";
        getline(cin, buku[i]);
    }

    ascendingBubbleSort(buku, n);

    cout << "\nBuku setelah diurutkan secara ascending:\n";
     for (int i = 0; i < n; i++) {
        cout << buku[i] << endl;
    }

    return 0;
}
