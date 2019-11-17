#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

int main(int argc, char *argv[]) {
	int cari,i,j,k,n=10,kecil,besar,temp;
	int data[10];
	
	srand(time(0));
	
	//create random array
	for(i=0;i<n;i++){
		data[i] = rand() %10+1;
	}
   //Ditampilin
   printf("Data : \n");
	for(i=0;i<n;i++){
		printf("%d.  %d \n",(i+1),data[i]);
	}	
	//sort ascending
	for (i = 0; i < n; i++){
	 		kecil= i;
            for (j = i + 1; j < n; j++){
                if (data[j] < data[kecil]){
                    kecil = j;
                }
                
            }
            //system("cls");
            printf("temp : %d\n",kecil);
            printf("data[%d] : %d\n",i+1,data[i]);
            printf("data[kecil] : %d",data[kecil]);
            temp = data[i]; 
            data[i] = data[kecil];
            data[kecil] = temp;
    }
    
	printf("\n\n Ascending\n");    
    //Ditampilin
	for(i=0;i<n;i++){
		printf("%d.  %d \n",(i+1),data[i]);
	}
	
	//sort descending
	for (i = 0; i < n; i++){
	 		besar= i;
            for (j = i + 1; j < n; j++){
                if (data[j] > data[besar]){
                    besar = j;
                }
            }
            temp = data[i]; 
            data[i] = data[besar];
            data[besar] = temp;
    }
    
	printf("\n\n Descending\n");    
    //Ditampilin
	for(i=0;i<n;i++){
		printf("%d.  %d \n",(i+1),data[i]);
	}
	
	
	
	return 0;
}
