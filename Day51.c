#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Create a new node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode =
        (struct TreeNode*)malloc(sizeof(struct TreeNode));

    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert into BST
struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL)
        return createNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Find LCA
struct TreeNode* lowestCommonAncestor(
    struct TreeNode* root,
    int p,
    int q
) {
    if (p < root->val && q < root->val)
        return lowestCommonAncestor(root->left, p, q);

    if (p > root->val && q > root->val)
        return lowestCommonAncestor(root->right, p, q);

    return root;
}

int main() {
    int N;
    scanf("%d", &N);

    struct TreeNode* root = NULL;

    // Input BST values
    for (int i = 0; i < N; i++) {
        int value;
        scanf("%d", &value);
        root = insert(root, value);
    }

    // Input two nodes
    int p, q;
    scanf("%d %d", &p, &q);

    struct TreeNode* lca =
        lowestCommonAncestor(root, p, q);

    printf("%d\n", lca->val);

    return 0;
}