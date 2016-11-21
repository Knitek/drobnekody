#include <iostream>
#include <windows.h>
// �eby nie pami�ta� komend cmd
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
			cout<<"\nPodaj ilo�� godzin w u�amku dziesi�tnym za ile ma nast�pi� zamkni�cie systemu\n";
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
			cout<<"ustaw - ustawianie czasowego wy��czenia komputera\nanuluj - przerwanie zaplanowanego wy��czenia komputera\nwyjdz - zamyka program\n";
		}
	}while(!koniec);	
}
