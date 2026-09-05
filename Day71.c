#include <stdio.h>
#include <string.h>

#define EMPTY -1

int main() {
    int m, q;
    scanf("%d", &m);
    scanf("%d", &q);

    int table[m];

    for (int i = 0; i < m; i++) {
        table[i] = EMPTY;
    }

    char operation[10];
    int key;

    for (int i = 0; i < q; i++) {
        scanf("%s %d", operation, &key);

        int h = key % m;

        if (strcmp(operation, "INSERT") == 0) {

            for (int j = 0; j < m; j++) {
                int index = (h + j * j) % m;

                if (table[index] == EMPTY) {
                    table[index] = key;
                    break;
                }
            }

        } else if (strcmp(operation, "SEARCH") == 0) {

            int found = 0;

            for (int j = 0; j < m; j++) {
                int index = (h + j * j) % m;

                if (table[index] == key) {
                    found = 1;
                    break;
                }

                if (table[index] == EMPTY) {
                    break;
                }
            }

            if (found)
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}