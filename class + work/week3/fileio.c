#include <stdio.h>
#include <math.h> // For M_PI. If calling funtions, must link with math library (-lm).

typedef enum {
    operation_rt,
    operation_rb,
    operation_wt,
    operation_wb //write binary
} operation;


void usage(const char *s) {
    //The runtime opens three files for us before main begins.
    //These are stdin, stdout, and stderr
    fprintf(stderr, "%s [-rt|-rb|-wt|-wb]\n", s);
}


int main(int argc, char *argv[]) {
    operation op;
    int error;

    struct {
        int i;
        int j;
        double d;
    } in, out;

    out.i = 1;
    out.j = 65537;
    out.d = M_PI;

    error = 1;
    if (argc == 2 && argv[1][0] == '-') {
        //read
        if(argv[1][1] == 'r') { 
            //text
            if(argv[1][2] == 't') {
                op = operation_rt;
                error = 0;
            //binary
            } else if (argv[1][2] == 'b') {
                op = operation_wb;
                error = 0;
            }
        }
    }
    if (error) {
        usage(argv[0]);

        return -1;
    }


    switch (op) {
        case operation_rt:
            break;
        case operation_wt:
            break;
        case operation_rb:
            break;
        case operation_wb:
            break;
    }

    return 0;
}