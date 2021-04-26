#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu(int data[], int n);
void terurut(int data[], int n);
void tampil(int data[], int n);

int pilihan, AscDsc;

int main(){
	int n;
	
	printf("%-25s", "Panjang Array"); printf(": ");
	scanf("%d", &n);
	fflush(stdin);
	
	int data[n];
	int data2[n];
	
	alokasi(data2, n);
	
	int len = sizeof(data2)/sizeof(*data2);
	
	do {
		memcpy(data, data2, len*(sizeof(int)));
		printf("%-25s", "Data array awal"); printf(": ");
		tampil(data, n);
		menu(data, n);
		printf("%-25s", "Data array terurut"); printf(": ");
		tampil(data, n);
	} while(pilihan != 3);
}

int alokasi(int data2[], int n){
	int i;
	
	for(i=0; i<n; i++){
		printf("Data Array ke %d ", i+1); printf(": ");
		scanf("%d", &data2[i]);
		fflush(stdin);
	}
}

void menu(int data[], int n){
	printf("========================\n");
	printf(" MENU METODE SORTING\n");
	printf("========================\n");
	printf("1. Insertion Sort\n");
	printf("2. Selection Sort\n");
	printf("3. Keluar\n");
	printf("%-25s", "Pilih Menu"); printf(": ");
	scanf("%d", &pilihan);
	fflush(stdin);
	if(pilihan == 1 || pilihan == 2)
		terurut(data, n);
	else if(pilihan == 3)
		exit(0);
}

void terurut(int data[], int n){
	printf("========================\n");
	printf(" MENU METODE SORTING\n");
	printf("========================\n");
	printf("1. Ascending\n");
	printf("2. Descending\n");
	printf("%-25s", "Pilih Menu"); printf(": ");
	scanf("%d", &AscDsc);
	fflush(stdin);
	
	switch(pilihan){
		case 1:
			insertion(data, n);
			break;
		case 2:
			selection(data, n);
			break;
	}

}

int insertion(int data[], int n){
	
	int i, j, key, temp;
	
	for(i=1; i<n; i++){
		key = data[i];
		j = i - 1;
		while(j >= 0 && data[j] > key && AscDsc == 1 || j >= 0 && data[j] < key && AscDsc == 2){
			tukar(&data[j+1], &data[j]);
			j = j - 1;
		}
	}
	
}

int selection(int data[], int n){
	
	int i,j, x, temp;
    for(i=0; i<n-1; i++){
        x = i;
        j = i+1;
        while(j<n){
            if(data[j] < data[x] && AscDsc == 1 || data[j] > data[x] && AscDsc == 2)
                x = j;
            j++;
        }
        tukar(&data[i], &data[x]);
    }
	
}

int tukar(int *a, int *b){
	int temp;
	
    temp = *a;
    *a = *b;
    *b = temp;
}

void tampil(int data[], int n){
	int i;
	for(i=0; i<n; i++){
		printf("%d ", data[i]);
	}
	printf("\n");
}
