#include <iostream>
using namespace std;

class BangunDatar
{
protected:
    int lebar, tinggi;

public:
    void setValue(int a, int b)
    {
        lebar = a;
        tinggi = b;
    }
};

// Class turunan
class PersegiPanjang : public BangunDatar {
    public:
    int getValue() {
        return (lebar * tinggi);
    }
};

class Segitiga: public BangunDatar {
    public:
    int getValue()  {
        return (lebar * tinggi / 2);
    }
};

int main()
{
    // Inisiasi Object
    PersegiPanjang rectangle;
    Segitiga triangle;

    // Set Value
    rectangle.setValue(4, 5);
    triangle.setValue(10, 5);

    // Get Value
    cout << rectangle.getValue() << endl;
    cout << triangle.getValue() << endl;
    return 0;
}