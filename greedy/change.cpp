#include <iostream>

int get_change(int n) {
	int count = 0;

	while (n >= 10) {
		n -= 10;
		count++;
	}

	while (n >= 5) {
		n -= 5;
		count++;
	}

	while (n >= 1) {
		n -= 1;
		count++;
	}

	return count;
}

int main() {
	int n;
	std::cin >> n;
	std::cout << get_change(n) << '\n';
}
