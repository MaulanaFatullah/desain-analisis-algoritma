#include <iostream>

using namespace std;

class DoubleHashing {
private:
    int *table;
    int size;

public:
    DoubleHashing(int size) {
        this->size = size;
        table = new int[size];
        for (int i = 0; i < size; i++) {
            table[i] = -1;
        }
    }

    int hash1(int key) {
        return key % size;
    }
    
    int hash2(int key) {
        return 7 - (key % 7);
    }

    void insert(int key) {
        int index = hash1(key);
        int step = hash2(key);

        while (table[index] != -1) {
            index = (index + step) % size;
        }

        table[index] = key;
    }

    void search(int key) {
        int index = hash1(key);
        int step = hash2(key);

        while (table[index] != key && table[index] != -1) {
            index = (index + step) % size;
        }

        if (table[index] == key) {
            cout << "Kunci ditemukan pada index ke-" << index << endl;
        } else {
            cout << "Kunci tidak ditemukan" << endl;
        }
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << "Index " << i << ": ";
            if (table[i] == -1) {
                cout << "Kosong" << endl;
            } else {
                cout << table[i] << endl;
            }
        }
    }
};

int main() {
    DoubleHashing dh(10);

    dh.insert(5);
    dh.insert(25);
    dh.insert(15);
    dh.insert(35);
    dh.insert(95);

    dh.display();

    dh.search(25);
    dh.search(35);
    dh.search(55);

    return 0;
}
