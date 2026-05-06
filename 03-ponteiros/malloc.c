#include <stdio.h>
#include <stdlib.h>

int main() {

    char *s = "Hello World!";

    printf("%s\n", s);

    free(s);

}