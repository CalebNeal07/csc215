#include <stdio.h>

#define TRUE 1;
#define FALSE 0;

print_help_msg() {
    printf("All commands operate on standard input or a list files entered as command line arguments.\n")
    printf("\n");
    printf("Commands:")
    printf("\t-n\t\tCounts blanks, tabs, and newlines. (1-6)\n")
}

main(argc, argv)
int argc;
char *argv[];
{
    FILE f;
    int input, count;
    count = 0;

    if (argc == 1) {
        print_help_msg();
    } else if (argc == 2) {
        switch (argv[1]) {
        case "-n":
            while((input = getchar()) != EOF) {
                if (input == '\t' || input == ' ' || input == '\n')
                    printf("Count incremented");
                    count++;
            }
            printf("There are %d tabs, spaces, and newlines", count);
        default:
            print_help_msg();
        }
    } else {

    }
}