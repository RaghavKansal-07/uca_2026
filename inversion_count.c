#include <stdio.h>
#include <stdlib.h>

int merge(int arr[], int low, int mid, int high)
{
    int *temp = (int *)malloc((high - low + 1) * sizeof(int));

    int left = low;
    int right = mid + 1;
    int k = 0;
    int count = 0;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp[k++] = arr[left++];
        }
        else
        {
            count += (mid - left + 1);
            temp[k++] = arr[right++];
        }
    }

    while (left <= mid)
    {
        temp[k++] = arr[left++];
    }

    while (right <= high)
    {
        temp[k++] = arr[right++];
    }

    for (int i = 0; i < k; i++)
    {
        arr[low + i] = temp[i];
    }

    free(temp);

    return count;
}

int mergeSort(int arr[], int low, int high)
{
    if (low >= high)
    {
        return 0;
    }

    int mid = low + (high - low) / 2;

    int count = 0;

    count += mergeSort(arr, low, mid);
    count += mergeSort(arr, mid + 1, high);

    count += merge(arr, low, mid, high);

    return count;
}

int main()
{
    int arr[] = {1, 2, 4, 1, 3, 5};

    int n = sizeof(arr) / sizeof(arr[0]);

    int ans = mergeSort(arr, 0, n - 1);

    printf("%d\n", ans);

    return 0;
}
