#ifndef MOTOR_H_
#define MOTOR_H_

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <iomanip>

typedef struct{
	char nama[20];
	char plat[15];
	int cc;
	int tahun;
}motor;

motor arrmotor[30];

void tambah_motor();
void tb_motor();
void edit_motor();
void hapus_motor();

#endif