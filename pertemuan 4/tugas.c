#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


	struct tgl_lahir {
		int tanggal;
		int bulan;
		int tahun;
	};
	struct alamat {
		char jalan[40];
		char kota[20];
		char provinsi[20];
	};
	struct rekening {
		char no_rek[12];
		long int saldo;
		char nama[20];
		char bank[10];
		struct tgl_lahir tgl_lahir;
		int umur;
		struct alamat alamat;
	};
	
int main(int argc, char *argv[]) {
	int index=0;
	int skrg=2019;
	int i=0;
	int j;
	int input;
	char convert[128];
	int loop=1;
	int inp_case;
	int total=0;
	long int max,min;
	int in_serbgn;
	char ch_serbgn[20];
	struct rekening rek[10];
	srand(time(0));
	
	
	while(loop==1){
	printf("===================================\n");
	printf("=========Pendataan Nasabah=========\n");
	printf("===================================\n\n");
		printf("Menu : \n\t1. Create data\n\t2. View data\n\t3. Search saldo\n\t4. Saldo total, max dan min\n\t5. Search Umur \n\t6. Search kota\n");
		scanf("%d",&inp_case);
		
		switch(inp_case){
		case 1:				//Create data
			{
				printf("Input nama : ");
				scanf("%s",&rek[i].nama);
				rek[i].saldo = rand() %100000000+100000;
				printf("Input nama bank : \n\t1. BNI\n\t2. BCA\n\t3. Mandiri\n");
				scanf("%d",&input);
				switch(input){
					case 1:
						strcpy(rek[i].bank,"BNI");
						strcpy(rek[i].no_rek,"001");
						break;
					case 2:
						strcpy(rek[i].bank,"BCA");
						strcpy(rek[i].no_rek,"002");
						break;
					case 3:
						strcpy(rek[i].bank,"Mandiri");
						strcpy(rek[i].no_rek,"003");
						break;
					default:
						printf("Input salah!!!");
						break;
				}
					printf("Input tanggal lahir : \n");
					printf("\tTanggal		: ");
					scanf("%d",&rek[i].tgl_lahir.tanggal);	
					printf("\tBulan		: ");
					scanf("%d",&rek[i].tgl_lahir.bulan);
					printf("\tTahun		: ");
					scanf("%d",&rek[i].tgl_lahir.tahun);
					fflush(stdin);
					
					rek[i].umur = skrg - rek[i].tgl_lahir.tahun;
					
						printf("Input Alamat rumah : \n");
						printf("\tAlamat		: ");
						scanf("%[^\n]",&rek[i].alamat.jalan);	
						fflush(stdin);
						printf("\tKota		: ");
						scanf("%[^\n]",&rek[i].alamat.kota);
						fflush(stdin);
						printf("\tProvinsi	: ");
						scanf("%[^\n]",&rek[i].alamat.provinsi);
						fflush(stdin);
																			//Generating random no_rek
										strcat(rek[i].no_rek,itoa(rand()%512+128,convert,10));
										if(rek[i].tgl_lahir.tanggal<10){
											strcat(rek[i].no_rek,"0");
										}
										strcat(rek[i].no_rek,itoa(rek[i].tgl_lahir.tanggal,convert,10));	
										if(rek[i].tgl_lahir.bulan<10){
											strcat(rek[i].no_rek,"0");
										}
										strcat(rek[i].no_rek,itoa(rek[i].tgl_lahir.bulan,convert,10));
										if((rek[i].tgl_lahir.tahun%100)<10){
											strcat(rek[i].no_rek,"0");
										}
										strcat(rek[i].no_rek,itoa((rek[i].tgl_lahir.tahun)%10,convert,10));
										printf("%s\n",rek[i].no_rek);
										fflush(stdin);
				
				i++;
			}
			break;
		case 2:				//tugas 1 view data
		{
			printf("Data Nasabah	 \n");
			for(j=0;j<i;j++){
				printf("Nama		: %s\n",rek[j].nama);
				printf("Nama Bank	: %s\n",rek[j].bank);
				printf("No Rek		: %s\n",rek[j].no_rek);
				printf("Umur		: %d\n",rek[j].umur);
				printf("Tgl Lahir	: %d-%d-%d\n",rek[j].tgl_lahir.tanggal,rek[j].tgl_lahir.bulan,rek[j].tgl_lahir.tahun);
				printf("Alamat		: Jl.%s Kota %s Provinsi %s\n",rek[j].alamat.jalan,rek[j].alamat.kota,rek[j].alamat.provinsi);
				printf("Saldo 		: %d\n",rek[j].saldo);
				printf("\n\n");
				}	
		}
			break;
		case 3:				//tugas 2 search range saldo dengan input user
		{
			printf("Masukkan input saldo : ");
			scanf("%d",&in_serbgn);
			for(j=0;j<i;j++){
				if(rek[j].saldo<in_serbgn){
					printf("Nama %s saldo kurang dari %d\n",rek[j].nama,in_serbgn);
				}else{
					printf("Nama %s saldo lebih dari %d\n",rek[j].nama,in_serbgn);
				}
				}
		}
			break;
		case 4:				//tugas 3 saldo total dan max-min
		{
			max = rek[0].saldo;
			min = rek[0].saldo;
			for(j=0;j<i;j++){
				total = total + rek[j].saldo;
				if(rek[j].saldo<min){
					min = rek[j].saldo;
				}else if(rek[j].saldo>max){
					max = rek[j].saldo;
				}
			}
			printf("Total Saldo 	: %d\n",total);
			printf("Saldo Max 		: %d\n",max);
			printf("Saldo Min 		: %d\n",min);
		}
			break;
		case 5:				//tugas 4 search range umur dengan input user
		{
			printf("Masukkan Range Umur :");
			scanf("%d",&in_serbgn);
			for(j=0;j<i;j++){
				if(rek[j].umur<in_serbgn){
					printf("Nama %s umur kurang dari %d\n",rek[j].nama,in_serbgn);
				}else {
					printf("Nama %s umur lebih dari %d\n",rek[j].nama,in_serbgn);
				}
				}	
		}
			break;
		case 6:				//tugas 5 search nasabah dengan kota
		{
			printf("Masukkan input kota : ");
			scanf("%s",&ch_serbgn);
			fflush(stdin);
			for(j=0;j<i;j++){
				if(strcmp(rek[j].alamat.kota,ch_serbgn)==0){
					printf("Nama %s ada pada kota %s\n",rek[j].nama,ch_serbgn);
				}
				}
		}
			break;
		default:
			printf("Input salah lol :P");
			break;
		}	
		
		printf("\napakah anda ingin mengulang? (1. Ya/2. Tidak)");
		scanf("%d",&loop);
		system("cls");
	}
	
	printf("===================================\n");
	printf("===========Terima Kasih============\n");
	printf("===================================\n");
	

	return 0;
}
