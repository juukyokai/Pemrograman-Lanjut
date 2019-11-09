#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct mahasiswa{
		char nama[15];
		char npm[15];
		char jurusan[20];
		char angkatan[5];
	};
	typedef struct mahasiswa mahasiswa;


int main(int argc, char *argv[]) {
	mahasiswa a;
	int x=10;
	int *px;
	int i[10];
	int j=0;

	strcpy(a.nama,"Faisal");
	strcpy(a.npm,"18081010001");
	strcpy(a.jurusan,"informatika");
	strcpy(a.angkatan,"2018");

	printf("\nnama mahasiswa : %s",a.nama);
	printf("\nNpm : %s",a.npm);
	printf("\njurusan : %s",a.jurusan);
	printf("\nAngkatan : %s\n",a.angkatan);


	//Pointer
	printf("\n alamat memori a : %d  ",x);
	px = &x;
	printf("\n alamat memori a : %d  ",*px);

	printf("\n alamat memori a : %d",&a.nama);
	printf("\n alamat memori a : %d",&a.npm);

	printf("\n\n");
	for(j=0;j<10;j++){
		printf("alamat i[%d] : %d\n",j,&i[j])	;
	};

	return 0;
}
