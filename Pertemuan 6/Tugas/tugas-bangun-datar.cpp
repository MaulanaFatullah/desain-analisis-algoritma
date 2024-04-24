#include <iostream>

using namespace std;

class BangunDatar
{
protected:
    int panjang, lebar, alas, tinggi, sisi;

public:
    BangunDatar(int _panjang, int _lebar, int _alas, int _tinggi, int _sisi) : panjang(_panjang), lebar(_lebar), alas(_alas), tinggi(_tinggi), sisi(_sisi) {}

    virtual void display() = 0;
    virtual int getLuas() = 0; // membuat fungsi virtual yang harus diimplementasikan oleh turunannya
};

class PersegiPanjang : public BangunDatar
{
public:
    PersegiPanjang(int _panjang, int _lebar) : BangunDatar(_panjang, _lebar, 0, 0, 0) {}

    // Method yang di override dari class BangunDatar
    void display() override
    {
        cout << "Luas Persegi Panjang: " << getLuas() << endl;
    }

    int getLuas() override {
        return panjang * lebar;
    }
};

class Segitiga : public BangunDatar
{
public:
    Segitiga(int _alas, int _tinggi) : BangunDatar(0, 0, _alas, _tinggi, 0) {}

    // Method yang di override dari class BangunDatar
    void display() override
    {
        cout << "Luas Segitiga: " << getLuas() << endl;
    }

    int getLuas() override {
        return (0.5 * alas * tinggi);
    }
};

class Persegi : public BangunDatar
{
public:
    Persegi(int _sisi) : BangunDatar(0, 0, 0, 0, _sisi) {}

    // Method yang di override dari class BangunDatar
    void display() override
    {
        cout << "Luas Persegi: " << getLuas() << endl;
    }

    int getLuas() override {
        return sisi * sisi;
    }
};

int main () {
    int panjang, lebar, alas, tinggi, sisi;

    cout << "~~Persegi Panjang~~" << endl;
    cout << "\tMasukkan panjang: "; cin >> panjang;
    cout << "\tMasukkan lebar: "; cin >> lebar;
    cout << "~~Segitiga~~" << endl;
    cout << "\tMasukkan alas: "; cin >> alas;
    cout << "\tMasukkan tinggi: "; cin >> tinggi;
    cout << "~~Persegi~~" << endl;
    cout << "\tMasukkan sisi: "; cin >> sisi;

    cout << "\n\n";

    PersegiPanjang persegi_panjang(panjang, lebar);
    Segitiga segitiga(alas, tinggi);
    Persegi persegi(sisi);
    
    cout << "--Luas Bangun Datar--" << endl;
    persegi_panjang.display();
    segitiga.display();
    persegi.display();
    return 0;
}
