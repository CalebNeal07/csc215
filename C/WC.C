#include <stdio.h>

#define TRUE 1;
#define FALSE 0;

print_help_msg() {
    printf("All commands operate on standard input or a list files entered as command line arguments.\n");
    printf("\n");
    printf("Commands:");
    printf("\t-n\t\tCounts blanks, tabs, and newlines. (1-6)\n");
    printf("\t-c\t\tEchoes the input with removed duplicate whitespace\n");
}

main(argc, argv)
int argc;
char *argv[];
{
    FILE f;
    int input, count, i;
    count = 0;
    char* buffer[256];
    int prev_ws;

    if (argc == 1) {
        print_help_msg();
    } else if (argc == 2) {
        switch (argv[1]) {
        case "-n": /* 1-6 */
            while((input = getchar()) != EOF) {
                if (input == '\t' || input == ' ' || input == '\n') 
                    count++;
            }

            printf("There are %d tabs, spaces, and newlines", count);
            return;
        case "-c" /* 1-7 */
            i = 0;
            prev_ws = FALSE;

            while((input = getchar()) != EOF) {
                if (input == " " && !prev_ws) {
                    prev_ws = TRUE;
                    buffer[i] = input;
                    i++;
                } else {
                    buffer[i] = input;
                    i++;
                    prev_ws = FALSE;
                }
            } 
            buffer[i] = 0;

            for (i = 0; buffer[i] != 0; i++) {
                printf("%c", buffer[i]);
            }
            return;
        default:
            print_help_msg();
        }
    } else {
        switch(argv[1]) {
        case "-n": /* 1-6 */
            for (i = 1; i < argc; i++) {
                f = fopen(argv[i], "r");

                while ((input = fgetc(f)) != EOF) {
                    if (input == '\t' || input == ' ' || input == '\n')
                        count++;
                }

                printf("There are %d tabs, spaces and newlines in %s.", count, argv[i]);
                fclose(f);
            }
            return;
        case "-c": /* 1-7 */
            for (i = 1; i < argc; i++) {
                f = fopen(argv[i], "r");
                prev_ws = FALSE;

                while ((input = fgetc(f)) != EOF) {
                    if (input == " " && !prev_ws) {
                        prev_ws = TRUE;
                        printf("%c", input);
                    } else {
                        printf("%c", input);
                    }
                }
                
                fclose(f);
            }
        default:
            print_help_msg();
        }
    }
}