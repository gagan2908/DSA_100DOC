#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    Node** queue = (Node**)malloc(n * sizeof(Node*));
    int front = 0, rear = 0;

    Node* root = createNode(arr[0]);
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

void zigzagTraversal(Node* root) {
    if (root == NULL)
        return;

    Node** queue = (Node**)malloc(1000 * sizeof(Node*));
    int front = 0, rear = 0;

    queue[rear++] = root;

    int leftToRight = 1;

    while (front < rear) {
        int size = rear - front;

        int* level = (int*)malloc(size * sizeof(int));

        for (int i = 0; i < size; i++) {
            Node* current = queue[front++];

            if (leftToRight)
                level[i] = current->data;
            else
                level[size - 1 - i] = current->data;

            if (current->left)
                queue[rear++] = current->left;

            if (current->right)
                queue[rear++] = current->right;
        }

        for (int i = 0; i < size; i++)
            printf("%d ", level[i]);

        free(level);

        leftToRight = !leftToRight;
    }

    free(queue);
}

int main() {
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Node* root = buildTree(arr, n);

    zigzagTraversal(root);

    free(arr);

    return 0;
}