#include <stdio.h>


int aliquot_sum(int n) {
    int sum = 0;
    if (n <= 1) {
        return 0;
    }
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    int n;
    int aliquot = aliquot_sum(n);
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Aliquot sum of %d is %d\n", n, aliquot_sum(n));
    if (aliquot == n) {
        printf("%d is a perfect number.\n", n);
    } else if (aliquot < n) {
        printf("%d is a deficient number.\n", n);
    } else {
        printf("%d is an abundant number.\n", n);
    }
    return 0;
}