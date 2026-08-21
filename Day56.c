#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
} Node;

/* Check whether two subtrees are mirrors */
int isSymmetric(int *tree, int n) {
    if (n == 0 || tree[0] == -1)
        return 1;

    /*
       For a complete heap-style level-order array:
       left child  = 2*i + 1
       right child = 2*i + 2

       We recursively compare:
       left subtree's left  <-> right subtree's right
       left subtree's right <-> right subtree's left
    */

    int stack1[10000], stack2[10000];
    int top1 = -1, top2 = -1;

    stack1[++top1] = 1;  // root's left
    stack2[++top2] = 2;  // root's right

    while (top1 >= 0 && top2 >= 0) {
        int a = stack1[top1--];
        int b = stack2[top2--];

        if (a >= n || b >= n)
            continue;

        if (tree[a] == -1 && tree[b] == -1)
            continue;

        if (tree[a] == -1 || tree[b] == -1)
            return 0;

        if (tree[a] != tree[b])
            return 0;

        // left-left <-> right-right
        int aLeft = 2 * a + 1;
        int bRight = 2 * b + 2;

        // left-right <-> right-left
        int aRight = 2 * a + 2;
        int bLeft = 2 * b + 1;

        if (aLeft < n && bRight < n) {
            stack1[++top1] = aLeft;
            stack2[++top2] = bRight;
        }

        if (aRight < n && bLeft < n) {
            stack1[++top1] = aRight;
            stack2[++top2] = bLeft;
        }
    }

    return top1 == -1 && top2 == -1;
}

int main() {
    int N;
    scanf("%d", &N);

    int *tree = (int *)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) {
        scanf("%d", &tree[i]);
    }

    if (isSymmetric(tree, N))
        printf("YES\n");
    else
        printf("NO\n");

    free(tree);

    return 0;
}