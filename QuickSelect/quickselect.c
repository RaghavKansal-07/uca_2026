#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (i < high && arr[i] <= pivot)
            i++;

        while (j > low && arr[j] > pivot)
            j--;

        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

void quickSelect(int arr[], int low, int high, int k)
{
    if (low >= high)
        return;

    int p = partition(arr, low, high);

    if (p == k - 1)
        return;
    else if (p > k - 1)
        quickSelect(arr, low, p - 1, k);
    else
        quickSelect(arr, p + 1, high, k);
}

int main()
{
    int sizes[] = {1000, 2000, 5000, 10000, 20000, 50000, 100000};
    int totalSizes = sizeof(sizes) / sizeof(sizes[0]);

    srand(time(NULL));

    printf("Size\tAverage Time (ms)\n");

    for (int s = 0; s < totalSizes; s++)
    {
        int n = sizes[s];
        double totalTime = 0;

        for (int test = 0; test < 100; test++)
        {
            int *arr = (int *)malloc(n * sizeof(int));

            for (int i = 0; i < n; i++)
                arr[i] = rand();

            int k = n / 10;

            clock_t start = clock();

            quickSelect(arr, 0, n - 1, k);

            clock_t end = clock();

            totalTime += ((double)(end - start) * 1000) / CLOCKS_PER_SEC;

            free(arr);
        }

        printf("%d\t%.4f\n", n, totalTime / 100);
    }

    return 0;
}
