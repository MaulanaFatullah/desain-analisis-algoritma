/*
 * Program HashTable dengan OpenAddressing
 */

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <ctime>

using namespace std;

int storage[1024];
int i = 0;
int hdt_boundary;

void tambah_linear_probing(int n)
{
    bool inserted = false;
    int hash;
    i = 0;

    while ((!inserted) && (i < hdt_boundary))
    {
        hash = (n % hdt_boundary) + i;

        if (storage[hash] == 0)
        {
            storage[hash] = n;
            inserted = true;
        }
        else
        {
            ++i;
            cout << "Terjadi tabrakan di " << hash << endl;
        }
    }

    if (i == 0)
    {
        cout << "Langsung" << endl;
    }

    cout << "Isi hash[" << hash << "] dengan " << n << endl;
    cout << "===============================================" << endl;
}

void tambah_quadratic_probic(int n)
{
    bool inserted = false;
    int hash;
    i = 0;

    while ((!inserted) && (i < hdt_boundary))
    {
        hash = (n % hdt_boundary) + (i * i);

        if (storage[hash] == 0)
        {
            storage[hash] = 0;
            inserted = true;
        }
        else
        {
            ++i;
            cout << "Terjadi tabrakan di " << hash << endl;
        }
    }

    if (i == 0)
    {
        cout << "Langsung" << endl;
    }

    cout << "Isi hash[" << hash << "] dengan " << n << endl;
    cout << "===============================================" << endl;
}

int prima_atas(int n)
{
    if (n % 2 == 0)
    {
        n = n + 1;
    }
    else
    {
        n = n + 2;
    }

    bool ketemu = false;

    while (!ketemu)
    {
        bool prima = true;
        if (n % 2 == 0)
        {
            prima = false;
        }
        else
        {
            int i = 3;
            while (prima == true && i <= sqrt(n))
            {
                if (n % i == 0)
                {
                    prima = false;

                    i = i + 2;
                }
            }
            if (prima)
            {
                ketemu = true;
            }
            else
            {
                n = n + 2;
            }
            return n;
        }

        int prima_bawah()
        {
            int n = hdt_boundary;
            if (n % 2 == 0)
            {
                n = n - 1;
            }
            else
            {
                n = n - 2;
            }

            bool ketemu = false;
            while (!ketemu)
            {
                bool prima = true;
                if (n % 2 == 0)
                {
                    prima = false;
                }
                else
                {
                    int i = 3;
                    while (prima == true && i <= sqrt(n))
                    {
                        if (n % i == 0)
                        {
                            prima = false;
                        }
                        i = i + 2;
                    }
                }
                if (prima)
                {
                    ketemu = true;
                }
                else
                {
                    n = n - 2;
                }
                return n;
            }
        }
    }
}