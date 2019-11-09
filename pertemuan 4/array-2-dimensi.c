#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


	struct MHS{
		char npm[11];
		float ipk;
	};
	
int main(int argc, char *argv[]) {
	/*int arr[20];
	int i;
	int input;
	srand(time(0));
	//Input
	printf("Generating Array!\n");
	for(i=0;i<20;i++){
		arr[i] = rand() %100+1;
	}
	printf("\n\n");
	
	//urut
	printf("Showing Ordered Array!\n");
	for(i=0;i<20;i++){
		printf("Array ke-%d : %d\n",i,arr[i]);
	}
	printf("\n\n");
	
	//terbalik
	printf("Showing Reversed Array!\n");
	for(i=19;i>=0;i--){
			printf("Array ke-%d : %d\n",i,arr[i]);
	}
	printf("\n\n");
	
	
	
	//Search
	printf("Mencari Dari Array!\n");
	scanf("%d",&input);
	fflush(stdin);
	i=0;
	
	while((i<=20){
		if(arr[i]==input){
			printf("bilangan %d ada dalam input",input);
			break;
		}else if((i==20)&&(arr[i]!=input)){
			printf("Data tidak ada");
			break;
		}
		i++;
	}
	*/
	
	/*
	char npm[10][11]={"18081010001","18081010002","18081010003","18081010004","18081010005","18081010006","18081010007","18081010008","18081010009","18081010010"};
	float ipk[10]={4.0,1.0,3.0,4.0,1.5,2.5,3.5,4.5,3.4,1.5};
	int i;
	char input_npm[11];
	srand(time(0));
	
								Biasa
	//Search
	printf("Mencari Dari Array!\n");
	scanf("%s",&input_npm);
	fflush(stdin);
	i=0;
	
	while(i<=10){
		if(strcmp(npm[i],input_npm)==1){
			printf("npm %s memiliki IPK %f",input_npm,ipk[i]);
			break;
		}else if((i==10)&&(npm[i]!=input_npm)){
			printf("Data tidak ada");
			break;
		}
		i++;
	}
	*/

	//search
		struct MHS mahasiswa[10];

	int i;
	char input_npm[11];
	char ex[11]={"18081010001"};
	for(i=0;i<10;i++){
		strcpy(mahasiswa[i].npm,ex[10]++);
		//mahasiswa[i].ipk
		printf("%s\n",mahasiswa[i].npm);
	}

	printf("Mencari Dari Array!\n");
	scanf("%s",&input_npm);
	fflush(stdin);
	i=0;
	/*
	while(i<=10){
		if(strcmp(npm[i],input_npm)==1){
			printf("npm %s memiliki IPK %f",input_npm,ipk[i]);
			break;
		}else if((i==10)&&(npm[i]!=input_npm)){
			printf("Data tidak ada");
			break;
		}
		i++;
	}
	*/

	return 0;
}
