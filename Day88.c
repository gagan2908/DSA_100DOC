#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int possible(int a[], int n, int k, int d) {
    int count = 1, last = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] - last >= d) {
            count++;
            last = a[i];
        }
    }
    return count >= k;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    qsort(a, n, sizeof(int), cmp);

    int l = 0, r = a[n - 1] - a[0], ans = 0;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (possible(a, n, k, mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    printf("%d", ans);
    return 0;
}