#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    // Copy data ke dalam dua array sementara
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    // Proses penggabungan
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }
    // Copy sisa elemen dari kedua array sementara jika ada
    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }
    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Memecah list menjadi dua bagian
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Tahapan pemecahan
        cout << "Memecah List [";
        for (int i = left; i <= right; ++i) {
            cout << arr[i];
            if (i < right) {
                cout << ", ";
            }
        }
        cout << "]" << endl;

        merge(arr, left, mid, right);

        // Tahapan penggabungan
        cout << "Menggabungkan List [";
        for (int i = left; i <= right; ++i) {
            cout << arr[i];
            if (i < right) {
                cout << ", ";
            }
        }
        cout << "]" << endl << endl;
    }
}

int main() {
    int arr[] = {2, 5, 60, 43, 27, 10, 89, 17};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    cout << "List awal: [";
    for (int i = 0; i < arr_size; ++i) {
        cout << arr[i];
        if (i < arr_size - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl << endl;

    mergeSort(arr, 0, arr_size - 1);

    cout << "Sorted array: [";
    for (int i = 0; i < arr_size; ++i) {
        cout << arr[i];
        if (i < arr_size - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}
