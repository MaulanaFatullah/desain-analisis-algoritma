#include <iostream>
#include <math.h>
using namespace std;

class Calculator
{
    float a, b;

public:
    void result()
    {
        cout << "Enter First Number: ";
        cin >> a;
        cout << "Enter Second Number: ";
        cin >> b;
    }

    int add()
    {
        return a + b;
    }

    int sub()
    {
        return a - b;
    }

    float mul()
    {
        return a * b;
    }

    float div()
    {
        if (b == 0)
        {
            cout << "ERROR!" << endl;
        }
        else
        {
            return a / b;
        }
    }
};

int main()
{
    Calculator c;

    c.result();

    cout << "Pertambahan : " << c.add() << endl;

    cout << "Pengurangan : " << c.sub() << endl;

    cout << "Perkalian : " << c.mul() << endl;

    cout << "Pembagian : " << c.div() << endl;

}