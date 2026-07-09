#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// ---------------- Array Generators ----------------
int* generateRandomArray(int size) {
    int* arr = (int*) malloc(size * sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < size; i++) arr[i] = rand() % 100000;
    return arr;
}

int* generateAscendingArray(int size) {
    int* arr = (int*) malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) arr[i] = i;
    return arr;
}



int* generateDescendingArray(int size) {
    int* arr = (int*) malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) arr[i] = size - i;
    return arr;
}

// ---------------- Sorting Algorithms ----------------
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        bool swapped = false;
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int tmp = arr[j]; arr[j] = arr[j+1]; arr[j+1] = tmp;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i-1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j]; j--;
        }
        arr[j+1] = key;
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int minIdx = i;
        for (int j = i+1; j < n; j++)
            if (arr[j] < arr[minIdx]) minIdx = j;
        int tmp = arr[minIdx]; arr[minIdx] = arr[i]; arr[i] = tmp;
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high], i = low-1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp;
        }
    }
    int tmp = arr[i+1]; arr[i+1] = arr[high]; arr[high] = tmp;
    return i+1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m-l+1, n2 = r-m;
    int L[n1], R[n2];
    for (int i=0;i<n1;i++) L[i]=arr[l+i];
    for (int j=0;j<n2;j++) R[j]=arr[m+1+j];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2) arr[k++] = (L[i]<=R[j]) ? L[i++] : R[j++];
    while(i<n1) arr[k++] = L[i++];
    while(j<n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void heapify(int arr[], int n, int i) {
    int largest=i, l=2*i+1, r=2*i+2;
    if(l<n && arr[l]>arr[largest]) largest=l;
    if(r<n && arr[r]>arr[largest]) largest=r;
    if(largest!=i) {
        int tmp=arr[i]; arr[i]=arr[largest]; arr[largest]=tmp;
        heapify(arr,n,largest);
    }
}

void heapSort(int arr[], int n) {
    for(int i=n/2-1;i>=0;i--) heapify(arr,n,i);
    for(int i=n-1;i>0;i--) {
        int tmp=arr[0]; arr[0]=arr[i]; arr[i]=tmp;
        heapify(arr,i,0);
    }
}
void quickSortWrapper(int arr[], int n) {
    quickSort(arr, 0, n-1);
}

void mergeSortWrapper(int arr[], int n) {
    mergeSort(arr, 0, n-1);
}
// ---------------- Benchmark ----------------
double benchmark(void (*sortFunc)(int[], int), int arr[], int size) {
    clock_t start = clock();
    sortFunc(arr, size);
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC * 1000.0;
}

// ---------------- Main ----------------
int main() {
    int sizes[] = {8000, 12000, 16000, 20000, 24000, 28000, 32000, 36000};
    int numSizes = sizeof(sizes)/sizeof(sizes[0]);
    double time;
    for (int s = 0; s < numSizes; s++) {
        int n = sizes[s];
        printf("\nArray Size: %d\n", n);

        // Example: Random input with Bubble Sort
        int* arr = generateRandomArray(n);
        time = benchmark(bubbleSort, arr, n);
        printf("Bubble Sort (Random): %.3f ms\n", time);
        time = benchmark(insertionSort, arr, n);
        printf("Insertion Sort (Random): %.3f ms\n", time);
        time = benchmark(selectionSort, arr, n);
        printf("Selection Sort (Random): %.3f ms\n", time);
        time = benchmark(mergeSortWrapper, arr, n);
        printf("Merge Sort (Random): %.3f ms\n", time);
        time = benchmark(quickSortWrapper, arr, n);
        printf("Quick Sort (Random): %.3f ms\n", time);
        time = benchmark(heapSort, arr, n);
        printf("Heap Sort (Random): %.3f ms\n", time);
        free(arr);

        arr = generateAscendingArray(n);
        time = benchmark(bubbleSort, arr, n);
        printf("Bubble Sort (Ascending): %.3f ms\n", time);
        time = benchmark(insertionSort, arr, n);
        printf("Insertion Sort (Ascending): %.3f ms\n", time);
        time = benchmark(selectionSort, arr, n);
        printf("Selection Sort (Ascending): %.3f ms\n", time);
        time = benchmark(mergeSortWrapper, arr, n);
        printf("Merge Sort (Ascending): %.3f ms\n", time);
        time = benchmark(quickSortWrapper, arr, n);
        printf("Quick Sort (Ascending): %.3f ms\n", time);
        time = benchmark(heapSort, arr, n);
        printf("Heap Sort (Ascending): %.3f ms\n", time);
        free(arr);

        arr = generateDescendingArray(n);
        time = benchmark(bubbleSort, arr, n);
        printf("Bubble Sort (Descending): %.3f ms\n", time);
        time = benchmark(insertionSort, arr, n);
        printf("Insertion Sort (Descending): %.3f ms\n", time);
        time = benchmark(selectionSort, arr, n);
        printf("Selection Sort (Descending): %.3f ms\n", time);
        time = benchmark(mergeSortWrapper, arr, n);
        printf("Merge Sort (Descending): %.3f ms\n", time);
        time = benchmark(quickSortWrapper, arr, n);
        printf("Quick Sort (Descending): %.3f ms\n", time);
        time = benchmark(heapSort, arr, n);
        printf("Heap Sort (Descending): %.3f ms\n", time);
        free(arr);
        
    }
    return 0;
}