#include <stdio.h>

main(argc, argv)
int argc;
char *argv[];
{
    int c;
    char* s;

    if (argc == 1) {
        while ((c = getchar()) != EOF) {
            if (c == '\t') {
                putchar('>');
                putchar('\b');
                putchar('-');
            } else {
                putchar(c); 
            }
        }
    }
}