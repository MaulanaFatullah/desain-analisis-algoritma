#include <iostream>
using namespace std;

// Fungsi untuk membandingkan dua elemen array
bool compare(int a, int b)
{
    // Kembalikan true jika a lebih besar dari b
    return a > b;
}

// Fungsi untuk partisi array
int partition(int arr[], int low, int high)
{
    // Pilih pivot sebagai elemen terakhir
    int pivot = arr[high];

    // Indeks elemen yang lebih kecil dari pivot
    int i = low - 1;

    // Loop untuk semua elemen di antara low dan high
    for (int j = low; j < high; j++)
    {
        // Jika elemen saat ini lebih kecil dari pivot
        if (compare(arr[j], pivot))
        {
            // Tukar elemen saat ini dengan elemen di i
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // Tukar pivot dengan elemen di i + 1
    swap(arr[i + 1], arr[high]);

    // Kembalikan indeks partisi
    return i + 1;
}

// Fungsi untuk quicksort
void quicksort(int arr[], int low, int high)
{
    // Jika low lebih kecil dari high
    if (low < high)
    {
        // Temukan partisi
        int pi = partition(arr, low, high);

        // Rekursif quicksort pada elemen di kiri partisi
        quicksort(arr, low, pi - 1);

        // Rekursif quicksort pada elemen di kanan partisi
        quicksort(arr, pi + 1, high);
    }
}

// Menampilkan elemen array
void printArray(int arr[], int size)
{
    cout << "[";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
        if (i < size - 1) {
            cout << ", ";
        }
    }
    cout << "]";
    cout << endl;
}

int main()
{
    // Array contoh
    int arr[] = {67, 91, 87, 33, 49, 10, 16, 43, 65, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Menampilkan array awal
    cout << "Array awal: ";
    printArray(arr, size);

    // Melakukan quicksort dan menampilkan array pada setiap tahap
    for (int i = 0; i < size; i++)
    {
        quicksort(arr, 0, i);
        cout << "Tahap " << i << ": ";
        printArray(arr, size);
    }

    // Menampilkan array yang sudah diurutkan
    cout << "Array akhir: ";
    printArray(arr, size);

    return 0;
}
