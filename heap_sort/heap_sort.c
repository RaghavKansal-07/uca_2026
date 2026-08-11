#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    while (1) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }

        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest == i) {
            break;
        }

        swap(&arr[i], &arr[largest]);
        i = largest;
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int isSorted(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] > arr[i]) {
            return 0;
        }
    }

    return 1;
}

void generateRandom(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand();
    }
}

void generateAscending(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
}

void generateDescending(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = n - i;
    }
}

double measureTime(int arr[], int n) {
    clock_t start = clock();

    heapSort(arr, n);

    clock_t end = clock();

    return ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;
}

double averageTime(void (*generator)(int[], int), int n, int repetitions) {
    double total = 0.0;

    int *base = malloc(n * sizeof(int));
    int *arr = malloc(n * sizeof(int));

    if (base == NULL || arr == NULL) {
        printf("Memory allocation failed\n");
        free(base);
        free(arr);
        exit(1);
    }

    generator(base, n);

    for (int i = 0; i < repetitions; i++) {
        for (int j = 0; j < n; j++) {
            arr[j] = base[j];
        }

        total += measureTime(arr, n);

        if (!isSorted(arr, n)) {
            printf("Sorting failed for size %d\n", n);
            free(base);
            free(arr);
            exit(1);
        }
    }

    free(base);
    free(arr);

    return total / repetitions;
}

int main() {
    int sizes[] = {1000, 2000, 5000, 10000, 20000, 50000, 100000};
    int count = sizeof(sizes) / sizeof(sizes[0]);
    int repetitions = 5;

    srand(42);

    printf("Size\tRandom(ms)\tAscending(ms)\tDescending(ms)\n");

    for (int i = 0; i < count; i++) {
        int n = sizes[i];

        double randomTime = averageTime(generateRandom, n, repetitions);
        double ascendingTime = averageTime(generateAscending, n, repetitions);
        double descendingTime = averageTime(generateDescending, n, repetitions);

        printf("%d\t%.4f\t\t%.4f\t\t%.4f\n",
               n,
               randomTime,
               ascendingTime,
               descendingTime);
    }

    return 0;
}
