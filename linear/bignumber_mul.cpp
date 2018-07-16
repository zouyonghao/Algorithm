#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

string add(string a, string b) {
    int i = a.length() - 1, j = b.length() - 1;
    int sum;
    int ai, bj;
    int succeed = 0;
    string result = "";
    while (i >= 0 && j >= 0) {
        ai = a[i] - '0';
        bj = b[j] - '0';
        sum = ai + bj + succeed;
        succeed = sum / 10;
        sum = sum % 10;
        result = char(sum + '0') + result;
        i--;
        j--;
    }
    while (i >= 0) {
        ai = a[i] - '0';
        sum = ai + succeed;
        succeed = sum / 10;
        sum = sum % 10;
        result = char(sum + '0') + result;
        i--;
    }
    while (j >= 0) {
        bj = b[j] - '0';
        sum = bj + succeed;
        succeed = sum / 10;
        sum = sum % 10;
        result = char(sum + '0') + result;
        j--;
    }
    if (succeed > 0) {
        result = char(succeed + '0') + result;
    }
    return result;
}

int main() {
    string a, b;
    cin >> a >> b;
    if (a.length() > b.length()) {
        swap(a, b);
    }
    // cout << add(a, b) << endl;
    string result = "";
    int succeed = 0;
    int ai, bj;
    int mul;
    for (int i = a.length() - 1; i >= 0; i--) {
        ai = a[i] - '0';
        string tmp = "";
        succeed = 0;
        for (int j = b.length() - 1; j >= 0; j--) {
            bj = b[j] - '0';
            mul = ai * bj + succeed;
            succeed = mul / 10;
            mul = mul % 10;
            tmp = char(mul + '0') + tmp;
        }
        if (succeed > 0) {
            tmp = char(succeed + '0') + tmp;
        }
        for (int k = 0; k < a.length() - 1 - i; k++) {
            tmp = tmp + "0";
        }
        result = add(tmp, result);
    }
    result.erase(0, result.find_first_not_of('0'));//去掉前导零
    cout << result << endl;
    return 0;
}