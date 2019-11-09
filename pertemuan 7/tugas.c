#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//========================================================

struct node {
	 int data;
    struct node *next;
};
typedef struct node node;

node *createNode(void);
void tambahAwal(node **head);
void tambahData(node **head);
void tranverse(node *head);
void insertNode(node **head, node *pPre, node *pNew);
void deleteNode(node **head, node *pPre, node *pCur);
void hapusData(node **head);
void deleteList(node *head);
void jumlah(node *head);
void hapusData_Akhir(node **head);
void hapusData_Awal(node **head);
void tambahData_Akhir(node **head);

//========================================================

int main()
{
  node *head;
  char pilih;

  head = NULL;
  do{
    //untuk membersihkan tampilan
    //untuk windows
    system("cls");
    //untuk linux
     //system("clear");
     
     printf("masukkan pilihan\n");
     printf("1. tambah data di awal\n");
     printf("2. tambah data di tengah list\n");
     printf("3. hapus data\n");
     printf("4. cetak isi list\n");
     printf("5. Lihat jumlah semua data\n");
     printf("6. hapus data di akhir list\n");
     printf("7. hapus data di awal list\n");
     printf("8. tambah data di akhir list\n");
     printf("MASUKKAN PILIHAN (tekan q untuk keluar) : ");
     fflush(stdin);
     scanf("%c", &pilih);
     if (pilih == '1')
     		tambahAwal(&head);
     else if (pilih == '2')
			tambahData(&head);
     else if (pilih == '3')
     		hapusData(&head);
     else if (pilih == '4'){
     		tranverse(head);
         getch();
     }
     else if (pilih == '5'){
     		jumlah(head);
     	getch();
	 }
	 else if (pilih == '6'){
	 		hapusData_Akhir(&head);
	 	getch();
	 }
	 else if (pilih == '7'){
	 	hapusData_Awal(&head);
	 	getch();
	 }
	 else if (pilih == '8'){
	 	tambahData_Akhir(&head);
	 }
  } while (pilih != 'q');
  deleteList(head);
}
//========================================================

void jumlah(node *head){
   //jumlah data input linked list
	node *pWalker;
	int jumlah=0;
    system("cls");
	pWalker = head;
	while (pWalker != NULL){
   	printf("%d->", pWalker -> data);
   	jumlah=jumlah + pWalker -> data;
   	pWalker = pWalker -> next;
	}
   printf("NULL");
   printf("\n Jumlah : %d",jumlah);
}

//========================================================

void hapusData_Akhir(node **head){
	node *hapus,*temp;
	system("cls");
	if(*head == NULL){
		printf("Data Kosong lol");
		getch();
		return;
	}
	tranverse(*head);
	hapus = *head;
	temp = NULL;
	while(hapus -> next != NULL){
		temp = hapus;
		hapus = hapus -> next;
	}
	free(hapus);
	temp -> next = NULL;
	getch();
}

//========================================================

void hapusData_Awal(node **head){
	node *hapus;
	system("cls");
	if(*head == NULL){
		printf("Data Kosong lol");
		getch();
		return;
	}
	tranverse(*head);
	hapus=*head;
	*head = hapus->next;
	free(hapus);
	getch();
	
}
//========================================================

void tambahData_Akhir(node **head){
	node *tambah,*pTemp;
	int bil;
	system("cls");
	tambah = *head;
	pTemp = NULL;
	fflush(stdin);
  	printf("masukkan bilangan integer : ");
  	fflush(stdin);
  	scanf("%d", &bil);
  	pTemp = (node *)malloc(sizeof(node));
  	if (pTemp == NULL){
	  	    printf("\nalokasi memeori gagal");
		    getch();
		    return ;
	}
  	//Awal
  	if(*head == NULL){
		 pTemp->data = bil;
	     pTemp->next = NULL;
	     insertNode(head, NULL, pTemp);
	}
	//Akhir
	else {
		while(tambah != NULL && tambah -> next != NULL){
			tambah = tambah -> next;
		}
		     pTemp->data = bil;
		     pTemp->next = NULL;
		     insertNode(head, tambah, pTemp);
	}
	
		
}

//========================================================
node *createNode(void){
  node *ptr;

  ptr = (node *)malloc(sizeof(node));
  return(ptr);
}

//========================================================

void tambahAwal(node **head){
  int bil;
  node *pTemp;

  //untuk membersihkan tampilan
  //untuk windows
  system("cls");
  //untuk linux
  //system("clear");
  fflush(stdin);
  printf("masukkan bilangan integer : ");
  fflush(stdin);
  scanf("%d", &bil);
  pTemp = (node *)malloc(sizeof(node));

  if (pTemp != NULL){
  		pTemp->data = bil;
      pTemp->next = NULL;
      insertNode(head, NULL, pTemp);
  }
  else{
      printf("Alokasi memori gagal");
      getch();
  }
}

//========================================================

void tambahData(node **head){
  int pos, bil;
  node *pTemp, *pCur;

  //untuk membersihkan tampilan
  //untuk windows
  system("cls");
  //untuk linux
  //system("clear");
  
  tranverse(*head);
  printf("\nposisi penyisipan setelah data bernilai : ");
  fflush(stdin);
  scanf("%d", &pos);
  printf("\nData yang disisipkan : ");
  fflush(stdin);
  scanf("%d", &bil);

  pCur = *head;
  while (pCur != NULL && pCur -> data != pos) {
    pCur = pCur -> next;
  }

  pTemp = (node *)malloc(sizeof(node));

  if (pCur == NULL){
     printf("\nnode tidak ditemukan");
     getch();
  }
  else if (pTemp == NULL){
     printf("\nalokasi memeori gagal");
     getch();
  }
  else{
     pTemp->data = bil;
     pTemp->next = NULL;
     insertNode(head, pCur, pTemp);
  }
}

//========================================================

void tranverse(node *head){
   //traverse linked list
	node *pWalker;

    system("cls");
	pWalker = head;
	while (pWalker != NULL){
   	printf("%d->", pWalker -> data);
   	pWalker = pWalker -> next;
	}
   printf("NULL");
}

//========================================================

void insertNode(node **head, node *pPre, node *pNew){
    if (pPre == NULL){
       //menambahkan diawal atau pada empty list
	    pNew -> next = *head;
       *head = pNew;
    }
    else {
       //menambahkan node di tengah atau di akhir
       pNew -> next = pPre -> next;
       pPre -> next = pNew;
   }
}

//========================================================

void deleteNode(node **head, node *pPre, node *pCur)
{
	if (pPre == NULL)
	   *head = pCur -> next;
	else
       pPre -> next = pCur -> next;
	free(pCur);
}

//========================================================

void hapusData(node **head)
{
  int pos;
  node *pCur, *pPre;

  //clrscr();
  system("cls");
  tranverse(*head);
  printf("\nData yang akan dihapus : ");
  fflush(stdin);
  scanf("%d", &pos);

  pPre = NULL;
  pCur = *head;
  //cari target value sampai ditemukan atau sampai pada akhir list
  while (pCur != NULL && pCur -> data != pos) {
    pPre = pCur;
    pCur = pCur -> next;
  }

  if (pCur == NULL){
     printf("\nnode tidak ditemukan");
     getch();
  }
  else
     deleteNode(head, pPre, pCur);
}

//========================================================

void deleteList(node *head){
  node *pTemp;


  while(head != NULL){
     pTemp = head;
     head = head->next;
     free(pTemp);
  }
}

