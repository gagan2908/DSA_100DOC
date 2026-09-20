#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);

    long long left = 0, right = n;
    long long ans = 0;

    while (left <= right) {
        long long mid = left + (right - left) / 2;

        if (mid * mid == n) {
            ans = mid;
            break;
        }
        else if (mid * mid < n) {
            ans = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    printf("%lld\n", ans);

    return 0;
}