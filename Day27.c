#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
void insertEnd(struct Node **head, int data) {
    struct Node *newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Find length
int getLength(struct Node *head) {
    int count = 0;

    while (head != NULL) {
        count++;
        head = head->next;
    }

    return count;
}

// Find first common value
void findIntersection(struct Node *head1, struct Node *head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff;

    if (len1 > len2) {
        diff = len1 - len2;
        while (diff--)
            head1 = head1->next;
    } else {
        diff = len2 - len1;
        while (diff--)
            head2 = head2->next;
    }

    while (head1 != NULL && head2 != NULL) {
        if (head1->data == head2->data) {
            printf("%d", head1->data);
            return;
        }

        head1 = head1->next;
        head2 = head2->next;
    }

    printf("No Intersection");
}

int main() {
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;

    int n, m, x;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        insertEnd(&head1, x);
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        insertEnd(&head2, x);
    }

    findIntersection(head1, head2);

    return 0;
}