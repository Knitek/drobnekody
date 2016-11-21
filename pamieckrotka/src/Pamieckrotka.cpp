#include "Pamieckrotka.h"

Pamieckrotka::Pamieckrotka()
{

    wyjscie=false;
    wypelnij_znaki();
    system("cls");
    cout<<"Witamy w programie do cwiczenia pamieci krotkotrwalej"<<endl;
    getch();
    system("cls");
    do
    {
        ilosc_znakow=0;
        ilosc_prob=0;
        punkty=0;

            opcje();
            test();

        short decyzja;
        do
        {
            cout<<"Jesli chcesz skozystac z programu wpisz '1',\njesli chcesz wyjsc wcisnij '0'."<<endl;
            cin>>decyzja;
            cin.clear();
            cin.sync();
        }while(!(decyzja==1 || decyzja==0));
        if(!decyzja)wyjscie=true;

    }while(!wyjscie);
}

Pamieckrotka::~Pamieckrotka()
{
    //dtor
}

void Pamieckrotka::test()
{
    for(int z=0;z<ilosc_prob;z++)
    {
        string slowo=generator();
        string odpowiedz;

        cout<<"Gotowy?\n";
        getch();
        system("cls");
            cout<<"\n\n\n\n\n\n\n\n\t\t\t\t"<<slowo;
        Sleep(500);
        system("cls");
        cin.clear(); cin.sync();
            cin>>odpowiedz;

        if(odpowiedz==slowo){cout<<"\nDobrze!\n";punkty++; }else cout<<"\nZle! \nPowinno byc: "<<slowo<<endl;
    }
    cout<<"Wynik twojego testu to "<<punkty<<"/"<<ilosc_prob<<" punktow.\n";
    getch();
    system("cls");
}

string Pamieckrotka::generator()
{
    char tab[20];
    int i=0;
    srand(time(NULL));
    switch(rodzaj_testu)
    {
    case 1:
        for(i=0;i<ilosc_znakow;i++)
        {
            tab[i]=znaki[(rand()%10)];
        }
        break;
    case 2:
        for(i=0;i<ilosc_znakow;i++)
        {
            tab[i]=znaki[(rand()%52)+10];
        }
        break;
    case 3:
        for(i=0;i<ilosc_znakow;i++)
        {
            tab[i]=znaki[(rand()%62)];
        }
        break;
    }
    string wynik(tab);
    return wynik.substr(0,ilosc_znakow);
}

void Pamieckrotka::opcje()
{
    system("cls");
    short decyzja1;
    do
    {
        cout<<"Wybierz rodzaj testu.\n";
        cout<<"'1' - same cyfry\n'2' - same litery\n'3' - litery i cyfry\n";
        cin>>decyzja1;
        cin.clear();
        cin.sync();
    }while(!(decyzja1>0 && decyzja1<4));
    rodzaj_testu=decyzja1;

    short decyzja2;
    do
    {
        cout<<"Wybierz z przedzialu <1,20>, ile chcesz znakow\n";
        cin>>decyzja2;
        cin.clear();
        cin.sync();
    }while(!(decyzja2>0 && decyzja2<21));
    ilosc_znakow=decyzja2;

    unsigned short decyzja3;
    do
    {
        cout<<"Wybierz z przedzialu <1,100>, ile chcesz testow\n";
        cin>>decyzja3;
        cin.clear();
        cin.sync();
    }while(!(decyzja3>0 && decyzja3<101));
    ilosc_prob=decyzja3;
}

void Pamieckrotka::wypelnij_znaki()
{
    for(int i=0;i<10;i++)
        znaki[i]=i+48;
    for(int i=0;i<26;i++){
        znaki[i+10]=65+i;
        znaki[i+10+26]=97+i;}
}
