#include <iostream>
#include <string>
using namespace std;

// negative,
string nums[] = {"zero",    "one",     "two",       "three",    "four",
                 "five",    "six",     "seven",     "eight",    "nine",
                 "ten",     "eleven",  "twelve",    "thirteen", "fourteen",
                 "fifteen", "sixteen", "seventeen", "eighteen", "nineteen",
                 "twenty"};
string bigs[] = {"thirty",  "forty",  "fifty", "sixty",
                 "seventy", "eighty", "ninety"};
string more[] = {"hundred", "thousand", "million"};
int mNum[] = {100, 1000, 1000000};

bool findInNums(string current, int &number) {
    for (int i = 0; i < 21; i++) {
        if (current == nums[i]) {
            number = i;
            return true;
        }
    }
    return false;
}
bool findInBigs(string current, int &bigger) {
    for (int i = 0; i < 7; i++) {
        if (current == bigs[i]) {
            bigger = i * 10 + 30;
            return true;
        }
    }
    return false;
}

bool findInMore(string current, int &morrer) {
    for (int i = 0; i < 3; i++) {
        if (current == more[i]) {
            morrer = mNum[i];
            return true;
        }
    }
    return false;
}

int main() {
    string a;
    while (getline(cin, a)) {
        long result = 0;
        long tmp = 0;
        bool negative = false;
        string current = "";
        if (a.length() <= 0) {
            return 0;
        }
        while (a.length() > 0) {
            int nextPos = a.find_first_of(" ");
            if (nextPos < 0) {
                current = a;
                a = "";
            } else {
                current = a.substr(0, nextPos);
                a = a.substr(nextPos + 1);
            }
            int number;
            int bigger;
            int morrer;
            if (current == "negative") {
                negative = true;
            } else if (findInNums(current, number)) {
                // result += number;
                tmp += number;
            } else if (findInBigs(current, bigger)) {
                // result += bigger;
                tmp += number;
            } else if (findInMore(current, morrer)) {
                if (current == "hundred") {
                    tmp *= morrer;
                } else {
                    tmp *= morrer;
                    result += tmp;
                    tmp = 0;
                }
            }
        }
        if (negative) {
            cout << "-";
        }
        if (tmp > 0) {
            result += tmp;
        }
        cout << result << endl;
        result = 0;
        current = "";
        negative = false;
        tmp = 0;
    }
}