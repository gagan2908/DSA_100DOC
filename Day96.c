#include <stdio.h>

long long merge(int a[], int temp[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    long long inversions = 0;

    while (i <= mid && j <= right) {

        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        }
        else {
            temp[k++] = a[j++];

            // All remaining elements in left half
            // are greater than a[j]
            inversions += (mid - i + 1);
        }
    }

    while (i <= mid)
        temp[k++] = a[i++];

    while (j <= right)
        temp[k++] = a[j++];

    for (i = left; i <= right; i++)
        a[i] = temp[i];

    return inversions;
}

long long mergeSort(int a[], int temp[], int left, int right) {

    if (left >= right)
        return 0;

    int mid = left + (right - left) / 2;

    long long inversions = 0;

    inversions += mergeSort(a, temp, left, mid);

    inversions += mergeSort(a, temp, mid + 1, right);

    inversions += merge(a, temp, left, mid, right);

    return inversions;
}

long long countInversions(int a[], int n) {

    int temp[n];

    return mergeSort(a, temp, 0, n - 1);
}

int main() {

    int a[] = {8, 4, 2, 1};
    int n = 4;

    printf("Number of inversions = %lld\n",
           countInversions(a, n));

    return 0;
}