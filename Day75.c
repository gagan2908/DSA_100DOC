#include <stdio.h>

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int maxLength = 0;

    // Check all possible subarrays
    for (int i = 0; i < n; i++) {
        int sum = 0;

        for (int j = i; j < n; j++) {
            sum += arr[j];

            if (sum == 0) {
                int length = j - i + 1;

                if (length > maxLength) {
                    maxLength = length;
                }
            }
        }
    }

    printf("Length of longest subarray with sum 0 = %d\n", maxLength);

    return 0;
}