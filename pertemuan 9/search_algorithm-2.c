#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int interpolation(int data[100],int n,int top,double posisi,int bot,int search){
	int pos = (int)posisi;
	int a= data[top],b= data[pos],c= data[bot];

	if((data[pos+1]>search) && b<search){
		printf("data tidak ada\n");
		return 0;
	}else if(search==b || search==a || search==c){
		printf("data ada \n");
		return 1;
	}

		if(b<search){
			top = pos + 1;
		}else{
			bot = pos - 1;
		}
		posisi=(double)(((search-a)/(c-a)*(bot-top))+top);

	interpolation(data,n,top,posisi,bot,search);
}



int main(int argc, char *argv[]) {
	int i,j,k,search,n=100;
	int data[n];
	srand(time(0));
	
	//create random array
	for(i=0;i<n;i++){
		data[i] = rand() %100+1;
	}
	
	
	
	//bubble sort
	 for (i = 0; i < n; ++i){
            for (j = i + 1; j < n; ++j){
                if (data[i] > data[j]){
                    k =  data[i];
                    data[i] = data[j];
                    data[j] = k;
                }
            }
        }
    //Ditampilin
	for(i=0;i<n;i++){
		printf("%d.  %d \n",(i+1),data[i]);
	}
	
	
	
	printf("Masukkan data yang ingin dicari : (int)\n");
	fflush(stdin);
	scanf("%d",&search);
	double a,b,c;
	double posisi =99;
	int top = 0, bot =n-1;
	a=(double)search-data[top];
	b=(double)data[bot]-data[top];
	c=(double)bot-top;
	posisi=(double)(((a/b)*c)+top);
	interpolation(data,n,top,posisi,bot,search);

	return 0;
}
