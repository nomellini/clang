#include <stdio.h>
#include <string.h>

int main() {

    char *bin = "10000";
    size_t len = strlen(bin);

    int dec = 0;
    for(size_t i = 0; i<len; i++) {
        int digit = bin[len-i-1] - '0';
        int value = 1 << i;
        dec += digit * value;
    }


    printf("binário: %s\n", bin);
    printf("Decimal %d\n", dec);

    return 0;
}