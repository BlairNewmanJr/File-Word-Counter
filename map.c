#include <stdio.h>
#include <stdlib.h>
/*
 * _main @ 0x4005c2
 * recur @ 0x40057d
 * _main stack: 0x7fffda11f73c
 * static data: 0x601048
* Heap: malloc 2: 0x671080
 * recur call 3: stack@ 0x7fffda11f6fc
 * recur call 2: stack@ 0x7fffda11f6cc
 * recur call 1: stack@ 0x7fffda11f69c
 *  recur call 0: stack@ 0x7fffda11f66c
 */
/* A statically allocated variable */
int foo;
extern int recur(int i);
/* A statically allocated, pre-initialized variable */
volatile int stuff = 7;
int main(int argc, char *argv[]) {
    printf("_main @ %p\n", main);
    /* A stack allocated variable */
    volatile int i = 0;
    printf("main stack: %p\n", &i);
    /* Dynamically allocate some stuff */
    volatile char *buf1 = malloc(100);
    printf("Heap: malloc 1: %p\n", buf1);
    /* ... and some more stuff */
    volatile char *buf2 = malloc(100);
    printf("Heap: malloc 2: %p\n", buf2);
    recur(3);
    return 0;
}
