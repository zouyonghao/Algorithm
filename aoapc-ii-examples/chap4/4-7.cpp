// ERROR
int sum(int a[]) {
    int ans = 0;
    // sizeof can't calculate a's size.
    for (int i = 0; i < sizeof(a); i++) {
        ans += a[i];
    }
    return ans;
}