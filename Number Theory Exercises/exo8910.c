#include <stdio.h>
#include <stdlib.h>

// Fermat's Little Theorem
int mod_pow(int a, int b, int p) {
    if (b == 0) return 1;
    int x = mod_pow(a, b / 2, p);
    x = (x * x) % p;
    if (b % 2 == 1) x = (x * a) % p;
    return x;
}

// Sum of Divisors
int sum_of_divisors(int n) {
    int sum = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i) sum += n / i;
        }
    }
    return sum;
}

// Linear Diophantine Equation
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
int mod_inverse(int a, int p) {
    return mod_pow(a, p - 2, p);
}
int solve_linear_diophantine_equation(int a, int b, int c) {
    int g = gcd(a, b);
    if (c % g != 0) return -1;
    int x0 = (c / g) * mod_inverse(a / g, b / g) % (b / g);
    return (x0 + b / g) % (b / g);
}

// Chinese Remainder Theorem
int chinese_remainder_theorem(int *n, int *r, int k) {
    int N = 1;
    for (int i = 0; i < k; i++) N *= n[i];
    int x = 0;
    for (int i = 0; i < k; i++) {
        int ni = N / n[i];
        int yi = mod_inverse(ni, n[i]);
        x += r[i] * ni * yi;
    }
    return x % N;
}

int main() {
    // Fermat's Little Theorem
    printf("Fermat's Little Theorem: (3^5) mod 7 = %d\n", mod_pow(3, 5, 7));

    // Sum of Divisors
    printf("Sum of Divisors: sum_of_divisors(24) = %d\n", sum_of_divisors(24));

    // Linear Diophantine Equation
    printf("Linear Diophantine Equation: 3x + 5y = 11, x = %d\n", solve_linear_diophantine_equation(3, 5, 11));

    // Chinese Remainder Theorem
    int n[] = {3, 5, 7};
    int r[] = {1, 2, 3};
    int k = 3;
    printf("Chinese Remainder Theorem: X mod 3 = 1, X mod 5 = 2, X mod 7 = 3, X = %d\n", chinese_remainder_theorem(n, r, k));

    return 0;
}