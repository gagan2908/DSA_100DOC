#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data) {
    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int findIndex(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

struct Node* buildTree(
    int inorder[],
    int postorder[],
    int inStart,
    int inEnd,
    int *postIndex
) {
    if (inStart > inEnd)
        return NULL;

    // Last element of postorder is the root
    int rootValue = postorder[*postIndex];
    (*postIndex)--;

    struct Node* root = createNode(rootValue);

    // Find root in inorder
    int rootIndex = findIndex(
        inorder,
        inStart,
        inEnd,
        rootValue
    );

    // Build right subtree first
    root->right = buildTree(
        inorder,
        postorder,
        rootIndex + 1,
        inEnd,
        postIndex
    );

    // Build left subtree
    root->left = buildTree(
        inorder,
        postorder,
        inStart,
        rootIndex - 1,
        postIndex
    );

    return root;
}

void preorder(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int N;

    scanf("%d", &N);

    int inorder[N];
    int postorder[N];

    for (int i = 0; i < N; i++)
        scanf("%d", &inorder[i]);

    for (int i = 0; i < N; i++)
        scanf("%d", &postorder[i]);

    int postIndex = N - 1;

    struct Node* root = buildTree(
        inorder,
        postorder,
        0,
        N - 1,
        &postIndex
    );

    preorder(root);

    return 0;
}