#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



int pangkat(int m, int n){
	if(n == 1){
		return m;
	}
	else{
		return m*pangkat(m,(n-1));
	}
}


int main(int argc, char *argv[]) {
	int m,n;
	int hasil=1;
	int i=0;

	printf("Masukkan Angka : ");
	scanf("%d",&m);
	printf("dipangkatkan : ");
	scanf("%d",&n);

	printf("Hasil rekursifnya adalah %d\n",pangkat(m,n));

	for(i=0;i<n;i++){
		hasil=hasil*m;
	}

	printf("Hasil dari iterasi biasa adalah %d\n",hasil);

	return 0;
}
