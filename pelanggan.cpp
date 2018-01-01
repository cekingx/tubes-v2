#include "pelanggan.h"

using namespace std;

pelanggan arrpelanggan[50];

void sewa(){
	char yakin;
	pelanggan temp;
	motor temp_m[30];
	int no_motor, harga;
	int i;
	ifstream infile;
	ofstream outfile;
	system("cls");

	tb_motor();
	cout << "\n\nData Diri Pelanggan :\n\n" << endl;
	cout << "Nama            > "; cin >> temp.nama;
	cout << "No. KTP/SIM     > "; cin >> temp.id;
	cout << "Alamat          > "; cin >> temp.alamat;
	cout << "Motor           > "; cin >> no_motor;
	cout << "Tanggal Sewa    > "; cin >> temp.tgl_sewa.dd >> temp.tgl_sewa.mm >> temp.tgl_sewa.yyyy;
	cout << "Tanggal Kembali > "; cin >> temp.tgl_kembali.dd >> temp.tgl_kembali.mm >> temp.tgl_kembali.yyyy;

	infile.open("db_motor/db_motor.txt", ios::in);
	i=0;
	while(!infile.eof()){ //read dari file motor.txt ke array temp_m[]
		infile >> temp_m[i].nama >> temp_m[i].plat >> temp_m[i].cc >> temp_m[i].tahun;
		i++;
	}
	infile.close();

	strcpy(temp.motorr.nama, temp_m[no_motor-1].nama);

	temp.lama_sewa = lama_sewa(temp.tgl_sewa, temp.tgl_kembali); //lama sewa

	infile.open("harga.txt", ios::in); //harga
	if(infile.fail()){ //jika harga.txt belum ada
		cout << "Harga belum ditentukan, tentukan harga" << endl;
		cout << "> "; cin >> harga;
		outfile.open("harga.txt", ios::out);
		outfile << harga;
		outfile.close();
		infile.close();
	}
	else{
		infile >> harga; //jika harga.txt sudah ada
		infile.close();
	}

	temp.biaya=harga*temp.lama_sewa; //biaya

	cout << "\n\nReview pelanggan :" << endl;
	cout << "Nama            : " << temp.nama << endl;
	cout << "No. KTP/SIM     : " << temp.id << endl;
	cout << "Alamat          : " << temp.alamat << endl;
	cout << "Motor           : " << temp.motorr.nama << endl;
	cout << "Tanggal Sewa    : " << temp.tgl_sewa.dd << "-" << temp.tgl_sewa.mm << "-" << temp.tgl_sewa.yyyy << endl;
	cout << "Tanggal Kembali : " << temp.tgl_kembali.dd << "-" << temp.tgl_kembali.mm << "-" << temp.tgl_kembali.yyyy << endl;
	cout << "Lama Sewa       : " << temp.lama_sewa << endl;
	cout << "Biaya           : " << temp.biaya << endl;	
	cout << "Apakah data tersebut sudah benar ? [y/t] > "; cin >> yakin;

	if(yakin == 'y' || yakin == 'Y'){ //write dari variabel temp ke file
		infile.open("db_pelanggan/db_pelanggan.txt", ios::in);
		if(infile.fail()){
			system("mkdir db_pelanggan");
		}
		infile.close();

		outfile.open("db_pelanggan/db_pelanggan.txt", ios::out | ios::app );
		outfile << temp.nama << " ";
		outfile << temp.id << " ";
		outfile << temp.alamat << " ";
		outfile << temp.motorr.nama << " ";
		outfile << temp.tgl_sewa.dd << " " << temp.tgl_sewa.mm << " " << temp.tgl_sewa.yyyy << " ";
		outfile << temp.tgl_kembali.dd << " " << temp.tgl_kembali.mm << " " << temp.tgl_kembali.yyyy << " ";
		outfile << temp.lama_sewa << " ";
		outfile << temp.biaya << endl;
		outfile.close();
		
	}
	else{
		sewa();
	}
}

void log_sewa(){
	system("cls");
	int i,j;
	char detail;
	ifstream infile;

	infile.open("db_pelanggan/db_pelanggan.txt", ios::in);
	i=0;
	while(!infile.eof()){ //read dari file db_pelanggan.txt ke array arrpelanggan[]
		infile 
		>> arrpelanggan[i].nama
		>> arrpelanggan[i].id
		>> arrpelanggan[i].alamat
		>> arrpelanggan[i].motorr.nama
		>> arrpelanggan[i].tgl_sewa.dd >> arrpelanggan[i].tgl_sewa.mm >> arrpelanggan[i].tgl_sewa.yyyy
		>> arrpelanggan[i].tgl_kembali.dd >> arrpelanggan[i].tgl_kembali.mm >> arrpelanggan[i].tgl_kembali.yyyy
		>> arrpelanggan[i].lama_sewa
		>> arrpelanggan[i].biaya;
		i++;
	}
	infile.close();

	cout << "+---+----------------------+--------------+-----------------+-----------+------------+" << endl;
	cout << "| No|    Nama Penyewa      | Tanggal Sewa | Tanggal Kembali | Lama Sewa |    Biaya   |" << endl;
	cout << "+---+----------------------+--------------+-----------------+-----------+------------+" << endl;
	for(j=0;j<i-1;j++){
		cout << "|" << setw(3) << j+1;
		cout << "| " << setw(20) << arrpelanggan[j].nama;
		cout << " | " << setw(4) << arrpelanggan[j].tgl_sewa.dd << "-" << setw(2) << arrpelanggan[j].tgl_sewa.mm << "-" << setw(4) << arrpelanggan[j].tgl_sewa.yyyy; 
		cout << " | " << setw(7) << arrpelanggan[j].tgl_kembali.dd << "-" << setw(2) << arrpelanggan[j].tgl_kembali.mm << "-" << setw(4) << arrpelanggan[j].tgl_kembali.yyyy; 
		cout << " | " << setw(3) << arrpelanggan[j].lama_sewa << " Hari ";
		cout << " | " << "Rp" << setw(8) << arrpelanggan[j].biaya;
		cout << " |" << endl;
	}
	cout << "+---+----------------------+--------------+-----------------+-----------+------------+" << endl;

	cout << "Ingin melihat detail ? [y/t] > "; cin >> detail;
	if(detail == 'y'  || detail == 'Y'){
		cout << "+---+----------------------+----------------------+----------------------+----------------------+" << endl;
		cout << "| No|    Nama Penyewa      |          ID          |        Alamat        |      Nama Motor      |" << endl;
		cout << "+---+----------------------+----------------------+----------------------+----------------------+" << endl;
		for(j=0;j<i-1;j++){
			cout << "|" << setw(3) << j+1;
			cout << "| " << setw(20) << arrpelanggan[j].nama;
			cout << " | " << setw(20) << arrpelanggan[j].id;
			cout << " | " << setw(20) << arrpelanggan[j].alamat;
			cout << " | " << setw(20) << arrpelanggan[j].motorr.nama;
			cout << " |" << endl;
		}
		cout << "+---+----------------------+----------------------+----------------------+----------------------+" << endl;
	}


}

void pengembalian(){

}

