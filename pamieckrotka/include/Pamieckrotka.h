#ifndef PAMIECKROTKA_H
#define PAMIECKROTKA_H

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <time.h>

using namespace std;

class Pamieckrotka
{
    public:
        Pamieckrotka();
        virtual ~Pamieckrotka();

        char znaki[62];
        short rodzaj_testu;
        short ilosc_znakow;
        unsigned short ilosc_prob,punkty;
        bool wyjscie;

        void opcje();
        void wybor();
        void test();
        string generator();
        void sprawdzanie(string);

        void wypelnij_znaki();
    protected:
    private:
};

#endif // PAMIECKROTKA_H
