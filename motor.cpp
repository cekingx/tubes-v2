#include "motor.h"

using namespace std;

int main(){
	tb_motor();

	return 0;
}

void tambah_motor(){
	char pilih;
	motor temp;
	ifstream infile;
	ofstream outfile;
	system("cls");

	cout << "\n\nTambah Sepeda Motor : " << endl;
	cout << "Nama Motor      > "; cin >> temp.nama;
	cout << "Plat            > "; cin >> temp.plat;
	cout << "Kapasitas Mesin > "; cin >> temp.cc;
	cout << "Tahun Produksi  > "; cin >> temp.tahun;

	cout << "\nReview Kendaraan :" << endl;
	cout << "Nama Motor      : " << temp.nama << endl;
	cout << "Plat            : " << temp.plat << endl;
	cout << "Kapasitas Mesin : " << temp.cc << endl;
	cout << "Tahun Produksi  : " << temp.tahun << endl;
	cout << "\nApakah data tersebut sudah benar ? [y/t] >"; cin >> pilih;

	if(pilih == 'y' || pilih == 'Y'){
		infile.open("db_motor/db_motor.txt", ios::in);
		if(infile.fail()){
			system("mkdir db_motor");
		}
		infile.close();

		outfile.open("db_motor/db_motor.txt", ios::out | ios::app);

		outfile << temp.nama << " " << temp.plat << " " << temp.cc << " " << temp.tahun << endl;
		outfile.close();

	}
}

void tb_motor(){
	system("cls");
	int i,j;
	ifstream infile;
	ofstream outfile;

	infile.open("db_motor/db_motor.txt", ios::in);
	i=0;
	while(!infile.eof()){
		infile >> arrmotor[i].nama >> arrmotor[i].plat >> arrmotor[i].cc >> arrmotor[i].tahun;
		i++; 
	}
	infile.close();

	cout << "+---+----------------------+-----------------+-------+-------+" << endl;
	cout << "| No|      Nama Motor      |       Plat      |  CC   | Tahun |" << endl;
	cout << "+---+----------------------+-----------------+-------+-------+" << endl;
	for(j=0;j<i-1;j++){
		cout << "|"  << setw(3) << j+1;
		cout << "| " << setw(20) << arrmotor[j].nama ;
		cout << " | " << setw(15) << arrmotor[j].plat ;
		cout << " | " << setw(5) << arrmotor[j].cc ;
		cout << " | " << setw(5) << arrmotor[j].tahun << " |" << endl;
	}
	cout << "+---+----------------------+-----------------+-------+-------+" << endl;

}

void edit_motor(){

}

void hapus_motor(){

}