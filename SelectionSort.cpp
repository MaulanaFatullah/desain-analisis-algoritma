#include <iostream>
using namespace std;

void ascendingSelectionSort(int array[], int n)
{
    int i, j, minIdx;
    for (i = 0; i < n - 1; i++)
    {
        minIdx = i;
        for (j = i + 1; j < n; j++)
        {
            if (array[j] < array[minIdx])
            {
                minIdx = j;
            }
        }
        cout << "Tahap " << i << ":\n";
        for (int k = 0; k < n; k++)
        {
            cout << array[k] << " ";
        }
        cout << "\n-----------------------------------------------\n";
        int temp = array[minIdx];
        array[minIdx] = array[i];
        array[i] = temp;
    }
}
void descendingSelectionSort(int array[], int n)
{
    int i, j, minIdx;
    for (i = 0; i < n - 1; i++)
    {
        minIdx = i;
        for (j = i + 1; j < n; j++)
        {
            if (array[j] > array[minIdx])
            {
                minIdx = j;
            }
        }
        cout << "Tahap " << i << ":\n";
        for (int k = 0; k < n; k++)
        {
            cout << array[k] << " ";
        }
        cout << "\n-----------------------------------------------\n";
        int temp = array[minIdx];
        array[minIdx] = array[i];
        array[i] = temp;
    }
}
int main() {
    int n;
    cout << "Masukkan jumlah elemen: ";
    cin >> n;

    int array[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Masukkan nilai ke - " << i + 1 << ": ";
        cin >> array[i];
    }

    cout << "\nSebelum sorting: \n";
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    cout << "\n-- Ascending Selection Sort --\n";
    cout << "\nProses Ascending Insertion Sort: \n";
    ascendingSelectionSort(array, n);
    cout << "Hasil Ascending Selection Sort:\n";
    for (int k = 0; k < n; k++)
    {
        cout << array[k] << " ";
    }

    cout << endl;
    cout << "\n=========================================================\n";

    cout << "\n-- Descending Selection Sort --\n";
    cout << "\nProses Descending Insertion Sort: \n";
    descendingSelectionSort(array, n);
    cout << "Hasil Descending Selection Sort:\n";
    for (int k = 0; k < n; k++)
    {
        cout << array[k] << " ";
    }
}
