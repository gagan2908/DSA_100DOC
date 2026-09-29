#include <stdio.h>
#include <stdlib.h>

void bucketSort(float arr[], int n) {
    // Create n buckets
    float buckets[n][n];
    int count[n];

    // Initialize bucket counts
    for (int i = 0; i < n; i++) {
        count[i] = 0;
    }

    // Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int index = (int)(n * arr[i]);
        buckets[index][count[index]] = arr[i];
        count[index]++;
    }

    // Sort each bucket using insertion sort
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < count[i]; j++) {
            float key = buckets[i][j];
            int k = j - 1;

            while (k >= 0 && buckets[i][k] > key) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }

            buckets[i][k + 1] = key;
        }
    }

    // Concatenate buckets
    int index = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < count[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    float arr[] = {
        0.78, 0.17, 0.39, 0.26,
        0.72, 0.94, 0.21, 0.12,
        0.23, 0.68
    };

    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);

    printf("Sorted array:\n");

    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }

    return 0;
}