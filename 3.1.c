#include <stdio.h>
#include <stdlib.h>

void menu(int data[], int n);
void terurut(int data[], int n);
void tampil(int data[], int n);

int pilihan, AscDsc;

int main(){
	int n;
	
	printf("%-25s", "Jumlah index"); printf(": ");
	scanf("%d", &n);
	fflush(stdin);
	
	int data[n];
	
	alokasi(data, n);
	
	do {
		menu(data, n);
		printf("%-25s", "Data array"); printf(": ");
		tampil(data, n);
	} while(pilihan != 3);
}

int alokasi(int data[], int n){
	int i;
	
	for(i=0; i<n; i++){
		printf("Data Array ke %d ", i+1); printf(": ");
		scanf("%d", &data[i]);
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
	if(pilihan == 1 || pilihan == 2){
		terurut(data, n);
	}
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
	
	if(AscDsc == 1){
		switch(pilihan){
			case 1:
				insertionASC(data, n);
				break;
			case 2:
				selectionASC(data, n);
				break;
		}
	} else {
		switch(pilihan){
			case 1:
				insertionDSC(data, n);
				break;
			case 2:
				selectionDSC(data, n);
				break;
		}
	}
}

int insertionASC(int data[], int n){
	
	int i, j, key, temp;
	
	for(i=1; i<n; i++){
		key = data[i];
		j = i - 1;
		while(j >= 0 && data[j] > key){
			temp = data[j+1];
			data[j+1] = data[j];
			data[j] = temp;
			j = j - 1;
		}
	}
	
}

int selectionASC(int data[], int n){
	
	int i, j, key, temp, x;
	
	for(i=0; i<n; i++){
		j = i + 1;
		key = data[j];
		x = j;
		
		while(j < n){
			if(key > data[j]){
				key = data[j];
				x = j;
			}
			j = j + 1;
		}
		
		if(key < data[i]){
			temp = data[i];
			data[i] = key;
			data[x] = temp;
		}
	}
	
}

int insertionDSC(int data[], int n){
	
	int i, j, key, temp;
	
	for(i=1; i<n; i++){
		key = data[i];
		j = i - 1;
		while(j >= 0 && data[j] < key){
			temp = data[j+1];
			data[j+1] = data[j];
			data[j] = temp;
			j = j - 1;
		}
	}
	
}

int selectionDSC(int data[], int n){
	
	int i, j, key, temp, x;
	
	for(i=0; i<n; i++){
		j = i + 1;
		key = data[j];
		x = j;
		
		while(j < n){
			if(key < data[j]){
				key = data[j];
				x = j;
			}
			j = j + 1;
		}
		
		if(key > data[i]){
			temp = data[i];
			data[i] = key;
			data[x] = temp;
		}
	}
	
}

void tampil(int data[], int n){
	int i;
	for(i=0; i<n; i++){
		printf("%d ", data[i]);
	}
	printf("\n");
}
