#include <stdio.h>

int modularExponentiation(int A, int B, int M) {
    int result = 1;

    A = A % M; // Update A if it is more than or equal to M

    while (B > 0) {
        // If B is odd, multiply A with result
        if (B & 1) {
            result = (result * A) % M;
        }

        // B becomes B/2
        B = B >> 1;

        // A square is multiplied to A
        A = (A * A) % M;
    }

    return result;
}

int main() {
    int A, B, M;

    printf("Enter A, B, and M: ");
    scanf("%d %d %d", &A, &B, &M);

    int result = modularExponentiation(A, B, M);
    printf("(A^B) mod M = %d\n", result);

    return 0;
}