#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int value;
    int index;
} Node;

void merge(Node arr[], int low, int mid, int high, int ans[])
{
    int n = high - low + 1;
    Node *temp = (Node *)malloc(n * sizeof(Node));

    int left = low;
    int right = mid + 1;
    int k = 0;
    int rightCount = 0;

    while (left <= mid && right <= high)
    {
        if (arr[right].value < arr[left].value)
        {
            temp[k++] = arr[right++];
            rightCount++;
        }
        else
        {
            ans[arr[left].index] += rightCount;
            temp[k++] = arr[left++];
        }
    }

    while (left <= mid)
    {
        ans[arr[left].index] += rightCount;
        temp[k++] = arr[left++];
    }

    while (right <= high)
    {
        temp[k++] = arr[right++];
    }

    for (int i = 0; i < n; i++)
    {
        arr[low + i] = temp[i];
    }

    free(temp);
}

void mergeSort(Node arr[], int low, int high, int ans[])
{
    if (low >= high)
        return;

    int mid = low + (high - low) / 2;

    mergeSort(arr, low, mid, ans);
    mergeSort(arr, mid + 1, high, ans);

    merge(arr, low, mid, high, ans);
}

int main()
{
    int nums[] = {5, 2, 6, 1};

    int n = sizeof(nums) / sizeof(nums[0]);

    Node *arr = (Node *)malloc(n * sizeof(Node));
    int *ans = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        arr[i].value = nums[i];
        arr[i].index = i;
    }

    mergeSort(arr, 0, n - 1, ans);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", ans[i]);
    }

    free(arr);
    free(ans);

    return 0;
}
