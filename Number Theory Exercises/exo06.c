#include <stdio.h>

int phi(int n) {
    int result = n;

    for (int p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }

    if (n > 1)
        result -= result / n;

    return result;
}

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Euler's Totient Function for %d is %d\n", n, phi(n));

    return 0;
}