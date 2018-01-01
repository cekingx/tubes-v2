#ifndef PELANGGAN_H_
#define PELANGGAN_H_

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include "lib.h" //type tanggal
#include "motor.h"  //type motor
#include "menu.h" // fungsi lama_sewa()


typedef struct{
	char nama[20];
       char id[20];
       char alamat[20];
       motor motorr;
       tanggal tgl_sewa;
       tanggal tgl_kembali;
       int lama_sewa;
       int biaya;
}pelanggan;


void sewa();
void log_sewa();
void pengembalian();


#endif