#include <stdio.h>

#define MAX_SIZE 10000

typedef struct {
    int data[MAX_SIZE];
    int size;
} MaxHeap;

typedef struct {
    int data[MAX_SIZE];
    int size;
} MinHeap;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapifyUp(MaxHeap *heap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;

        if (heap->data[parent] >= heap->data[index]) {
            break;
        }

        swap(&heap->data[parent], &heap->data[index]);
        index = parent;
    }
}

void maxHeapifyDown(MaxHeap *heap, int index) {
    while (1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < heap->size && heap->data[left] > heap->data[largest]) {
            largest = left;
        }

        if (right < heap->size && heap->data[right] > heap->data[largest]) {
            largest = right;
        }

        if (largest == index) {
            break;
        }

        swap(&heap->data[index], &heap->data[largest]);
        index = largest;
    }
}

void minHeapifyUp(MinHeap *heap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;

        if (heap->data[parent] <= heap->data[index]) {
            break;
        }

        swap(&heap->data[parent], &heap->data[index]);
        index = parent;
    }
}

void minHeapifyDown(MinHeap *heap, int index) {
    while (1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < heap->size && heap->data[left] < heap->data[smallest]) {
            smallest = left;
        }

        if (right < heap->size && heap->data[right] < heap->data[smallest]) {
            smallest = right;
        }

        if (smallest == index) {
            break;
        }

        swap(&heap->data[index], &heap->data[smallest]);
        index = smallest;
    }
}

void insertMaxHeap(MaxHeap *heap, int value) {
    heap->data[heap->size] = value;
    heap->size++;
    maxHeapifyUp(heap, heap->size - 1);
}

void insertMinHeap(MinHeap *heap, int value) {
    heap->data[heap->size] = value;
    heap->size++;
    minHeapifyUp(heap, heap->size - 1);
}

int removeMaxHeap(MaxHeap *heap) {
    int value = heap->data[0];

    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;

    if (heap->size > 0) {
        maxHeapifyDown(heap, 0);
    }

    return value;
}

int removeMinHeap(MinHeap *heap) {
    int value = heap->data[0];

    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;

    if (heap->size > 0) {
        minHeapifyDown(heap, 0);
    }

    return value;
}

void insert(MaxHeap *maxHeap, MinHeap *minHeap, int num) {
    if (maxHeap->size == 0 || num <= maxHeap->data[0]) {
        insertMaxHeap(maxHeap, num);
    } else {
        insertMinHeap(minHeap, num);
    }

    if (maxHeap->size > minHeap->size + 1) {
        int value = removeMaxHeap(maxHeap);
        insertMinHeap(minHeap, value);
    } else if (minHeap->size > maxHeap->size) {
        int value = removeMinHeap(minHeap);
        insertMaxHeap(maxHeap, value);
    }
}

float getMedian(MaxHeap *maxHeap, MinHeap *minHeap) {
    if (maxHeap->size > minHeap->size) {
        return (float)maxHeap->data[0];
    }

    return (maxHeap->data[0] + minHeap->data[0]) / 2.0f;
}

int main() {
    MaxHeap maxHeap = {.size = 0};
    MinHeap minHeap = {.size = 0};

    int numbers[] = {10, 5, 2, 8, 15};
    int n = 5;

    for (int i = 0; i < n; i++) {
        insert(&maxHeap, &minHeap, numbers[i]);
        printf("After inserting %d: %.2f\n",
               numbers[i],
               getMedian(&maxHeap, &minHeap));
    }

    return 0;
}
