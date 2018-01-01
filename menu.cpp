#include "menu.h"

using namespace std;

int main(){

	log_sewa();

	return 0;
}

int lama_sewa(tanggal tgl_sewa, tanggal tgl_kembali){
       int total1, total2, total;
       int bln1 = 0, bln2 = 0;
       int bln[]={31,28,31,30,31,30,31,31,30,31,30,31};
       int i;
       int j;

       if(tgl_sewa.mm==1){
              bln1=0;
       }
       else{
              for(i=0;i<tgl_sewa.mm-1;i++)
                     bln1=bln1+bln[i];
       }
       total1=bln1+tgl_sewa.dd;

       if(tgl_kembali.mm==1){
              bln2=0;
       }
       else{
              for(j=0;j<tgl_kembali.mm-1;j++)
                     bln2=bln2+bln[j];
       }
       total2=bln2+tgl_kembali.dd;

       total=((tgl_kembali.yyyy-tgl_sewa.yyyy)*365)+(total2-total1);
       return total;
}