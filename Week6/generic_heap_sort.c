#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(void *a, int i, int j, int size)
{
    char *arr = (char *)a;
    char *x = arr + i * size;
    char *y = arr + j * size;

    char *temp = malloc(size);

    if (temp == NULL)
        return;

    memcpy(temp, x, size);
    memcpy(x, y, size);
    memcpy(y, temp, size);

    free(temp);
}

void heapify(void *a, int n, int i, int (*cmp)(void *, void *), int size)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n &&
        cmp((char *)a + left * size,
            (char *)a + largest * size) > 0)
    {
        largest = left;
    }

    if (right < n &&
        cmp((char *)a + right * size,
            (char *)a + largest * size) > 0)
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(a, i, largest, size);
        heapify(a, n, largest, cmp, size);
    }
}

void heap_sort(void *a, int n, int (*cmp)(void *, void *), int size)
{
    int i;

    for (i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i, cmp, size);

    for (i = n - 1; i > 0; i--)
    {
        swap(a, 0, i, size);
        heapify(a, i, 0, cmp, size);
    }
}

int intComparator(void *a, void *b)
{
    int x = *(int *)a;
    int y = *(int *)b;

    if (x < y)
        return -1;

    if (x > y)
        return 1;

    return 0;
}

int floatComparator(void *a, void *b)
{
    float x = *(float *)a;
    float y = *(float *)b;

    if (x < y)
        return -1;

    if (x > y)
        return 1;

    return 0;
}

struct student
{
    int id;
    float cgpa;
    char name[50];
};

int studentIdComparator(void *a, void *b)
{
    struct student *x = (struct student *)a;
    struct student *y = (struct student *)b;

    if (x->id < y->id)
        return -1;

    if (x->id > y->id)
        return 1;

    return 0;
}

void printIntArray(int *a, int n)
{
    int i;

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

void printFloatArray(float *a, int n)
{
    int i;

    for (i = 0; i < n; i++)
        printf("%.2f ", a[i]);

    printf("\n");
}

void printStudents(struct student *a, int n)
{
    int i;

    for (i = 0; i < n; i++)
        printf("ID: %d, CGPA: %.2f, Name: %s\n",
               a[i].id, a[i].cgpa, a[i].name);
}

int main()
{
    int numbers[] = {42, 15, 8, 23, 4, 16, 9};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    float values[] = {4.5, 2.1, 9.8, 1.7, 6.3};
    int m = sizeof(values) / sizeof(values[0]);

    struct student students[] = {
        {103, 8.7, "Rohan"},
        {101, 9.4, "Aarav"},
        {104, 7.9, "Kabir"},
        {102, 8.9, "Diya"}
    };

    int k = sizeof(students) / sizeof(students[0]);

    printf("Integer array before sorting:\n");
    printIntArray(numbers, n);

    heap_sort(numbers, n, intComparator, sizeof(int));

    printf("Integer array after sorting:\n");
    printIntArray(numbers, n);

    printf("\nFloat array before sorting:\n");
    printFloatArray(values, m);

    heap_sort(values, m, floatComparator, sizeof(float));

    printf("Float array after sorting:\n");
    printFloatArray(values, m);

    printf("\nStudents before sorting:\n");
    printStudents(students, k);

    heap_sort(students, k, studentIdComparator, sizeof(struct student));

    printf("\nStudents after sorting by ID:\n");
    printStudents(students, k);

    return 0;
}
