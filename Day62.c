#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

int main() {
    int n, m;

    scanf("%d %d", &n, &m);

    Node* adj[n];

    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    // Add edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        // Add v to u's list
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->vertex = v;
        newNode->next = adj[u];
        adj[u] = newNode;

        // Add u to v's list (undirected graph)
        newNode = (Node*)malloc(sizeof(Node));
        newNode->vertex = u;
        newNode->next = adj[v];
        adj[v] = newNode;
    }

    // Print adjacency lists
    for (int i = 0; i < n; i++) {
        printf("%d:", i);

        Node* temp = adj[i];

        while (temp != NULL) {
            printf(" %d", temp->vertex);
            temp = temp->next;
        }

        printf("\n");
    }

    // Free memory
    for (int i = 0; i < n; i++) {
        Node* temp = adj[i];

        while (temp != NULL) {
            Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }

    return 0;
}