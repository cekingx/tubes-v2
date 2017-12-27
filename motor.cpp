#include "motor.h"

using namespace std;

int main(){
	tambah_motor();

	return 0;
}

void tambah_motor(){
	char pilih;
	bool check;
	motor temp;
	system("cls");
	ifstream infile;
	ofstream outfile;

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

}

void edit_motor(){

}

void hapus_motor(){

}