#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mahasiswa{
	char nama[20];
	float IPS[10];
	int mk_diikuti[10];
	float ipk;
};

int main(int argc, char *argv[]) {
	char nama_matkul[10][25]={"Bela negara","Pemrograman Lanjut","Sistem Operasi","Pancasila","Kewirausahaan"};
	char bob_matkul[10]={3,4,4,2,3};
	struct mahasiswa mhs[10];
	int loop=1;
	int loop2=0;
	int inp_case;
	int in_mk;
	int i=0;
	int j=0;
	int a=0;
	int b=0;
	float total_IP=0;
	float total_bobot=0;
	srand(time(0));
	
	while (loop==1){
	printf("===================================\n");
	printf("============Data Mahasiswa=========\n");
	printf("===================================\n\n");
		printf("Menu : \n\t1. Create data\n\t2. View data\n");
		scanf("%d",&inp_case);
		
		switch(inp_case){
			case 1: //Input data mahasiswa
			{
				j=0;
				loop2=0;
				printf("Input nama mahasiswa : ");
				scanf("%s",&mhs[i].nama);
				while(loop2<4){
					printf("Piliha matkul ke - %d : \n\t1. Bela Negara\n\t2. Pemrograman Lanjut\n\t3. Sistem Operasi\n\t4. Pancasila\n\t",j+1);
					scanf("%d",&mhs[i].mk_diikuti[j]);	
					mhs[i].IPS[j] = rand() %4+1;
					j++;
					loop2++;
				}
				for(a=0;a<j;a++){
					total_IP		= total_IP		+ ((mhs[i].IPS[a])*(bob_matkul[mhs[i].mk_diikuti[a]]));
					total_bobot		= total_bobot	+ bob_matkul[mhs[i].mk_diikuti[a]];
				}
				mhs[i].ipk=total_IP/total_bobot;
				i++;
				system("cls");
			}
				break;
			case 2: // Cek IPK
			{
				printf("Data Nasabah	 \n");
				for(a=0;a<i;a++){
					printf("Nama		: %s\n",mhs[a].nama);
					for(b=0;b<4;b++){
						printf("\tMK %s	\tnilai : %f \n",nama_matkul[mhs[a].mk_diikuti[b]],mhs[a].IPS[b]);
					}
					printf("IPK			: %f\n",mhs[a].ipk);
				}
				
			}
				break;
			default:
				printf("Input salah lol !!");
				break;

		}
	}
	return 0;
}
