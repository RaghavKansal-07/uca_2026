#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = 0;

    int *temp = (int *)malloc((high - low + 1) * sizeof(int));

    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }  
        else{
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid){
        temp[k++] = arr[i++];
    }
        
    while (j <= high){
        temp[k++] = arr[j++];
    }

    for (i = low, k = 0; i <= high; i++, k++){
        arr[i] = temp[k];
    }

    free(temp);
}

int countPairs(int arr[], int low, int mid, int high)
{   
    int count = 0;
    int j = mid + 1;

    for (int i = low; i <= mid; i++)
    {
        while (j <= high && (long long)arr[i] > 2LL * arr[j]){
            j++;
        }

        count += j - (mid + 1);
    }

    return count;
}

int mergeSort(int arr[], int low, int high)
{
    if (low >= high)
        return 0;

    int mid = (low + high) / 2;

    int count = 0;

    count += mergeSort(arr, low, mid);
    count += mergeSort(arr, mid + 1, high);

    count += countPairs(arr, low, mid, high);
    merge(arr, low, mid, high);

    return count;
}

int main()
{
    int arr[] = {2, 4, 3, 5, 1};

    int n = sizeof(arr) / sizeof(arr[0]);

    int ans = mergeSort(arr, 0, n - 1);

    printf("%d\n", ans);

    return 0;
}
