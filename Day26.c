#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

int main()
{
    int n, i, value;

    scanf("%d", &n);

    struct Node *head = NULL;
    struct Node *tail = NULL;

    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);

        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = tail;

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    struct Node *temp = head;

    while (temp != NULL)
    {
        printf("%d", temp->data);

        if (temp->next != NULL)
            printf(" ");

        temp = temp->next;
    }

    return 0;
}
