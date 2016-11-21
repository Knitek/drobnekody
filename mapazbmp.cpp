#include <fstream>
#include <iostream>

using namespace std;

const int rozmiar = 64;
const string zrodlo = "mapa1.bmp";
const string wynik = "wynik1.map";

int main()
{
    char tab[rozmiar][rozmiar];
    fstream plik;
    char znak;
    plik.open(zrodlo.c_str(),ios::in | ios::binary);
    plik.seekg(-(rozmiar*rozmiar),ios_base::end);

    for(int i=0;i<rozmiar;i++)
    {
        for(int j=0;j<rozmiar;j++)
        {
            plik.get(znak);
            switch(znak)
            {
            case 0x00:
                tab[rozmiar-i-1][j]='#';
                break;
            case 0x4F:
                tab[rozmiar-i-1][j]='E';
                break;
            case 0x71:
                tab[rozmiar-i-1][j]='S';
                break;
            default:
                tab[rozmiar-i-1][j]='.';
                break;
            }
        }
    }
    plik.close();


    plik.open(wynik.c_str(),ios::out | ios::trunc);

    for(int i=0;i<rozmiar;i++)
    {
        for(int j=0;j<rozmiar;j++)
        {
            plik<<tab[i][j]<<" ";
            cout<<tab[i][j];
        }
        plik<<"\n";
        cout<<endl;
    }
    plik.close();
}
