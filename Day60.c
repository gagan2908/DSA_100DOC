#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Check Min-Heap property
    for (int i = 0; i < n; i++) {

        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // Check left child
        if (left < n && arr[i] > arr[left]) {
            printf("NO\n");
            return 0;
        }

        // Check right child
        if (right < n && arr[i] > arr[right]) {
            printf("NO\n");
            return 0;
        }
    }

    printf("YES\n");

    return 0;
}