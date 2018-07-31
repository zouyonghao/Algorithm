#include <memory>
#include <string>
#include <cstring>
#include <iostream>
#include <stdio.h>
using namespace std;

int wall[20];
int originWall[20];
int paint[20]; 

int GetBit(int n, int i) {
    return (n >> i) & 1;
}

void SetBit(int &n, int i, int v) {
    if (v) {
        n |= (1 << i);
    } else {
        n &= ~(1 << i);
    }
}

void FlipBit(int &n, int i) {
    n ^= (1 << i);
}

int main() {
    // freopen("input", "r", stdin);
    // this cases is for the test on Coursera.
    int cases;
    cin >> cases;
    while (cases-- > 0) {
        int n;
        cin >> n;
        // cout << n << endl;
        string tmp;
        memset(originWall, 0, sizeof(originWall));
        for (int i = 1; i <= n; i++) {
            cin >> tmp;
            originWall[i] = 0;
            for (int j = 0; j < n; j++) {
                if (tmp[j] == 'w') {
                    SetBit(originWall[i], j + 1, 1);
                }
            }
        }

        bool bingo = true;
        int count = 0;
        for (int i = 0; i < (1 << n); i++) {
            bingo = true;
            count = 0;
            int paints = i << 1;
            memcpy(wall, originWall, sizeof(originWall));
            
            for (int j = 1; j <= n; j++) {
                paint[j] = paints;
                for (int k = 1; k <= n; k++) {
                    if (GetBit(paint[j], k)) {
                        count ++;
                        FlipBit(wall[j], k);
                        // FlipBit(wall[j - 1], k);
                        FlipBit(wall[j + 1], k);
                        FlipBit(wall[j], k - 1);
                        FlipBit(wall[j], k + 1);
                    }
                }
                paints = wall[j];
            }
            for (int l = 1; l <= n; l++) {
                if (GetBit(wall[n], l) == 1) {
                    bingo = false;
                    break;
                }
            }
            if (bingo) {
                break;
            }
        }

        if (bingo) {
            cout << count << endl;
        } else {
            cout << "inf" << endl;
        }

    }
    return 0;
}