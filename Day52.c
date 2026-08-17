#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
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

// Build tree from level-order traversal
struct TreeNode* buildTree(int arr[], int n) {

    if (n == 0 || arr[0] == -1)
        return NULL;

    struct TreeNode* root = createNode(arr[0]);

    struct TreeNode** queue =
        (struct TreeNode**)malloc(n * sizeof(struct TreeNode*));

    int front = 0, rear = 0;

    queue[rear++] = root;

    int i = 1;

    while (i < n) {

        struct TreeNode* current = queue[front++];

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

// Find LCA
struct TreeNode* lowestCommonAncestor(
    struct TreeNode* root,
    int p,
    int q) {

    // If tree is empty or current node is p/q
    if (root == NULL || root->val == p || root->val == q)
        return root;

    // Search left subtree
    struct TreeNode* left =
        lowestCommonAncestor(root->left, p, q);

    // Search right subtree
    struct TreeNode* right =
        lowestCommonAncestor(root->right, p, q);

    // p and q found in different subtrees
    if (left != NULL && right != NULL)
        return root;

    // Return whichever side found a node
    if (left != NULL)
        return left;

    return right;
}

int main() {

    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int p, q;
    scanf("%d %d", &p, &q);

    // Build binary tree
    struct TreeNode* root = buildTree(arr, n);

    // Find LCA
    struct TreeNode* lca =
        lowestCommonAncestor(root, p, q);

    if (lca != NULL)
        printf("%d\n", lca->val);

    free(arr);

    return 0;
}