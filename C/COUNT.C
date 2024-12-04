#include <stdio.h>

int main() {
    int input, count;
    count = 0;

    while((input = getchar()) != EOF) {
        if (input == '\t' || input == ' ' || input == '\n')
            printf("Count incremented");
            count++;
    }
    printf("There are %d tabs, spaces, and newlines", count);
}