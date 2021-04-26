#include <stdio.h>
#include <stdlib.h>

void tampil(int data[], int n);

int main(){
	int n;
	int data[] = {3, 10, 4, 6, 8, 9, 7, 2, 1, 5};
	
	n = sizeof(data)/sizeof(data[0]);

	tampil(data, n);
	insertion(&data, n);
	tampil(data, n);
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
