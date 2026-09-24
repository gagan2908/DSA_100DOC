#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int a[n];
    long long low = 0, high = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] > low)
            low = a[i];
        high += a[i];
    }

    while (low < high) {
        long long mid = low + (high - low) / 2;
        int painters = 1;
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            if (sum + a[i] > mid) {
                painters++;
                sum = a[i];
            } else {
                sum += a[i];
            }
        }

        if (painters <= k)
            high = mid;
        else
            low = mid + 1;
    }

    printf("%lld\n", low);

    return 0;
}