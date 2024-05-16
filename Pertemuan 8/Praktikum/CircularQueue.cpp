#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 20;

// deklarasi class

class Queue
{
private:
    int front, rear;
    int arr[MAX];

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    void enqueue(int data)
    {
        if ((rear + 1) % MAX == front)
        {
            cout << "Queue is full" << endl;
            return;
        }

        if (front == -1)
        {
            front = 0;
        }
        rear = (rear + 1) % MAX;
        arr[rear] = data;
    }

    void dequeue()
    {
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
    }

    int front_element()
    {
        if (front == -1)
        {
            cout << "Queue is empty." << endl;
            return -1;
        }

        return arr[front];
    }

    bool is_empty()
    {
        return (front == -1);
    }
};

int main()
{
    // Deklarasi bilangan dalam antrian
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    // Deklarasi perintah yang akan dilakukan pada antrian

    cout << "Front element is: " << q.front_element() << endl;
    q.dequeue();
    cout << "Front element is: " << q.front_element() << endl;
    q.dequeue();

    return 0;
}