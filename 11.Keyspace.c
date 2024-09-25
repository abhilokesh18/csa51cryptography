#include <stdio.h>
#include <math.h>

unsigned long long factorial(int n) {
    unsigned long long fact = 1;
    for (int i = 1; i <= n; i++) fact *= i;
    return fact;
}

int findPowerOf2(unsigned long long n) {
    return (int)(log(n) / log(2));
}

int main() {
    int n;
    printf("Enter the number of characters (up to 25): ");
    scanf("%d", &n);
    if (n > 0 && n <= 25) {
        unsigned long long totalKeys = factorial(n);
        int powerOf2_total = findPowerOf2(totalKeys);
        unsigned long long uniqueKeys = totalKeys / (8 * n);
        int powerOf2_unique = findPowerOf2(uniqueKeys);
        printf("The total number of possible keys is approximately 2^%d.\n", powerOf2_total);
        printf("The total number of effectively unique keys is approximately 2^%d.\n", powerOf2_unique);
    } else {
        printf("Please enter a valid number between 1 and 25.\n");
    }
    return 0;
}
