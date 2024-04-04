#include <iostream>
using namespace std;

// Fungsi untuk menukar dua elemen dalam array
void tukar(int arr[], int pos1, int pos2)
{
    int temp;
    temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}

// Fungsi untuk membagi array berdasarkan pivot
int partisi(int arr[], int rendah, int tinggi, int pivot, bool ascending)
{
    int i = rendah;
    int j = rendah;
    do
    {
        if (ascending)
        {
            if (arr[i] <= pivot)
            {
                tukar(arr, i, j); // Menukar elemen jika elemen saat ini <= pivot
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        else
        { // descending
            if (arr[i] >= pivot)
            {
                tukar(arr, i, j); // Menukar elemen jika elemen saat ini >= pivot
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
    } while (i <= tinggi);
    return j - 1; // Mengembalikan posisi pivot yang benar setelah partisi
}
// Fungsi rekursif untuk Quicksort
void quickSort(int arr[], int rendah, int tinggi, bool ascending)
{
    if (rendah < tinggi)
    {
        int pivot = arr[tinggi];                                 // Pivot dipilih sebagai elemen terakhir
        int pos = partisi(arr, rendah, tinggi, pivot, ascending); // Memperoleh posisi pivot yang benar setelah partisi
        quickSort(arr, rendah, pos - 1, ascending);               // Memanggil quickSort pada bagian kiri pivot
        quickSort(arr, pos + 1, tinggi, ascending);              // Memanggil quickSort pada bagian kanan pivot
    }
}

int main()
{
    int n, i = 0;
    cout << "Tentukan panjang array: ";
    cin >> n;
    int arr[n];
    do
    {
        cout << "Elemen ke-" << i + 1 << " :";
        cin >> arr[i];
        i++;
    } while (i < n);

    cout << "Array awal: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t"; // Mencetak elemen-elemen array yang telah diurutkan secara ascending
    }
 	cout << endl;
    // Urutkan secara ascending
    bool ascending = true;
    quickSort(arr, 0, n - 1, ascending);
    cout << "Hasil ascending: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t"; // Mencetak elemen-elemen array yang telah diurutkan secara ascending
    }
    

    cout << endl;

    return 0;
}

