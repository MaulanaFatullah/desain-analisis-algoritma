#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
		cout << "Tahap " << i + 1 << ":\n";
		for (int k = 0; k < n; k++)
		{
			cout << arr[k] << " ";
		}
		cout << endl;
	}
}

int main()
{
	int n;
	cout << "Masukkan jumlah elemen dalam array: ";
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Masukkan nilai ke - " << i + 1 << ": ";
		cin >> arr[i];
	}

	cout << "Array sebelum sorting: \n";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	cout << "Proses Bubble Sort: \n";
	bubbleSort(arr, n);

	cout << "Array setelah sorting secara ascending: \n";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}
