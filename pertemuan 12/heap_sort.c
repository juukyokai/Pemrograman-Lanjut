#include <stdio.h>
#include <stdlib.h>

void tukar(int data[],int i,int j){
	int temp;
	temp = data[i];
	data[i] = data[j];
	data[j] = temp;
}

void max_heap(int data[],int n,int root){
	int besar = root;
	int childL = (2*root)+1;
	int childR = (2*root)+2;
	
	if(childL < n && data[childL] > data[besar]){
		besar = childL;
	}
	if(childR < n && data[childR] > data[besar]){
		besar = childR;
	}

	if (besar != root){
		tukar(data,root,besar);
		max_heap(data,n,besar);
	}
}

void min_heap(int data[],int n,int root){
	int kecil = root;
	int childL = (2*root)+1;
	int childR = (2*root)+2;
	
	if(childL < n && data[childL] < data[kecil]){
		kecil = childL;
	}
	if(childR < n && data[childR] < data[kecil]){
		kecil = childR;
	}
	
	if (kecil != root){
		tukar(data,root,kecil);
		min_heap(data,n,kecil);
	}
}

void heap_sort(int n,int data[],int pil){
	int i,j;
	//max heap ascending sort
	if(pil == 1){
		for(i = n / 2 - 1 ; i>=0; i--){
			max_heap(data,n,i);
		}	
		for(i=n - 1; i>=0; i--){
			tukar(data,0,i);
			max_heap(data,i,0);
		}
		//Ditampilin
		printf("ascending : \n");
		printf("{ ");
		for(i=0;i<n;i++){
			printf("%d ",data[i]);
		}
		printf(" }\n");
	}
	//min heap descending sort
	else{
		for(i = n/2-1; i>=0; i--){
			min_heap(data,n,i);
		}	
		for(i=n-1; i>=0; i--){
			tukar(data,0,i);
			min_heap(data,i,0);
		}
		//Ditampilin
		printf("descending : \n");
		printf("{ ");
		for(i=0;i<n;i++){
			printf("%d ",data[i]);
		}
		printf(" }\n");		
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
	
	//heap_sort ascending
	heap_sort(n,data,1);
	//heap_sort descending
	heap_sort(n,data,0);
	
	return 0;
}
