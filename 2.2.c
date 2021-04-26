#include <stdio.h>
#include <stdlib.h>

void tampil(int data[], int n);

int banding = 0;
int jtukar = 0;

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
	selection(data, n);
	printf("%-25s", "Data terurut array"); printf(": ");
	tampil(data, n);
	printf("%-25s", "Jumlah Perbandingan"); printf(": %d\n", banding);
	printf("%-25s", "Jumlah Pertukaran"); printf(": %d", jtukar);
}

int alokasi(int data[], int n){
	int i;
	
	for(i=0; i<n; i++){
		printf("Data Array ke %d ", i+1); printf(": ");
		scanf("%d", &data[i]);
		fflush(stdin);
	}
}

int selection(int data[], int n){
	
	int i,j, x, temp;
    for(i=0; i<n-1; i++){
        x = i;
        j = i+1;
        while(j<10){
        	banding++;
            if(data[j] < data[x]){
            	x = j;
			}
            j++;
        }
        tukar(&data[i], &data[x]);
    }
	
}

int tukar(int *a, int *b){
	int temp;
	jtukar++;
	
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
