#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct {
    Node* node;
    int hd;   // horizontal distance
} QueueNode;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Build tree from level-order array
Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    Node* root = createNode(arr[0]);

    Node** queue = (Node**)malloc(n * sizeof(Node*));
    int front = 0, rear = 0;

    queue[rear++] = root;

    int i = 1;

    while (i < n) {
        Node* current = queue[front++];

        // Left child
        if (i < n && arr[i] != -1) {
            current->left = createNode(arr[i]);
            queue[rear++] = current->left;
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            queue[rear++] = current->right;
        }
        i++;
    }

    free(queue);
    return root;
}

void verticalOrder(Node* root, int n) {
    if (root == NULL)
        return;

    QueueNode* queue =
        (QueueNode*)malloc(n * sizeof(QueueNode));

    int front = 0, rear = 0;

    queue[rear].node = root;
    queue[rear].hd = 0;
    rear++;

    // Store nodes according to horizontal distance
    int** columns = (int**)malloc((2 * n + 1) * sizeof(int*));
    int* sizes = (int*)calloc(2 * n + 1, sizeof(int));

    for (int i = 0; i < 2 * n + 1; i++)
        columns[i] = (int*)malloc(n * sizeof(int));

    int offset = n;
    int minHD = 0;
    int maxHD = 0;

    while (front < rear) {
        QueueNode current = queue[front++];

        Node* node = current.node;
        int hd = current.hd;

        columns[hd + offset][sizes[hd + offset]++] = node->data;

        if (hd < minHD)
            minHD = hd;

        if (hd > maxHD)
            maxHD = hd;

        if (node->left != NULL) {
            queue[rear].node = node->left;
            queue[rear].hd = hd - 1;
            rear++;
        }

        if (node->right != NULL) {
            queue[rear].node = node->right;
            queue[rear].hd = hd + 1;
            rear++;
        }
    }

    // Print from leftmost vertical line to rightmost
    for (int hd = minHD; hd <= maxHD; hd++) {
        for (int j = 0; j < sizes[hd + offset]; j++) {
            printf("%d ", columns[hd + offset][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < 2 * n + 1; i++)
        free(columns[i]);

    free(columns);
    free(sizes);
    free(queue);
}

int main() {
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Node* root = buildTree(arr, n);

    verticalOrder(root, n);

    free(arr);

    return 0;
}