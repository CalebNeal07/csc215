#include <stdio.h>

int main() {
    int input, prev_whitespace;
    prev_whitespace = 0;

    while ((input = getchar()) != EOF) {
        /* Check if input is a whitespace character */
        if (input == ' ' || input == '\t') {
            if (prev_whitespace) {
                prev_whitespace = 0;
            } else {
                putchar(input);
                prev_whitespace = 1;
            }
        } else {
            putchar(input);
        }
    }
}