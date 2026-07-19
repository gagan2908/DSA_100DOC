/* Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print the merged linked list elements, space-separated

Example:
Input:
5
10 20 30 40 50
4
15 25 35 45

Output:
10 15 20 25 30 35 40 45 50

Explanation:
Compare nodes of both lists, append smaller to result, continue until all nodes are merged. */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create new node dynamically
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert node at end
void insert(struct Node** head, int value) {
    struct Node* newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Merge two sorted linked lists
struct Node* mergeLists(struct Node* head1, struct Node* head2) {
    struct Node dummy;
    dummy.next = NULL;

    struct Node* tail = &dummy;

    while (head1 != NULL && head2 != NULL) {

        if (head1->data <= head2->data) {
            tail->next = head1;
            head1 = head1->next;
        }
        else {
            tail->next = head2;
            head2 = head2->next;
        }

        tail = tail->next;
    }

    // Attach remaining nodes
    if (head1 != NULL)
        tail->next = head1;
    else
        tail->next = head2;

    return dummy.next;
}

// Print linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, m, value;

    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    // First list
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insert(&list1, value);
    }

    // Second list
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        scanf("%d", &value);
        insert(&list2, value);
    }

    // Merge and print
    struct Node* merged = mergeLists(list1, list2);

    printList(merged);

    return 0;
}