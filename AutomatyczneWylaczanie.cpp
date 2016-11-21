#include <iostream>
#include <windows.h>
// ¿eby nie pamiêtaæ komend cmd
using namespace std;

int main()
{
	float liczba;
	bool koniec=false;
	string komenda,anulujwyjscie,ustalwyjscie;
	anulujwyjscie="shutdown -a";
	ustalwyjscie="shutdown -s -t ";
	do
	{
		cin>>komenda;
		if(komenda=="ustaw"){
			cout<<"\nPodaj iloœæ godzin w u³amku dziesiêtnym za ile ma nast¹piæ zamkniêcie systemu\n";
			cin>>liczba;
			liczba*=3600;
			int licz=(int)liczba;
			ustalwyjscie+=to_string(licz);
			system(ustalwyjscie.c_str());
			cout<<endl;
		}
		else if(komenda=="anuluj"){
			system(anulujwyjscie.c_str());
			cout<<endl;
		}
		else if(komenda=="wyjdz" || komenda=="exit" || komenda=="zamknij"){
			koniec=!koniec;
		}
		else if(komenda=="pomoc"){
			cout<<"ustaw - ustawianie czasowego wy³¹czenia komputera\nanuluj - przerwanie zaplanowanego wy³¹czenia komputera\nwyjdz - zamyka program\n";
		}
	}while(!koniec);	
}
