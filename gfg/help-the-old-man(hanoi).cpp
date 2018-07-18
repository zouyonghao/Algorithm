// https://practice.geeksforgeeks.org/problems/help-the-old-man/0
#include <iostream>
using namespace std;

int printed;
int needPrinted;

void move(int n, int source, int buffer, int destination) {
    if (n <= 0 || printed >= needPrinted) return;
    move(n-1, source, destination, buffer);
    printed++;
    if (printed == needPrinted) {
        cout << source << " " << destination << endl;
        return;
    }
    move(n-1, buffer, source, destination);
}

int main() {
	int n;
	cin >> n;
    int m;
	while (n-- > 0) {
	    cin >> m >> needPrinted;
	    printed = 0;
	    move(m, 1, 2, 3);
	}
	return 0;
}