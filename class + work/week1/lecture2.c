#include <stdio.h>    // For input/output functions like printf
#include <ctype.h>    // For character testing functions like isdigit
#include <stdlib.h>   // For utility functions like atoi (convert string to integer)

int main(int argc, char *argv[]) {
    int i, j;

    if(argc == 1) {   // argc == 1 means no arguments were passed (only program name is present)
        printf("Hellooo \n");
    } else {
        for(i = 1; i < argc; i++) {   // Loop through all arguments starting from argv[1]

            if(isdigit(argv[i][0])){  // Check if the first character of the argument is a digit
                printf("%d\n", atoi(argv[i]));  // Convert the string argument to an integer and print it
            } 
              else {
                printf("Hello ");

                for(j = 0; argv[i][j]; j++) {   // Loop through each character of the current argument
                    printf("%c", argv[i][j]);
                }
                printf("!\n");
            }
        }
    }
    return 0;
}
