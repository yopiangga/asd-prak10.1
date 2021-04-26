#include <stdio.h>
#include <stdlib.h>

void tampil(int data[], int n);

int c = 0;
int m = 0;
int s = 0;

int main(){
	int n = 10;

//	int data[] = {3, 10, 4, 6, 8, 9, 2, 7, 1, 5};
//	int data[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
	printf("\n");
	printf("%-25s", "Data awal array"); printf(": ");
	tampil(data, n);
	selection(data, n);
	printf("%-25s", "Data terurut array"); printf(": ");
	tampil(data, n);
	printf("%-25s", "Jumlah C"); printf(": %d\n", c);
	printf("%-25s", "Jumlah M"); printf(": %d\n", m);
	printf("%-25s", "Jumlah S"); printf(": %d", s);
}

int selection(int data[], int n){
	
	int i,j, x;
    for(i=0; i<n-1; i++){
        x = i;
        for(j = i+1; j<n; j++){
        	c++;
        	if(data[j] < data[x]){
        		x = j;
			}
		}
        tukar(&data[i], &data[x]);
    }
	
}

int tukar(int *a, int *b){
	int temp;
	s++;
	m = m+3;
	
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
