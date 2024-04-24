#include <iostream>
using namespace std;

class Karyawan
{
private:
    int gaji;

public:
    void setGaji(int s)
    {
        gaji = s;
    }
    int getGaji()
    {
        return gaji;
    }
};

int main()
{
    Karyawan myObj;
    myObj.setGaji(50000);
    cout << "--Implementasi Enkapsulasi--" << endl;
    cout << myObj.getGaji();
    return 0;
}