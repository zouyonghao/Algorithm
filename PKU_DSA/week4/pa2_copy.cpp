#include <iostream>
#include <string>
using namespace std;
string d[10001];
bool checksame(string a, string b) { return a == b; }
bool checksimilar(string a, string b) {
    if (a.length() == b.length()) //长度相等则进行1次替换
    {
        int count = 0;
        for (int i = 0; i < a.length(); ++i) {
            if (a[i] != b[i])
                ++count;
            if (count > 1)
                return false;
        }
        return true;
    } else if (
        a.length() - b.length() ==
        1) //长度差1则进行一次插入/删除，实现方法是在某一位置时只挪动一个字符串的游标
    {
        bool flag = false;
        for (int i = 0, j = 0; i < a.length(), j < b.length(); ++i, ++j) {
            if (a[i] != b[j]) {
                if (flag)
                    return false;
                if (!flag) {
                    --j;
                    flag = true;
                }
            }
        }
        return true;
    } else if (a.length() - b.length() == -1) {
        bool flag = false;
        for (int i = 0, j = 0; i < a.length(), j < b.length(); ++i, ++j) {
            if (a[i] != b[j]) {
                if (flag)
                    return false;
                if (!flag) {
                    --i;
                    flag = true;
                }
            }
        }
        return true;
    } else
        return false;
}
int main() {
    int n = 0;
    while (1) {
        cin >> d[n];
        ++n;
        if (d[n - 1] == "#")
            break;
    }
    --n;
    while (1) {
        string t;
        cin >> t;
        if (t == "#")
            break;
        bool flag = false;
        for (int i = 0; i < n; ++i) {
            if (checksame(t, d[i])) {
                cout << t << " is correct" << endl;
                flag = true;
                break;
            }
        }
        if (flag)
            continue;
        cout << t << ": ";
        for (int i = 0; i < n; ++i) {
            if (checksimilar(t, d[i]))
                cout << d[i] << " ";
        }
        cout << endl;
    }
    return 0;
}