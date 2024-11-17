#include <stdio.h>

int modular_exponentiation(int base, int exponent, int modulus) {
    int result = 1;
    base %= modulus;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }

        exponent /= 2;
        base = (base * base) % modulus;
    }

    return result;
}

int compute_power_mod_prime(int A, int B, int P) {
    // Ensure P is a prime number (you might want to add a primality test here)
    if (P <= 1) {
        return 0; // Handle invalid input
    }

    // Apply Fermat's Little Theorem: A^(P-1) ≡ 1 (mod P)
    int exponent = B % (P - 1); // Reduce the exponent modulo P-1

    return modular_exponentiation(A, exponent, P);
}

int main() {
    int A, B, P;

    printf("Enter A, B, and P (a prime number): ");
    scanf("%d %d %d", &A, &B, &P);

    int result = compute_power_mod_prime(A, B, P);
    printf("(A^B) mod P = %d\n", result);

    return 0;
}