#include <stdio.h>

int main() {
    char s[1000];
    int seen[26] = {0};

    scanf("%s", s);

    for (int i = 0; s[i] != '\0'; i++) {
        int index = s[i] - 'a';

        if (seen[index]) {
            printf("%c", s[i]);
            return 0;
        }

        seen[index] = 1;
    }

    printf("-1");

    return 0;
}