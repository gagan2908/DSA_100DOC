#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Meeting;

// Sort meetings by start time
int compare(const void *a, const void *b) {
    Meeting *m1 = (Meeting *)a;
    Meeting *m2 = (Meeting *)b;

    return m1->start - m2->start;
}

// Insert into min heap
void push(int heap[], int *size, int value) {
    int i = (*size)++;
    heap[i] = value;

    while (i > 0) {
        int parent = (i - 1) / 2;

        if (heap[parent] <= heap[i])
            break;

        int temp = heap[parent];
        heap[parent] = heap[i];
        heap[i] = temp;

        i = parent;
    }
}

// Remove minimum element
int pop(int heap[], int *size) {
    int minValue = heap[0];

    heap[0] = heap[--(*size)];

    int i = 0;

    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < *size && heap[left] < heap[smallest])
            smallest = left;

        if (right < *size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == i)
            break;

        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;

        i = smallest;
    }

    return minValue;
}

int minMeetingRooms(int start[], int end[], int n) {

    Meeting meetings[n];

    for (int i = 0; i < n; i++) {
        meetings[i].start = start[i];
        meetings[i].end = end[i];
    }

    // Sort by start time
    qsort(meetings, n, sizeof(Meeting), compare);

    // Min heap containing end times
    int heap[n];
    int heapSize = 0;
    int maxRooms = 0;

    for (int i = 0; i < n; i++) {

        // Reuse room if previous meeting has ended.
        // Equal time is allowed.
        if (heapSize > 0 && heap[0] <= meetings[i].start) {
            pop(heap, &heapSize);
        }

        // Allocate room for current meeting
        push(heap, &heapSize, meetings[i].end);

        if (heapSize > maxRooms)
            maxRooms = heapSize;
    }

    return maxRooms;
}

int main() {

    int start[] = {2, 9, 6};
    int end[] = {4, 12, 10};

    int n = sizeof(start) / sizeof(start[0]);

    printf("Minimum rooms required = %d\n",
           minMeetingRooms(start, end, n));

    return 0;
}