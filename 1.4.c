#include <stdio.h>
#include <stdlib.h>

void tampil(int data[], int n);

int m = 0;
int c = 0;

int main(){
	int n = 10;

//	int data[] = {3, 10, 4, 6, 8, 9, 2, 7, 1, 5};
//	int data[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
	printf("\n");
	printf("%-25s", "Data awal array"); printf(": ");
	tampil(data, n);
	insertion(data, n);
	printf("%-25s", "Data terurut array"); printf(": ");
	tampil(data, n);
	printf("%-25s", "Jumlah C"); printf(": %d\n", c);
	printf("%-25s", "Jumlah M"); printf(": %d", m);
}

int insertion(int data[], int n){
	
	int i, j, key;
	
	for(i=1; i<n; i++){
		key = data[i];
		m++;
		j = i - 1;
		while(j >= 0 && data[j] > key){
			data[j+1] = data[j];
			m++;
			j = j - 1;
			c++;
		}
		data[j+1] = key;
		m++;
	}
	
}

void tampil(int data[], int n){
	int i;
	for(i=0; i<n; i++){
		printf("%d ", data[i]);
	}
	printf("\n");
}
