#include <stdio.h>

// Function to calculate the sum of an arithmetic series
double arithmetic_series_sum(double a, double d, int n) {
    return (n * (2 * a + (n - 1) * d)) / 2;
}

// Function to calculate the sum of a geometric series
double geometric_series_sum(double a, double r, int n) {
    if (r == 1) {
        return a * n;
    } else {
        return a * (1 - pow(r, n)) / (1 - r);
    }
}

// Function to generate the first N numbers in the Fibonacci series
void fibonacci_series(int n) {
    int a = 0, b = 1, c;
    printf("%d %d ", a, b);
    for (int i = 2; i < n; i++) {
        c = a + b;
        printf("%d ", c);
        a = b;
        b = c;
    }
}

// Function to calculate the sum of the squares of the first N natural numbers
double sum_of_squares(int n) {
    return (n * (n + 1) * (2 * n + 1)) / 6;
}

// Function to calculate the n-th triangular number
int triangular_number(int n) {
    return n * (n + 1) / 2;
}

// Function to calculate the sum of the first N terms of a harmonic series
double harmonic_series_sum(int n) {
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += 1.0 / i;
    }
    return sum;
}

// Function to calculate the sum of the factorials of the first N natural numbers
double factorial_series_sum(int n) {
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        double factorial = 1;
        for (int j = 1; j <= i; j++) {
            factorial *= j;
        }
        sum += factorial;
    }
    return sum;
}

// Function to calculate the sum of the first N terms of an alternating series
double alternating_series_sum(int n) {
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += pow(-1, i + 1) * i;
    }
    return sum;
}

// Function to calculate the sum of the first N terms of the exponential series
double exponential_series_sum(double x, int n) {
    double sum = 1;
    for (int i = 1; i <= n; i++) {
        sum += pow(x, i) / factorial(i);
    }
    return sum;
}

// Function to calculate the factorial of a number
double factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Function to calculate the sum of the first N terms of an arithmetic-geometric series
double arithmetic_geometric_series_sum(double a, double d, double r, int n) {
    if (r == 1) {
        return n * (a + (n - 1) * d);
    } else {
        return a * (1 - pow(r, n)) / (1 - r) + d * ((n - 1) * r + 1 - pow(r, n)) / (1 - r)^2;
    }
}

int main() {
    // Example usage of the functions

    // Arithmetic series sum
    double arithmetic_sum = arithmetic_series_sum(1, 2, 10);
    printf("Sum of arithmetic series: %.2f\n", arithmetic_sum);

    // Geometric series sum
    double geometric_sum = geometric_series_sum(2, 0.5, 5);
    printf("Sum of geometric series: %.2f\n", geometric_sum);

    // Fibonacci series
    fibonacci_series(10);
    printf("\n");

    // Sum of squares
    double sum_squares = sum_of_squares(5);
    printf("Sum of squares: %.2f\n", sum_squares);

    // Triangular number
    int triangular_num = triangular_number(7);
    printf("Triangular number: %d\n", triangular_num);

    // Harmonic series sum
    double harmonic_sum = harmonic_series_sum(10);
    printf("Sum of harmonic series: %.2f\n", harmonic_sum);

    // Factorial series sum
    double factorial_sum = factorial_series_sum(5);
    printf("Sum of factorial series: %.2f\n", factorial_sum);

    // Alternating series sum
    double alternating_sum = alternating_series_sum(5);
    printf("Sum of alternating series: %.2f\n", alternating_sum);

    // Exponential series sum
    double exponential_sum = exponential_series_sum(2, 5);
    printf("Sum of exponential series: %.2f\n", exponential_sum);

    // Arithmetic-geometric series sum
    double arithmetic_geometric_sum = arithmetic_geometric_series_sum(1, 2, 0.5, 5);
    printf("Sum of arithmetic-geometric series: %.2f\n", arithmetic_geometric_sum);

    return 0;
}