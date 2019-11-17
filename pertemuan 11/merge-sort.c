#include <stdio.h>
#include <stdlib.h>

void ascending(int data[], int bot, int mid, int top) 
{ 
    int i, j, k; 
    int n1 = mid - bot + 1; 
    int n2 =  top - mid; 
  
    /* create temp arrays */
    int div[n1], con[n2]; 
  
    /* dividing into temp arrays */
    for (i = 0; i < n1; i++) 
        div[i] = data[bot + i]; 
    for (j = 0; j < n2; j++) 
        con[j] = data[mid + 1+ j]; 
  
    // merging 2 array
    i = 0; // index div
    j = 0; // index con
    k = bot; // index data 
    while (i < n1 && j < n2)  
    { 
        if (div[i] <= con[j]) // Pembanding antar array temp apakah lebih kecil?
        { 
            data[k] = div[i]; 
            i++; 
        } 
        else
        { 
            data[k] = con[j]; 
            j++; 
        } 
        k++; 
    } 
  
    // jadikan satu kedalam data apabila terdapat sisa 
    while (i < n1) 
    { 
        data[k] = div[i]; 
        i++; 
        k++; 
    } 
  
    // jadikan satu kedalam data apabila terdapat sisa 
    while (j < n2) 
    { 
        data[k] = con[j]; 
        j++; 
        k++; 
    } 
} 
  
  void descending(int data[], int bot, int mid, int top) 
{ 
    int i, j, k; 
    int n1 = mid - bot + 1; 
    int n2 =  top - mid; 
  
    /* create temp arrays */
    int div[n1], con[n2]; 
  
    /* dividing into temp arrays */
    for (i = 0; i < n1; i++) 
        div[i] = data[bot + i]; 
    for (j = 0; j < n2; j++) 
        con[j] = data[mid + 1+ j]; 
  
    // merging 2 array
    i = 0; // index div
    j = 0; // index con
    k = bot; // index data 
    while (i < n1 && j < n2)  
    { 
        if (div[i] >= con[j]) // Pembanding antar array temp apakah lebih besar?
        { 
            data[k] = div[i]; 
            i++; 
        } 
        else
        { 
            data[k] = con[j]; 
            j++; 
        } 
        k++; 
    } 
  
    // jadikan satu kedalam data apabila terdapat sisa 
    while (i < n1) 
    { 
        data[k] = div[i]; 
        i++; 
        k++; 
    } 
  
    // jadikan satu kedalam data apabila terdapat sisa 
    while (j < n2) 
    { 
        data[k] = con[j]; 
        j++; 
        k++; 
    } 
} 
void mergeSort(int data[], int bot, int top,int trace) // Membagi data menjadi satuan yang lebih kecil
{ 
    if (bot < top) 
    { 
        int mid = bot+(top-bot)/2; 
  		
        // Sort bagian pertama dan kedua 

        mergeSort(data, bot, mid, trace);
        mergeSort(data, mid+1, top, trace); 
        if(trace == 0){
        	ascending(data, bot, mid, top); 	
		}
        else {
        	descending(data, bot, mid, top); 
		}
        
    } 
} 

int main(int argc, char *argv[]) {
	int cari,i,n=20,trace;
	int data[n];
	srand(time(0));
	
	//Create Random data
	for(i=0;i<n;i++){
		data[i]=rand()%10+1;
	}
	printf("ascending/descending (0/1): %d\n",trace);
	scanf("%d",&trace);
	mergeSort(data,0,n-1,trace);
	printf("\n------merged-----------\n");
	
	//Tampilkan
	printf("Data :\n");
	for(i=0;i<n;i++){
		printf("%d. %d \n",(i+1),data[i]);
	}

	return 0;
}
