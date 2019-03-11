// if n = 1 or n is big, do not use this function
int is_prime(int n) {
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}