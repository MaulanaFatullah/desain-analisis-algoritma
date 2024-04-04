#include <iostream>

using namespace std;

int main () {
    int data[] = {7, 3, 4, 10, 40};
    int i, n = 5, cari = 10;
    bool ketemu;

    for (i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << "\n\n\n";

    ketemu = false;
    for (i = 0; i < n; i++) {
        if  (data[i] == cari) {
            ketemu  = true;
        }
    }
    if (ketemu == true) {
        cout << "Angka = " << cari << " Ketemu!";
    } else {
        cout << "Angka = " << cari << " Tidak Ketemu!";
    }
}