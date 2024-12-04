#include <stdio.h>

main(argc, argv)
int argc;
char *argv[];
{
    int c, count;
    count = 0;
    FILE *input;
    switch (argc) {
        /* Command Line Input */
        case 1:
            while ((c = getchar()) != EOF   )
                if (c == '\n')
                    ++count;
            printf("\nThere are %d newlines.\n", count);
            return;
        /* File Input */
        case 2:
            input = fopen(argv[1], "r");

            while ((c = fgetc(input)) != EOF)
                if (c == '\n')
                    ++count;
            printf("There are %d newlines in %s.\n", count, argv[1]);
            return;
        /* Too many args */
        default:
            printf("This command accepts either a single file or user input");
            return;
            
    }
}