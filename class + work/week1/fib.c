#include <stdio.h>
#include <stdlib.h>

//unsigned is positive (can't be negative)
unsigned fib(unsigned n){
    if(n <= 1) {
        return n;
    }

    return fib(n - 1) + fib(n - 2);
} 

int main(int argc, char *argv[]) {
    
    printf("fib(%d): %d\n", atoi(argv[1]), fib(atoi(argv[1])));
    return 0;
}