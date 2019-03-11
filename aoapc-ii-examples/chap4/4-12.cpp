void guess(char ch) {
    int bad = 1;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == ch) {
            left--;
            s[i] = ' ';
            bad = 0;
        }
    }
    if (bad)
        --chance;
    if (!chance)
        lose = 1;
    if (!left)
        win = 1;
}