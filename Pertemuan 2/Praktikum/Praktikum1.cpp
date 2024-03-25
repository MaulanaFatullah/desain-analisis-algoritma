#include <iostream>
using namespace std;

// Fungsi untuk menukar dua elemen dalam array
void swap(int arr[], int pos1, int pos2) {
    int temp;
    temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}

// Fungsi untuk membagi array berdasarkan pivot
int partition(int arr[], int low, int high, int pivot, bool ascending) {
    int i = low;
    int j = low;
    while (i <= high) {
        if (ascending) {
            if (arr[i] <= pivot) {
                swap(arr, i, j); // Menukar elemen jika elemen saat ini <= pivot
                i++;
                j++;
            } else {
                i++;
            }
        } else { // descending
            if (arr[i] >= pivot) {
                swap(arr, i, j); // Menukar elemen jika elemen saat ini >= pivot
                i++;
                j++;
            } else {
                i++;
            }
        }
    }
    return j - 1; // Mengembalikan posisi pivot yang benar setelah partisi
}
// Fungsi rekursif untuk Quicksort
void quickSort(int arr[], int low, int high, bool ascending) {
    if (low < high) {
        int pivot = arr[high]; // Pivot dipilih sebagai elemen terakhir
        int pos = partition(arr, low, high, pivot, ascending); // Memperoleh posisi pivot yang benar setelah partisi
        quickSort(arr, low, pos - 1, ascending); // Memanggil quickSort pada bagian kiri pivot
        quickSort(arr, pos + 1, high, ascending); // Memanggil quickSort pada bagian kanan pivot
    }
}

int main() {
    int n;
    cout << "Tentukan panjang array: ";
    cin >> n;
    int arr[n];
    cout << "Masukkan elemen-elemen array: \n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Urutkan secara ascending
    bool ascending = true;
    quickSort(arr, 0, n - 1, ascending);
    cout << "Hasil ascending: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\t"; // Mencetak elemen-elemen array yang telah diurutkan secara ascending
    }
    cout << endl;

    // Urutkan secara descending
    ascending = false;
    quickSort(arr, 0, n - 1, ascending);
    cout << "Hasil descending: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\t"; // Mencetak elemen-elemen array yang telah diurutkan secara descending
    }
    cout << endl;

    return 0;
}
