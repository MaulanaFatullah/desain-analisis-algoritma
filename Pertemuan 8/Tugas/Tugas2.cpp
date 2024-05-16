#include <iostream>
#include <string>

using namespace std;

const int MAX = 100;

// Deklarasi class
class Queue
{
private:
    int front, rear, count;
    string arr[MAX];  // Change to string array

public:
    Queue()
    {
        front = 0;
        rear = MAX - 1;
        count = 0;
    }

    void enqueue(const string &x)
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

    string dequeue()
    {
        if (count <= 0)
        {
            cout << "Antrian kosong." << endl;
            return "";
        }

        string x = arr[front];
        front = (front + 1) % MAX;
        count--;
        return x;
    }

    string peek()
    {
        if (count <= 0)
        {
            cout << "Antrian kosong." << endl;
            return "";
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
    cout << "Masukkan Jumlah Nama Yang Ingin Dimasukkan ke Dalam Queue: ";
    cin >> n;
    cin.ignore();  // To ignore the newline character left in the buffer

    // Input data secara manual
    for (int i = 0; i < n; i++)
    {
        string name;
        cout << "Masukkan nama ke-" << i + 1 << ": ";
        getline(cin, name);  // Use getline to read the full name
        q.enqueue(name);
    }

    // Menampilkan seluruh isi antrian
    cout << "Nama Dalam Antrian: " << endl;
    while (!q.isEmpty())
    {
        cout << q.dequeue() << endl;
    }
    cout << endl;

    return 0;
}
