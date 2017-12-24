#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>

using namespace std;

typedef struct{
	string nama;
	string alamat;
	int umur;
}datadiri;

void menuu();

int main(){
	system("cls");
	char again;
	int menu;

	do{
		cout<<"Menu : "<<endl;
		cout<<"1. I/O"<<endl;
		cout<<"2. Quit"<<endl;
		cout<<"Pilih menu >"; cin >> menu;
		switch(menu){
			case 1:{
				menuu();
				getchar();
				cout<<"Ingin mengulang ? [y/t] > "; cin >> again;
				break;
			}
			case 2:{
				again = 't';
				getchar();
				break;
			}
			default :{
				cout<<"pilihan salah"<<endl;
				cout<<"Ingin mengulang ? [y/t] > "; cin >> again;
				break;
			}
		}

	}while(again == 'y' || again == 'Y');

	return 0;
}

void menuu(){
	system("cls");
	datadiri orang;

	cout << "Input data diri anda" << endl;
	cout << "Nama > "; cin >> orang.nama;
	cout << "Alamat > "; cin >> orang.alamat;
	cout << "Umur > "; cin >> orang.umur;

	cout << "Data diri anda adalah sebagai berikut : "<< endl;
	cout << "Nama   : " << orang.nama << endl;
	cout << "Alamat : " << orang.alamat << endl;
	cout << "Umur   : " << orang.umur << endl;
}