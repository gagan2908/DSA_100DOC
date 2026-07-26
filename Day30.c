#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff;
    int exp;
    struct Node *next;
};

struct Node* createNode(int coeff, int exp)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;

    return newNode;
}

void insert(struct Node **head, int coeff, int exp)
{
    struct Node *newNode = createNode(coeff, exp);

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void display(struct Node *head)
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        printf("%d", temp->coeff);

        if (temp->exp > 1)
        {
            printf("x^%d", temp->exp);
        }
        else if (temp->exp == 1)
        {
            printf("x");
        }

        if (temp->next != NULL)
        {
            printf(" + ");
        }

        temp = temp->next;
    }
}

int main()
{
    struct Node *head = NULL;

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int coeff, exp;
        scanf("%d %d", &coeff, &exp);

        insert(&head, coeff, exp);
    }

    display(head);

    return 0;
}