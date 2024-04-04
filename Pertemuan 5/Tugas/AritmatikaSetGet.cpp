#include <iostream>

using namespace std;

class Penambahan
{
private:
    float angka1, angka2;

public:
    void setAngka1(float x)
    {
        angka1 = x;
    }
    void setAngka2(float x)
    {
        angka2 = x;
    }

    float getAngka()
    {
        return angka1 + angka2;
    }
};
class Pengurangan
{
private:
    float angka1, angka2;

public:
    void setAngka1(float x)
    {
        angka1 = x;
    }
    void setAngka2(float x)
    {
        angka2 = x;
    }

    float getAngka()
    {
        return angka1 - angka2;
    }
};
class Perkalian
{
private:
    float angka1, angka2;

public:
    void setAngka1(float x)
    {
        angka1 = x;
    }
    void setAngka2(float x)
    {
        angka2 = x;
    }

    float getAngka()
    {
        return angka1 * angka2;
    }
};
class Pembagian
{
private:
    float angka1, angka2;

public:
    void setAngka1(float x)
    {
        angka1 = x;
    }
    void setAngka2(float x)
    {
        angka2 = x;
    }

    float getAngka()
    {
        if (angka2 == 0)
        {
            cout << "ERROR!" << endl;
            cout << "Angka pertama tidak boleh dibagi dengan 0" << endl;
        }
        else
        {
            return angka1 / angka2;
        }
    }
};
int main()
{
    Penambahan tambah;
    Pengurangan kurang;
    Perkalian kali;
    Pembagian bagi;

    float a, b;
    cout << "Masukkan  nilai angka pertama : ";
    cin >> a;
    tambah.setAngka1(a);
    kurang.setAngka1(a);
    kali.setAngka1(a);
    bagi.setAngka1(a);
    cout << "Masukkan  nilai angka kedua: ";
    cin >> b;
    tambah.setAngka2(b);
    kurang.setAngka2(b);
    kali.setAngka2(b);
    bagi.setAngka2(b);

    cout << "\nData : \n";
    cout << "Hasil penambahan: " << tambah.getAngka() << endl;
    cout << "Hasil pengurangan: " << kurang.getAngka() << endl;
    cout << "Hasil perkalian: " << kali.getAngka() << endl;
    cout << "Hasil pembagian: " << bagi.getAngka() << endl;

    return 0;
}