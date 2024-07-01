#include <iostream>

using namespace std;

class HashTable
{
private:
  int size;
  int **table;
  int *tableSize;

public:
  HashTable(int size)
  {
    this->size = size;
    table = new int *[size];
    tableSize = new int[size];
    for (int i = 0; i < size; i++)
    {
      table[i] = new int[0];
      tableSize[i] = 0;
    }
  }

  int hashFunction(int key)
  {
    return key % size;
  }

  void insert(int key)
  {
    int index = hashFunction(key);
    int *temp = new int[tableSize[index] + 1];
    for (int i = 0; i < tableSize[index]; i++)
    {
      temp[i] = table[index][i];
    }
    temp[tableSize[index]] = key;
    delete[] table[index];
    table[index] = temp;
    tableSize[index]++;
  }

  void display()
  {

    for (int i = 0; i < size; i++)
    {
      cout << i << " --> ";
      if (tableSize[i] == 0)
      {
        cout << "Kosong";
      }
      else
      {
        for (int j = 0; j < tableSize[i]; j++)
        {
          cout << table[i][j] << " ";
        }
      }
      cout << endl;
    }
  }

  bool search(int key)
  {
    int index = hashFunction(key);
    for (int i = 0; i < tableSize[index]; i++)
    {
      if (table[index][i] == key)
      {
        return true;
      }
    }
    return false;
  }

  ~HashTable()
  {
    for (int i = 0; i < size; i++)
    {
      delete[] table[i];
    }
    delete[] table;
    delete[] tableSize;
  }
};

int main()
{
  int size, numElements;

  cout << "Masukkan ukuran tabel hash: ";
  cin >> size;

  cout << "Masukkan jumlah elemen yang akan disimpan: ";
  cin >> numElements;

  HashTable hashTable(size);

  cout << "Masukkan " << numElements << " elemen:" << endl;
  for (int i = 0; i < numElements; i++)
  {
    int element;
    cout << "Elemen ke-" << (i + 1) << ": ";
    cin >> element;
    hashTable.insert(element);
  }

  cout << "Isi Tabel Hash:" << endl;
  hashTable.display();

  int searchKey;
  cout << "Masukkan elemen yang ingin dicari dalam tabel hash: ";
  cin >> searchKey;
  if (hashTable.search(searchKey))
  {
    cout << searchKey << " ditemukan dalam tabel hash." << endl;
  }
  else
  {
    cout << searchKey << " tidak ditemukan dalam tabel hash." << endl;
  }

  return 0;
}