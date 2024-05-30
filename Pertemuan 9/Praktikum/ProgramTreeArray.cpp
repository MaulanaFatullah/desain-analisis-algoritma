#include <iostream>

using namespace std;

const int MAX_NODES = 100;

int tree[MAX_NODES];
int n;

void insertNode(int x)
{
    int curr = 0;

    while (tree[curr] != -1)
    {
        if (x < tree[curr])
        {
            curr = 2 * curr + 1;
        }
        else
        {
            curr = 2 * curr + 2;
        }
    }

    tree[curr] = x;
    n++;
}

void inorderTraversal(int curr)
{
    if (tree[curr] != -1)
    {
        inorderTraversal(2 * curr + 1);
        cout << tree[curr] << " ";
        inorderTraversal(2 * curr + 2);
    }
}

int main()
{
    for (int i = 0; i < MAX_NODES; i++)
    {
        tree[i] = -1;
    }
    n = 0;

    int x;
    char pilihan;
    do
    {
        cout << "Masukkan nilai pada binary tree ";
        cin >> x;
        insertNode(x);
        cout << "Ingin memasukkan nilai lain (y/n)?";
        cin >> pilihan;

    } while (pilihan == 'y' || pilihan == 'Y');

    cout << "In-order traversal: ";
    inorderTraversal(0);

    return 0;
}
