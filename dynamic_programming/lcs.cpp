#include <iostream>
using namespace std;

int lcs(string a, string b) {
    int **cheet = new int *[a.length() + 1];
    for (int i = 0; i < a.length() + 1; i++) {
        cheet[i] = new int[b.length() + 1];
    }
    for (int i = 0; i < b.length() + 1; i++) {
        cheet[0][i] = 0;
    }
    for (int i = 0; i < a.length() + 1; i++) {
        cheet[i][0] = 0;
    }
    for (int i = 1; i < a.length() + 1; i++) {
        for (int j = 1; j < b.length() + 1; j++) {
            // 这里注意不要错了！
            if (a[i - 1] == b[j - 1]) {
                cheet[i][j] = cheet[i - 1][j - 1] + 1;
            } else {
                cheet[i][j] = cheet[i - 1][j] > cheet[i][j - 1]
                                  ? cheet[i - 1][j]
                                  : cheet[i][j - 1];
            }
        }
    }
    return cheet[a.length()][b.length()];
}

int main(int argc, char const *argv[]) {
    string a, b;
    cin >> a;
    cin >> b;
    cout << lcs(a, b) << endl;

    return 0;
}
