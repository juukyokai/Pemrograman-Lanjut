#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	char nama[30];
	char npm[11];
	char fkt[20];
	char alamat[30];
	int umur;
	int jum_sks;
	int berat_badan;
	int loop=1;
	while(loop==1){
		printf("==================================\n");
		printf("====Sistem Pengisian Data Diri====\n");
		printf("==================================\n");

		printf("Masukkan Nama Anda\t\t\t: ");
		scanf("%[^\n]",&nama);
		fflush(stdin);
		printf("Masukkan NPM  Anda\t\t\t: ");
		scanf("%s",&npm);
		fflush(stdin);

		printf("Masukkan Fakultas Anda \t\t\t: ");
		scanf("%[^\n]",&fkt);
		fflush(stdin);

		printf("Masukkan Alamat Anda \t\t\t: ");
		scanf("%[^\n]",&alamat);
		fflush(stdin);
		printf("Masukkan Umur Anda \t\t\t: ");
		scanf("%d",&umur);
		fflush(stdin);
		printf("Masukkan Berat Badan Anda \t\t: ");
		scanf("%d",&berat_badan);
		fflush(stdin);

		printf("Masukkan Jumlah SKS Anda Semester ini \t: ");
		scanf("%d",&jum_sks);

		fflush(stdin);
		printf("\n\n");

		printf("DATA YANG TELAH ANDA MASUKKAN \n");
		printf("Nama \t\t\t: %s\n",nama);
		printf("NPM \t\t\t: %s\n",npm);
		printf("Fakultas \t\t: %s\n",fkt);
		printf("Alamat \t\t\t: %s\n",alamat);
		printf("Jumlah Sks smt ini \t: %d\n",jum_sks);
		printf("Umur\t\t\t: %d\n",umur);
		printf("Berat Badan \t\t: %d\n",berat_badan);
		printf("Apakah Anda ingin melakukan pengisian data kembali? \n1.ya\n2.tidak\n");
		scanf("%d",&loop);
		fflush(stdin);
		if(loop==1){system("cls");}
	}
		printf("===================================\n");
		printf("============Terima Kasih===========\n");
		printf("===================================\n");
	return 0;
}
