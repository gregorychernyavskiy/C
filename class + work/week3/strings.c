#include <stdio.h>

/*
There are two common ways you'll create statically allocated strings:asm

char a[] = "Foo"; // a string array (a char array which is a string); 
                  // compiler copies literal into the array. Array is mutable.

char *p = "Bar"; // a pointer to string literal;
                 // the pointer can be pointing elsewhere (it is mutable), 
                 // but the literal is immutble.

All stings in C are terminated by NULL byte ('\0'). When using a string literal,
the compiler automatically adds this byte for us at the end of the string.

You can have a char array that is not a string. If there's no terminating NULL, it is not a string, 
and it is an error to use string functions on it.
*/


int strcmp3270(const char *s1, const char *s2) {
    int i;
    
    for(i = 0; s1[i] && s1[i] == s2[i]; i++)
        ;

    return s1[i] - s2[i];
}


int strlen3270(const char *s) {
    int i;

    for(i = 0; s[i]; i++)
    ;

    return i;
}


char *strcpy3270(char *dst, const char *src) {
    int i;

    for(i = 0; (dst[i] = src[i]); i++)
    ;

    return dst;
}


int main(int argc, char *argv[]) {
    char a[] = "Hello";
    char b[] = "Goodbye";
    char *c = "Hello";

    printf("%d\t%d\n", strcmp3270(a, b), strcmp3270(a, c));
    b[0] = 'H';
    printf("%d\t%d\n", strcmp3270(a, b), strcmp3270(a, c));
    //c[0] = 'J'; // the string is not mutable
    printf("%d\t%d\n", strcmp3270(a, b), strcmp3270(a, c));

    strcpy3270(b, a);
    printf("%s\n", b);
    printf("%s\n", b + strlen3270(b) + 1); // Valid and well defined.

    return 0;
}