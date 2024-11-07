/*
Jackson Hoornaert
CSCI 242
HW 3
*/

#include <stdio.h>
#include <sys/time.h>

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

	/*Bubble Sort*/
	printf("Bubble Sort \n");
	t_start = TIMER();
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 5; j++){
			printf("Enter an integer: ");
			scanf("%d", &x);
			arr[j] = x;
		}

	printf("\n");
	printf("Unsorted array: \n");
	printArray(arr, n);

	bubbleSort(arr, n);

	printf("Sorted array: \n");
	printArray(arr, n);
	printf("\n");
	t_end = TIMER();
	}

	t_total = t_end - t_start;

	printf("It took %f microseconds \n\n", t_total);

	/*Insertion Sort*/
	printf("Insertion Sort \n");
	t_start = TIMER();
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 5; j++){
			printf("Enter an integer: ");
			scanf("%d", &x);
			arr[j] = x;
		}

	printf("\n");
	printf("Unsorted array: \n");
	printArray(arr, n);

	insertionSort(arr, n);

	printf("Sorted array: \n");
	printArray(arr, n);
	printf("\n");
	t_end = TIMER();
	}

	t_total = t_end - t_start;

	printf("It took %f microseconds \n\n", t_total);

/*Quick Sort*/
	printf("Quick Sort \n");
	t_start = TIMER();
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 5; j++){
			printf("Enter an integer: ");
			scanf("%d", &x);
			arr[j] = x;
		}

	printf("\n");
	printf("Unsorted array: \n");
	printArray(arr, n);

	quickSort(arr, 0, n - 1);

	printf("Sorted array: \n");
	printArray(arr, n);
	printf("\n");
	t_end = TIMER();
	}

	t_total = t_end - t_start;

	printf("It took %f microseconds \n\n", t_total);

	return 0;
}
