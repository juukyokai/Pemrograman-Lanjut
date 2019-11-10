#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>
struct kontainer{
	double ukuran;
	double berat;
	char vendor[15];
	char tipe_muatan;
};

int main(int argc, char *argv[]) {
	struct kontainer kon[10];
	struct kontainer blok_a[10];
	struct kontainer blok_b[10];
	struct kontainer blok_c[10];
	
	int i=0;
	int inp_case;
	int index_inp=0;
	int index_a=0,index_b=0,index_c=0;
	char loop = 'Y';
	
	while(loop != 'N'){
		printf("===================================\n");
		printf("============Data Kontainer=========\n");
		printf("===================================\n\n");
		printf("\t\t\t\t\t note : harap nyalakan capslock\n");
		printf("Menu : \n\t1. Create data\n\t2. View data\n\t3. Sort Data \n\t4. View Sorted Data\n");
		scanf("%d",&inp_case);
		switch(inp_case){
			case 1: 			//create
			{
				system("cls");
				printf("Input nama vendor	:	(gunakan '_' untuk mengganti spasi)\n");
				scanf("%s",&kon[index_inp].vendor);
				fflush(stdin);
				printf("Input jenis muatan 	: \n\tA. Electronics\n\tB. Goods\n\tC. Chemical\n");
				scanf("%c",&kon[index_inp].tipe_muatan);
				fflush(stdin);
				printf("Input berat muatan	: ");
				scanf("%lf",&kon[index_inp].berat);
				fflush(stdin);
				printf("Input ukuran muatan	: ");
				scanf("%lf",&kon[index_inp].ukuran);
				fflush(stdin);	
				index_inp++;
			}
			
			
				break;
			case 2:				//view-ALl
			{
				for(i=0;i<index_inp;i++){
				printf("Kontainer ke-%d",(i+1));
				printf("\n\tVendor		: %s",kon[i].vendor);
				switch(kon[i].tipe_muatan){
					case ('A') :
						printf("\n\tJenis Muatan	: Electronics(Tipe %c)",kon[i].tipe_muatan);
						break;
					case ('B') :
						printf("\n\tJenis Muatan	: Goods(Tipe %c)",kon[i].tipe_muatan);
						break;
					case ('C') :
						printf("\n\tJenis Muatan	: Chemicals(Tipe %c)",kon[i].tipe_muatan);
						break;
				}
				printf("\n\tBerat Muatan	: %lf",kon[i].berat);
				printf("\n\tUkuran Muatan	: %lf",kon[i].ukuran);
				printf("\n");
				getch();	
			}
				
			}
			
				break;
			case 3:				//Sorted
			{
				for(i=0;i<index_inp;i++){
					switch(kon[i].tipe_muatan){
						case ('A') :
							blok_a[index_a] = kon[i];
							index_a++;
							break;
						case ('B') :
							blok_b[index_b] = kon[i];
							index_b++;
							break;
						case ('C') :
							blok_c[index_c] = kon[i];
							index_c++;
							break;
					}
				}
				printf("proses selesai !!");
			}
				
				break;
			case 4: 		//View Sorted	
			{
				printf("View Per Blok");
				printf("\n\n\tJenis Muatan Electronics(Tipe A)");
				for(i=0;i<index_a;i++){
					printf("\n\n\tVendor		: %s",blok_a[i].vendor);
					printf("\n\tUkuran Muatan	: %lf",blok_a[i].ukuran);
					printf("\n\tBerat Muatan	: %lf",blok_a[i].berat);
				}
				printf("\n\n\tJenis Muatan Goods(Tipe B)");
				for(i=0;i<index_b;i++){
					printf("\n\n\tVendor		: %s",blok_b[i].vendor);
					printf("\n\tUkuran Muatan	: %lf",blok_b[i].ukuran);
					printf("\n\tBerat Muatan	: %lf",blok_b[i].berat);
				}
				printf("\n\n\tJenis Muatan Chemicals(Tipe C)");
				for(i=0;i<index_c;i++){
					printf("\n\tVendor		: %s",blok_c[i].vendor);
					printf("\n\tUkuran Muatan	: %lf",blok_c[i].ukuran);
					printf("\n\tBerat Muatan	: %lf",blok_c[i].berat);
				}
				break;
				getch();
			}
				
		}
	printf("Ingin Melanjutkan ? (tekan N untuk keluar)");
	fflush(stdin);
	scanf("%c",&loop);	
	
	system("cls");
	}
	printf("Terima Kasih  :)");
	
	
			
	return 0;
}
