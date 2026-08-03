/* Problem: Deque (Double-Ended Queue)

A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

Common Operations:
1. push_front(value): Insert an element at the front of the deque.
2. push_back(value): Insert an element at the rear of the deque.
3. pop_front(): Remove an element from the front of the deque.
4. pop_back(): Remove an element from the rear of the deque.
5. front(): Return the front element of the deque.
6. back(): Return the rear element of the deque.
7. empty(): Check whether the deque is empty.
8. size(): Return the number of elements in the deque.

Additional Operations:
- clear(): Remove all elements from the deque.
- erase(): Remove one or more elements from the deque.
- swap(): Swap contents of two deques.
- emplace_front(): Insert an element at the front without copying.
- emplace_back(): Insert an element at the rear without copying.
- resize(): Change the size of the deque.
- assign(): Replace elements with new values.
- reverse(): Reverse the order of elements.
- sort(): Sort the elements in ascending order.

Time Complexity:
- push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
- clear, erase, resize, assign, reverse: O(n)
- sort: O(n log n)

Input:
- Sequence of deque operations with values (if applicable)

Output:
- Results of operations such as front, back, size, or the final state of the deque after all operations */

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct {
    int arr[MAX];
    int front;
    int rear;
    int size;
} Deque;

// Initialize Deque
void initDeque(Deque *dq) {
    dq->front = -1;
    dq->rear = -1;
    dq->size = 0;
}

// Check if empty
int empty(Deque *dq) {
    return dq->size == 0;
}

// Check if full
int full(Deque *dq) {
    return dq->size == MAX;
}

// Push Front
void push_front(Deque *dq, int value) {
    if (full(dq)) {
        printf("Deque Overflow\n");
        return;
    }

    if (empty(dq)) {
        dq->front = dq->rear = 0;
    } else {
        dq->front = (dq->front - 1 + MAX) % MAX;
    }

    dq->arr[dq->front] = value;
    dq->size++;
}

// Push Back
void push_back(Deque *dq, int value) {
    if (full(dq)) {
        printf("Deque Overflow\n");
        return;
    }

    if (empty(dq)) {
        dq->front = dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % MAX;
    }

    dq->arr[dq->rear] = value;
    dq->size++;
}

// Pop Front
void pop_front(Deque *dq) {
    if (empty(dq)) {
        printf("Deque Underflow\n");
        return;
    }

    if (dq->size == 1) {
        dq->front = dq->rear = -1;
    } else {
        dq->front = (dq->front + 1) % MAX;
    }

    dq->size--;
}

// Pop Back
void pop_back(Deque *dq) {
    if (empty(dq)) {
        printf("Deque Underflow\n");
        return;
    }

    if (dq->size == 1) {
        dq->front = dq->rear = -1;
    } else {
        dq->rear = (dq->rear - 1 + MAX) % MAX;
    }

    dq->size--;
}

// Front Element
int front(Deque *dq) {
    if (empty(dq))
        return -1;
    return dq->arr[dq->front];
}

// Back Element
int back(Deque *dq) {
    if (empty(dq))
        return -1;
    return dq->arr[dq->rear];
}

// Size
int size(Deque *dq) {
    return dq->size;
}

// Clear
void clear(Deque *dq) {
    dq->front = dq->rear = -1;
    dq->size = 0;
}

// Display Deque
void display(Deque *dq) {
    if (empty(dq)) {
        printf("Deque is Empty\n");
        return;
    }

    int i = dq->front;
    int count = 0;

    while (count < dq->size) {
        printf("%d ", dq->arr[i]);
        i = (i + 1) % MAX;
        count++;
    }
    printf("\n");
}

// Driver Code
int main() {
    Deque dq;
    initDeque(&dq);

    push_back(&dq, 10);
    push_back(&dq, 20);
    push_front(&dq, 5);
    push_front(&dq, 1);

    printf("Deque: ");
    display(&dq);

    printf("Front = %d\n", front(&dq));
    printf("Back = %d\n", back(&dq));
    printf("Size = %d\n", size(&dq));

    pop_front(&dq);
    pop_back(&dq);

    printf("After Pop Operations: ");
    display(&dq);

    clear(&dq);

    printf("After Clear: ");
    display(&dq);

    return 0;
}