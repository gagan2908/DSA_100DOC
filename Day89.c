#include <stdio.h>

int canAllocate(int a[], int n, int m, int maxPages) {
    int students = 1, pages = 0;

    for (int i = 0; i < n; i++) {
        if (pages + a[i] > maxPages) {
            students++;
            pages = a[i];
        } else {
            pages += a[i];
        }
    }

    return students <= m;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int a[n], low = 0, high = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] > low) low = a[i];
        high += a[i];
    }

    if (m > n) {
        printf("-1");
        return 0;
    }

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (canAllocate(a, n, m, mid))
            high = mid;
        else
            low = mid + 1;
    }

    printf("%d", low);

    return 0;
}