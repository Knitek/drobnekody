#include <iostream>

using namespace std;

int main()
{
    string dane="",tmp;
    while(getline(cin,tmp))
        dane+=tmp;

    unsigned int licznik;
    for(char znak='a';znak<123;znak++)
        {
            licznik=0;
            for(unsigned int i=0;i<dane.length();i++)
            {
                if(dane[i]==znak)licznik++;
            }
            if(licznik!=0)cout<<znak<<" "<<licznik<<endl;
        }
    for(char znak='A';znak<91;znak++)
        {
            licznik=0;
            for(unsigned int i=0;i<dane.length();i++)
            {
                if(dane[i]==znak)licznik++;
            }
            if(licznik!=0)cout<<znak<<" "<<licznik<<endl;
        }
}
