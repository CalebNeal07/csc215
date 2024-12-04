#include <stdio.h>

main(argc, argv)
int argc;
char *argv[];
{
    int c, count;
    count = 0;
    FILE *input;

    /* Command Line Input */
    if (argc == 1) {
        while ((c = getchar()) != EOF   )
            if (c == '\n')
                ++count;
        printf("\nYou entered %d newlines\n", count);
        return;

    /* File Input */
    } else {
        int i;
        for (i = 1; i < argc; i++) {
            count = 0;
            input = fopen(argv[i], "r");

            while ((c = fgetc(input)) != EOF)
                if (c == '\n')
                    ++count;
            printf("There are %d newlines in %s\n", count, argv[i]);
            fclose(input);
        }
        return;
    }
}