#include <iostream>
using namespace std;

void ascendingBubbleSort(int array[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
        cout << "Tahap " << i + 1 << ":\n";
        for (int k = 0; k < n; k++)
        {
            cout << array[k] << " ";
        }
        cout << "\n-----------------------------------------------\n";
	}
}

void descendingBubbleSort(int array[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (array[j] < array[j + 1])
			{
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
        cout << "Tahap " << i + 1 << ":\n";
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

	cout << "\n-- Ascending Bubble Sort --\n";
	cout << "\nProses Ascending Bubble Sort: \n";
	ascendingBubbleSort(array, n);

	cout << "Hasil Ascending Bubble Sort: \n";
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}

	cout << endl;
	cout << "\n=========================================================\n";

	cout << "\n-- Descending Bubble Sort --\n";
	cout << "\nProses Descending Bubble Sort: \n";
	descendingBubbleSort(array, n);

	cout << "Hasil Descending Bubble Sort: \n";
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}
}
