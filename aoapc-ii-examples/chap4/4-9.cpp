int sum1(int *begin, int *end) {
    int n = end - begin;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += begin[i];
    }
    return ans;
}

int sum2(int *begin, int *end) {

    int ans = 0;
    for (int *p = begin; p != end; p++) {
        ans += *p;
    }
    return ans;
}
