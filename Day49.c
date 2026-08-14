#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert into BST
struct Node* insert(struct Node* root, int val) {

    // If empty, create new node
    if (root == NULL) {
        return createNode(val);
    }

    // Smaller value goes to left
    if (val < root->data) {
        root->left = insert(root->left, val);
    }

    // Greater value goes to right
    else if (val > root->data) {
        root->right = insert(root->right, val);
    }

    return root;
}

// Inorder traversal
void inorder(struct Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    struct Node* root = NULL;
    int n, val, x;
    printf("Enter number of roots: ");
    scanf("%d", &n);

    // Build BST
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d (-1 for NULL): ", i + 1);
        scanf("%d", &x);

        if (x != -1) {
            root = insert(root, x);
        }
    }

    // Value to insert
    printf("Enter value to insert: ");
    scanf("%d", &val);

    root = insert(root, val);

    // Print inorder
    inorder(root);

    return 0;
}