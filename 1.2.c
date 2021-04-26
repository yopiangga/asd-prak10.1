#include <stdio.h>
#include <stdlib.h>

void tampil(int data[], int n);

int main(){
	int n;
	
	printf("%-25s", "Jumlah index"); printf(": ");
	scanf("%d", &n);
	fflush(stdin);
	
	int data[n];
	
	alokasi(data, n);
	
	printf("\n");
	printf("%-25s", "Data awal array"); printf(": ");
	tampil(data, n);
	insertion(data, n);
	printf("%-25s", "Data terurut array"); printf(": ");
	tampil(data, n);
}

int alokasi(int data[], int n){
	int i;
	
	for(i=0; i<n; i++){
		printf("Data Array ke %d ", i+1); printf(": ");
		scanf("%d", &data[i]);
		fflush(stdin);
	}
}

int insertion(int data[], int n){
	
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

void tampil(int data[], int n){
	int i;
	for(i=0; i<n; i++){
		printf("%d ", data[i]);
	}
	printf("\n");
}
