#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Edge structure
typedef struct {
    int to;
    int weight;
} Edge;

// Priority Queue Node
typedef struct {
    int vertex;
    int distance;
} PQNode;

// Min Heap
typedef struct {
    PQNode heap[MAX * MAX];
    int size;
} PriorityQueue;

// Swap two nodes
void swap(PQNode *a, PQNode *b) {
    PQNode temp = *a;
    *a = *b;
    *b = temp;
}

// Insert into min heap
void push(PriorityQueue *pq, int vertex, int distance) {
    int i = pq->size++;
    pq->heap[i].vertex = vertex;
    pq->heap[i].distance = distance;

    while (i > 0) {
        int parent = (i - 1) / 2;

        if (pq->heap[parent].distance <= pq->heap[i].distance)
            break;

        swap(&pq->heap[parent], &pq->heap[i]);
        i = parent;
    }
}

// Remove minimum element
PQNode pop(PriorityQueue *pq) {
    PQNode result = pq->heap[0];

    pq->size--;
    pq->heap[0] = pq->heap[pq->size];

    int i = 0;

    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < pq->size &&
            pq->heap[left].distance < pq->heap[smallest].distance)
            smallest = left;

        if (right < pq->size &&
            pq->heap[right].distance < pq->heap[smallest].distance)
            smallest = right;

        if (smallest == i)
            break;

        swap(&pq->heap[i], &pq->heap[smallest]);
        i = smallest;
    }

    return result;
}

// Dijkstra's Algorithm
void dijkstra(int graph[MAX][MAX], int V, int source) {

    int dist[MAX];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    PriorityQueue pq;
    pq.size = 0;

    dist[source] = 0;
    push(&pq, source, 0);

    while (pq.size > 0) {

        PQNode current = pop(&pq);

        int u = current.vertex;
        int d = current.distance;

        // Ignore outdated entry
        if (d > dist[u])
            continue;

        for (int v = 0; v < V; v++) {

            if (graph[u][v] != 0) {

                int weight = graph[u][v];

                if (dist[u] != INT_MAX &&
                    dist[u] + weight < dist[v]) {

                    dist[v] = dist[u] + weight;

                    push(&pq, v, dist[v]);
                }
            }
        }
    }

    printf("\nShortest distances from source %d:\n", source);

    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            printf("%d -> INF\n", i);
        else
            printf("%d -> %d\n", i, dist[i]);
    }
}

int main() {

    int V, E;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    int graph[MAX][MAX] = {0};

    printf("Enter edges (u v weight):\n");

    for (int i = 0; i < E; i++) {
        int u, v, w;

        scanf("%d %d %d", &u, &v, &w);

        // Undirected graph
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int source;

    printf("Enter source vertex: ");
    scanf("%d", &source);

    dijkstra(graph, V, source);

    return 0;
}