#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int *queue = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    int m;
    scanf("%d", &m);

    // Rotate the front pointer
    int front = m % n;

    // Display queue from new front
    for (int i = 0; i < n; i++) {
        printf("%d", queue[(front + i) % n]);
        if (i != n - 1)
            printf(" ");
    }

    free(queue);
    return 0;
}