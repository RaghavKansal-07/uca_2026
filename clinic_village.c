#include <stdio.h>
#include <math.h>

int canAllocate(int population[], int n, int k, double maxLoad) {
    long long clinicsNeeded = 0;

    for (int i = 0; i < n; i++) {
        long long clinics = (long long)ceil(population[i] / maxLoad);

        if (clinics < 1) {
            clinics = 1;
        }

        clinicsNeeded += clinics;

        if (clinicsNeeded > k) {
            return 0;
        }
    }

    return 1;
}

double findMinimumLoad(int population[], int n, int k) {
    double low = 0.0;
    double high = population[0];

    for (int i = 1; i < n; i++) {
        if (population[i] > high) {
            high = population[i];
        }
    }

    for (int i = 0; i < 100; i++) {
        double mid = (low + high) / 2.0;

        if (canAllocate(population, n, k, mid)) {
            high = mid;
        } else {
            low = mid;
        }
    }

    return high;
}

int main() {
    int population[] = {200, 20, 50};
    int n = 3;
    int k = 5;

    double answer = findMinimumLoad(population, n, k);

    printf("%.2f\n", answer);

    return 0;
}
