#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using std::sort;

bool myPrepare(int a, int b) {
	return a > b;
}

long long min_dot_product(vector<int> a, vector<int> b) {
	// write your code here
	long long result = 0;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), myPrepare);
	for (size_t i = 0; i < a.size(); i++) {
		// std::cout << a[i] << " " << b[i] << std::endl;
		result += (long long)a[i] * (long long)b[i];
	}
	return result;
}

int main() {
	size_t n;
	std::cin >> n;
	vector<int> a(n), b(n);
	for (size_t i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for (size_t i = 0; i < n; i++) {
		std::cin >> b[i];
	}
	std::cout << min_dot_product(a, b) << std::endl;

	getchar();
	getchar();
}
