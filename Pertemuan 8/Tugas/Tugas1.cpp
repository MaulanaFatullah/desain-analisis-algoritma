#include <iostream>

using namespace std;

const int MAX = 100;

// Deklarasi class
class Queue
{
private:
    int front, rear, count;
    int arr[MAX];

public:
    Queue()
    {
        front = 0;
        rear = MAX - 1;
        count = 0;
    }

    void enqueue(int x)
    {
        if (count >= MAX)
        {
            cout << "Antrian penuh." << endl;
            return;
        }

        rear = (rear + 1) % MAX;
        arr[rear] = x;
        count++;
    }

    int dequeue()
    {
        if (count <= 0)
        {
            cout << "Antrian kosong." << endl;
            return -1;
        }

        int x = arr[front];
        front = (front + 1) % MAX;
        count--;
        return x;
    }

    int peek()
    {
        if (count <= 0)
        {
            cout << "Antrian kosong." << endl;
            return -1;
        }

        return arr[front];
    }

    int size()
    {
        return count;
    }

    bool isEmpty()
    {
        return count == 0;
    }

    bool isFull()
    {
        return count == MAX;
    }
};

int main()
{
    // Deklarasi queue
    Queue q;

    // Input jumlah data
    int n;
    cout << "Masukkan Jumlah Angka Yang Ingin Dimasukkan ke Dalam Queue: ";
    cin >> n;

    // Input data secara manual
    cout << "Masukkan " << n << " angka: " << endl;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        q.enqueue(x);
    }
    // Menampilkan seluruh isi antrian
    cout << "Menampilkan Angka Dari Queue: ";
    while (!q.isEmpty())
    {
        cout << q.dequeue() << " ";
    }
    cout << endl;

    return 0;
}
