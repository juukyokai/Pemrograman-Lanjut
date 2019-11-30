#include <stdio.h>
#include <stdlib.h>



/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int find(int top,int bot,int data[100],int search){
	if(data[top]==search){
		return top;
	}
	else{
		top++;
	}
	if(top == bot){
		return 0;
	}
	else {
		find(top,bot,data,search);
	}
}



int main(int argc, char *argv[]) {
	
	int i,j,k,cari,case1,case2,n;
	int index=-1;
	int loop = 0;
	printf("Masukkan banyak data : ");
	scanf("%d",&n);
	int data[n];
	
	srand(time(0));
	
	//create random array
	for(i=0;i<n;i++){
		data[i] = rand() %100+1;
	}
	//Ditampilin
	printf("{ ");
	for(i=0;i<n;i++){
		printf("%d,",data[i]);
	}
	printf(" }\n");
	
	int top = 0, bot = (n-1), mid=(top + bot)/2;
	while(loop == 0){
	printf("Masukkan data yang ingin dicari : ");
	scanf("%d",&cari);
	index = find(top,bot,data,cari);
	if(index != -1 ){
		loop=1;	
	}
	}
	printf("index = %d",index);
	double parent,childL,childR;
	parent = ((double)index-1)/2;
	childL = (2*(double)index)+1;
	childR = (2*(double)index)+2;
	//parent
	if(parent < 0 ){
		printf("parent tidak ada\n");
	}else {
		printf("parent %d adalah %d\n",cari,data[(int)parent]);
	}
	//childL
	if(childL > (n-1) ){
		printf("child left tidak ada\n");
	}else {
		printf("child left %d adalah %d\n",cari,data[(int)childL]);
	}
	//childR
	if(childR > (n-1) ){
		printf("child right tidak ada\n");
	}else {
		printf("child right %d adalah %d\n",cari,data[(int)childR]);
	}
	
	
	
	
	return 0;
}
