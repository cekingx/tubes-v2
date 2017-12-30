#include "motor.h"

using namespace std;

int main(){
	hapus_motor();

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
	//system("cls");
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
	system("cls");
	motor temp;
	int pilih;
	int i,j;
	char yakin;
	ifstream infile;
	ofstream outfile;

	tb_motor();
	cout << "\n\nPilih motor yang akan di edit > ";cin >> pilih; //Pilih nomer motor
	cout << "Nama Motor      > "; cin >> temp.nama;
	cout << "Plat            > "; cin >> temp.plat;
	cout << "Kapasitas Mesin > "; cin >> temp.cc;
	cout << "Tahun Produksi  > "; cin >> temp.tahun;

	cout << "\nReview Kendaraan :" << endl;
	cout << "Nama Motor      : " << temp.nama << endl;
	cout << "Plat            : " << temp.plat << endl;
	cout << "Kapasitas Mesin : " << temp.cc << endl;
	cout << "Tahun Produksi  : " << temp.tahun << endl;
	cout << "Anda yakin ?[y/t] > ";cin >> yakin;

	if(yakin == 'y' || yakin == 'Y'){
		infile.open("db_motor/db_motor.txt", ios::in);
		i=0;
		while(!infile.eof()){ //assign dari file ke array
			infile >> arrmotor[i].nama >> arrmotor[i].plat >> arrmotor[i].cc >> arrmotor[i].tahun;
			i++; 
		}
		infile.close();

		strcpy(arrmotor[pilih-1].nama, temp.nama); //edit elemen yang dipilih pada array
		strcpy(arrmotor[pilih-1].plat, temp.plat);
		arrmotor[pilih-1].cc = temp.cc;
		arrmotor[pilih-1].tahun = temp.tahun;

		outfile.open("db_motor/db_motor.txt", ios::out | ios::trunc); //assign dari array ke file
		for(j=0;j<i;j++){
			outfile << arrmotor[j].nama << " " << arrmotor[j].plat << " " << arrmotor[j].cc << " " << arrmotor[j].tahun << endl;
		}
		outfile.close();
	}

}

void hapus_motor(){
	system("cls");
	motor temp;
	int hapus;
	int i,j;
	char yakin;
	ifstream infile;
	ofstream outfile;

	tb_motor();
	cout << "\n\nPilih Motor Yang Akan Dihapus >"; cin >> hapus; //Nomer motor yang akan dihapus
	infile.open("db_motor/db_motor.txt", ios::in);
	i=0;
	while(!infile.eof()){ //assign dari file ke array
		infile >> arrmotor[i].nama >> arrmotor[i].plat >> arrmotor[i].cc >> arrmotor[i].tahun;
		i++; 
	}
	infile.close();

	cout << "\nReview Kendaraan :" << endl;
	cout << "Nama Motor      : " << arrmotor[hapus-1].nama << endl;
	cout << "Plat            : " << arrmotor[hapus-1].plat << endl;
	cout << "Kapasitas Mesin : " << arrmotor[hapus-1].cc << endl;
	cout << "Tahun Produksi  : " << arrmotor[hapus-1].tahun << endl;
	cout << "Anda yakin ?[y/t] > ";cin >> yakin;
	if(yakin == 'y' || yakin == 'Y'){
		for(j=hapus-1;j<i;j++){ //hapus motor di array
			strcpy(arrmotor[j].nama,arrmotor[j+1].nama);
			strcpy(arrmotor[j].plat,arrmotor[j+1].plat);
			arrmotor[j].cc = arrmotor[j+1].cc;
			arrmotor[j].tahun = arrmotor[j+1].tahun;
		}
	}

	outfile.open("db_motor/db_motor.txt", ios::out | ios::trunc); //assign dari array ke file
	for(j=0;j<i-2;j++){
		outfile << arrmotor[j].nama << " " << arrmotor[j].plat << " " << arrmotor[j].cc << " " << arrmotor[j].tahun << endl;
	}
	outfile.close();

}