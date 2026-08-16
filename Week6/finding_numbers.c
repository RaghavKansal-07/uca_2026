#include <stdio.h>

int findFourTimes(int arr[], int n) {
    int answer = 0;

    for (int bit = 0; bit < 32; bit++) {
        int count = 0;

        for (int i = 0; i < n; i++) {
            if ((arr[i] >> bit) & 1) {
                count++;
            }
        }

        if (count % 3 != 0) {
            answer |= (1 << bit);
        }
    }

    return answer;
}

int main() {
    int arr[] = {1, 2, 3, 4, 1, 2, 4, 1, 2, 3, 4, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", findFourTimes(arr, n));

    return 0;
}
