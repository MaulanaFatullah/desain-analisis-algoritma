#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Tiket {
public:
    int nomorTiket;
    string namaPelanggan;

    Tiket(int nomorTiket, string namaPelanggan) {
        this->nomorTiket = nomorTiket;
        this->namaPelanggan = namaPelanggan;
    }
};

class LoketTiket {
private:
    queue<Tiket> antrianTiket;
    int maxSize;

public:
    LoketTiket(int size) : maxSize(size) {}

    void enqueue(Tiket tiket) {
        if (!isFull()) {
            antrianTiket.push(tiket);
        } else {
            cout << "Antrian penuh, tidak dapat menambahkan pelanggan." << endl;
        }
    }

    void dequeue() {
        if (!isEmpty()) {
            antrianTiket.pop();
        } else {
            cout << "Tidak ada pelanggan yang mengantri." << endl;
        }
    }

    Tiket front() {
        if (!isEmpty()) {
            return antrianTiket.front();
        } else {
            throw runtime_error("Tidak ada pelanggan yang mengantri.");
        }
    }

    bool isEmpty() {
        return antrianTiket.empty();
    }

    bool isFull() {
        return antrianTiket.size() >= maxSize;
    }

    void displayQueue() {
        if (isEmpty()) {
            cout << "Tidak ada pelanggan dalam antrian." << endl;
            return;
        }

        queue<Tiket> tempQueue = antrianTiket;
        cout << "Daftar antrian:" << endl;
        while (!tempQueue.empty()) {
            Tiket tiket = tempQueue.front();
            cout << "Nomor Antrian: " << tiket.nomorTiket << " | Nama: " << tiket.namaPelanggan << endl;
            tempQueue.pop();
        }
    }
};

int main() {
    const int MAX_SIZE = 100;
    LoketTiket loket(MAX_SIZE);
    int pilihan, nomorTiket = 0;
    string namaPelanggan;

    while (1) {
        cout << "\nMenu loket tiket:" << endl;
        cout << "1. Ambil nomor antrian\n";
        cout << "2. Panggil pelanggan berikutnya\n";
        cout << "3. Lihat daftar antrian\n";
        cout << "4. Keluar\n";
        cout << "Masukkan pilihan menu: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama pelanggan: ";
                getline(cin, namaPelanggan);
                nomorTiket++;
                loket.enqueue(Tiket(nomorTiket, namaPelanggan));
                cout << "Nomor antrian Anda: " << nomorTiket << endl;
                break;

            case 2:
                if (!loket.isEmpty()) {
                    Tiket tiketSekarang = loket.front();
                    loket.dequeue();
                    cout << "\nSilahkan layani pelanggan dengan nomor antrian: " << tiketSekarang.nomorTiket << " (" << tiketSekarang.namaPelanggan << ")" << endl;
                } else {
                    cout << "\nTidak ada pelanggan yang mengantri." << endl;
                }
                break;

            case 3:
                loket.displayQueue();
                break;

            case 4:
                cout << "\nTerima kasih telah menggunakan program loket tiket." << endl;
                return 0;

            default:
                cout << "Pilihan tidak valid." << endl;
        }
    }

    return 0;
}
