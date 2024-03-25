#include <iostream>
using namespace std;


void ascendingInsertionSort(int array[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = array[i];
        int j = i - 1;
        while (key < array[j] && j >= 0)
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
        cout << "Tahap " << i << ":\n";
        for (int k = 0; k < n; k++)
        {
            cout << array[k] << " ";
        }
        cout << "\n-----------------------------------------------\n";
    }
}

void descendingInsertionSort(int array[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = array[i];
        int j = i - 1;
        while (key > array[j] && j >= 0)
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
        cout << "Tahap " << i << ":\n";
        for (int k = 0; k < n; k++)
        {
            cout << array[k] << " ";
        }
        cout << "\n-----------------------------------------------\n";
    }
}
int main()
{
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

	cout << "\n-- Ascending Insertion Sort --\n";
    cout << "\nProses Ascending Insertion Sort: \n";
    ascendingInsertionSort(array, n);
    cout << "Hasil Ascending Insertion Sort:\n";
    for (int k = 0; k < n; k++)
    {
        cout << array[k] << " ";
    }
    
	cout << endl;
    cout << "\n=========================================================\n";

    cout << "\n-- Descending Insertion Sort --\n";
    cout << "\nProses Descending Insertion Sort: \n";
    descendingInsertionSort(array, n);
    cout << "Hasil Descending Insertion Sort:\n";
    for (int k = 0; k < n; k++)
    {
        cout << array[k] << " ";
    }
}
//67, 91, 87, 33, 49, 10, 16, 43, 65, 3