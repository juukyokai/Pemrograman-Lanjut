#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int binary_rekursif(int data[100],int n,int top,int mid,int bot,int search){
	int a= data[top],b= data[mid],c= data[bot];
		if(b<search){
			top = mid + 1;
		}else{
			bot = mid - 1;
		}
		mid = (top + bot)/2;
		printf("a %d top %d\n",a,top);
		printf("b %d mid %d\n",b,mid);
		printf("c %d bot %d\n",c,bot);
		
		if((a==b&&b==c) && search != b){
				printf("data tidak ada\n");
				return 0;
		}else if(search==b || search==a || search==c){
			printf("data ada \n");
			return search;
		}
		getch();
		binary_rekursif(data,n,top,mid,bot,search);
}



int main(int argc, char *argv[]) {
	int i,j,k,search,n=100;
	int data[n];
	srand(time(0));
	
	//create random array
	for(i=0;i<n;i++){
		data[i] = rand() %100+1;
	}
	
	
	
	//sort
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
	scanf("%d",&search);
	fflush(stdin);
	/*										//Sequential search
	printf("\nJika terdapat data input maka tercetak 'ada' \n");
	for(i=0;i<100;i++){
		if(data[i]==search){
			printf("\nada");
			break;
		}
		else if(i==99){
			printf("data tidak ada");
		}
	}
	
	*/
	
	/*								//Sequential search with sentinel
	data[100]=search;
	i = 0;
	printf("\nJika terdapat data input maka tercetak 'ada' \n");
	while(data[i] != search){
		i++;
	}
	if(i<=99){
			printf("data 'ada' \n");
		}
		else printf("data tidak ada\n");
	*/
	
	
										//Binary search
	
	
	int a,b,c;
	int top = (n-n), bot =(n-1),mid=(top + bot)/2;
	//Biasa
	while ((search != b || search != c || search != a)){
	a= data[top];
	b= data[mid];
	c= data[bot];
		if(b<search){
			top = mid + 1;
		}else{
			bot = mid - 1;
		}
		mid = (top + bot)/2;
		if((a==b&&b==c) && search != b){
				printf("data tidak ada\n");
				break;
		}else if(search==b || search==a || search==c){
			printf("data ada \n");
			break;
		}
	}
	
	//Rekursif
	/*
	binary_rekursif(data,n,top,mid,bot,search);
	*/

	return 0;
}
