#include <stdio.h>

int findKthLargest(int* nums, int numsSize, int k) {
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = 0; j < numsSize - i - 1; j++) {
            if (nums[j] < nums[j + 1]) {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }

    return nums[k - 1];
}

int main() {
    int nums[] = {3, 2, 1, 5, 6, 4};
    int n = sizeof(nums) / sizeof(nums[0]);
    int k = 2;

    int result = findKthLargest(nums, n, k);

    printf("Kth largest element = %d\n", result);

    return 0;
}