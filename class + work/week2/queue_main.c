#include <stdio.h>
#include "queue.h"

int main(int argc, char *argv[]) {
    struct queue q;
    int i, j;

    queue_init(&q); // checks return value

    for(i = 0; i < 10; i++) {
        queue_enqueue(&q, i);
    }

    queue_front(&q, &j);

    printf("length: %d, is empty: %d, front: %d\n", queue_size(&q), queue_is_empty(&q), j);

    while(!queue_dequeue(&q, &j)) {
        printf("%d\n", j);
    }

    printf("length: %d, is empty: %d, front: %d", queue_size(&q), queue_is_empty(&q), j);

    queue_destroy(&q);

    return 0;
}