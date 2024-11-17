#include <stdio.h>

int is_prime(int n) {
  if (n <= 1) {
    return 0;
  }
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}

int main() {
  int n;
  printf("Enter an integer: ");
  scanf("%d", &n);
  if (is_prime(n)) {
    printf("%d is a prime number.\n", n);
  } else {
    printf("%d is not a prime number.\n", n);
  }
  return 0;
}