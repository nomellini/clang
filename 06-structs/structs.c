#include <stdio.h>
#include <stdlib.h>

struct Point {
    int x;
    int y;
};

int main() {
    struct Point *p1 = malloc(sizeof(struct Point));

    p1->x = 10;
    p1->y = 20;

    printf("Point p1: (%d, %d)\n", p1->x, p1->y);

    free(p1);
    return 0;
}

