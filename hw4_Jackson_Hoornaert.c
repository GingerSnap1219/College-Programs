/*
Jackson Hoornaert
CSCI 242
HW 4
*/

#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

double TIMER(void){
	struct timeval tp;
	struct timezone tzp;
	int i;

	i = gettimeofday(&tp, &tzp);
	return((double)tp.tv_sec + (double)tp.tv_usec * 1.e-6);
}

void swap(int* xp, int* yp){
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

int partition(int arr[], int low, int high){
	int pivot = arr[high];
	int i = low - 1;

	for(int j = low; j<= high - 1; j++){
		if(arr[j] < pivot){
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void merge(int arr[], int l, int m, int r){
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	for(i = 0; i < n1; i++){
		L[i] = arr[l + i];
	}
	for(j = 0; j < n2; j++){
		R[j] = arr[m + 1 + j];
	}

	i = 0;
	j = 0;
	k = 1;

	while(i < n1 && j <n2){
		if(L[i] <= R[j]){
			arr[k] = L[i];
			i++;
		}else{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while(i < n1){
		arr[k] = L[i];
		i++;
		k++;
	}
	while(j < n2){
		arr[k] = R[j];
		j++;
		k++;
	}
}

void bubbleSort(int arr[], int n){
	int i, j;
	for(i = 0; i < n - 1; i++){
		for(j = 0; j < n - i - 1; j++){
			if(arr[j] > arr[j + 1]){
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

void insertionSort(int arr[], int n){
	int i, key, j;
	for(i = 1; i < n; i++){
		key = arr[i];
		j = i - 1;

		while(j >= 0 && arr[j] > key){
			arr[j + 1] = arr[j];
			j -= 1;
		}
		arr[j + 1] = key;
	}
}

void quickSort(int arr[], int low, int high){
	if(low < high){
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void mergeSort(int arr[], int l, int r){
	if(l < r){
		int m = l + (r - 1) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

void printArray(int arr[], int size){
	int i;
	for(i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(){
	int arr[5];
	int n = sizeof(arr) / sizeof(arr[0]);
	int x;
	double t_start, t_end, t_total;

	for(int i = 0; i < 5; i++){
		arr[i] = rand()%65536;
	}

	/*Bubble Sort*/
	printf("Bubble Sort \n");
	printf("Unsorted Array: \n");
	printArray(arr, n);

	t_start = TIMER();
	for(int i = 0; i < 1000; i++){
	bubbleSort(arr, n);
	}

	t_end = TIMER();

	t_total = t_end - t_start;

	printf("It took %f microseconds \n\n", t_total);

	for(int i = 0; i < 5; i++){
		arr[i] = rand()%65536;
	}

	/*Insertion Sort*/
	printf("Insertion Sort \n");
	printf("Unsorted Array: \n");
	printArray(arr, n);

	t_start = TIMER();
	for(int i = 0; i < 1000; i++){
	insertionSort(arr, n);
	}
	t_end = TIMER();

	t_total = t_end - t_start;

	printf("It took %f microseconds \n\n", t_total);

	for(int i = 0; i < 5; i++){
		arr[i] = rand()%65536;
	}

	/*Quick Sort*/
	printf("Quick Sort \n");
	printf("Unsorted array: \n");
	printArray(arr, n);

	t_start = TIMER();

	for(int i = 0; i < 1000; i++){
	quickSort(arr, 0, n - 1);
	}

	t_end = TIMER();

	t_total = t_end - t_start;

	printf("It took %f microseconds \n\n", t_total);

	for(int i = 0; i < 5; i++){
		arr[i] = rand()%65536;
	}

	/*Merge Sort*/
	printf("Merge Sort Sort \n");
	printf("Unsorted array: \n");
	printArray(arr, n);

	t_start = TIMER();

	for(int i = 0; i < 1000; i++){
	mergeSort(arr, 0, n - 1);
	}

	t_end = TIMER();

	t_total = t_end - t_start;

	printf("It took %f microseconds \n\n", t_total);

	return 0;
}
