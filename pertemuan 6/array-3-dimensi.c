#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char *argv[]) {
	int loop=1;
	int inp_case;
	int i,j,k; // for variabel
	int g=2; // banyak garis
	int t=3; // banyak koordinat
	int d=3; //banyak dimensi
	int krdnt[g][t][d]; //array
	double hsl_jarak[g][t-1];
	double hsl_total[g];
	double selisih[d];
	srand(time(0));
	
	while(loop==1){
	printf("====================================\n");
	printf("============Jarak Koordinat=========\n");
	printf("====================================\n\n");
		printf("Menu : \n\t1. Create data\n\t2. View data\n\t3. Hitung data\n\t4. hasil hitung\n");
		scanf("%d",&inp_case);
		switch(inp_case){
			case 1://Input data
				for(i=0;i<g;i++){
					for(j=0;j<t;j++){
						for(k=0;k<d;k++){
						krdnt[i][j][k]= rand() %10+(-1);	
								
						}
					}
				}
				break;
			case 2://View Data
				for(i=0;i<g;i++){
					printf("garis ke ke - %d\n",i);
						printf("====================================\n");
						printf("x	y	z\n");
					for(j=0;j<t;j++){
						
						for(k=0;k<d;k++){
						printf("%d	",krdnt[i][j][k]);
						}printf("koordinat ke - %d\n",j);
					}
					printf("\n==================Lol==============\n");
				}
				break;
			case 3://hitung data
				for(i=0;i<g;i++){
					for(j=0;j<(t-1);j++){
						for(k=0;k<d;k++){
							selisih[k]=(double) krdnt[i][j+1][k] - krdnt[i][j][k];
						}
						hsl_jarak[i][j]=sqrt(pow((selisih[0]),2)+pow(selisih[1],2)+pow(selisih[2],2));
						hsl_total[i]=hsl_total[i]+hsl_jarak[i][j];
					}
					
				}	
				break;
			case 4://Hasil hitung
				for(i=0;i<g;i++){
					printf("garis ke ke - %d\n",i);
					printf("====================================\n");
					for(j=0;j<(t-1);j++){
						printf("dari titik %d - %d : %lf\n",j,j+1,hsl_jarak[i][j]);
					}
					printf("totalnya adalah : %lf\n",hsl_total[i]);
				}
				break;
		}
		
		
		printf("apakah anda ingin mengulang? (1.ya/2.tidak)");
		scanf("%d",&loop);
		system("cls");		
	}
	printf("makasih :D");

	return 0;
}
