#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    int n, i, value;

    scanf("%d", &n);

    if (n == 0)
        return 0;

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Make the list circular
    temp->next = head;

    // Traverse and print the circular linked list
    temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    return 0;
}