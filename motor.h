#ifndef MOTOR_H_
#define MOTOR_H_

#include <iostream>
#include <fstream>
#include <cstdlib>

typedef struct{
	char nama[20];
	char plat[11];
	int cc;
	int tahun;
}motor;

motor arrmotor[30];

void tb_motor();
void tambah_motor();
void edit_motor();
void hapus_motor();

#endif