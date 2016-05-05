#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Goods{
	int weight;
	int value;
	double unitValue;

	public:
		Goods() {

		}

		Goods(int weight, int value) {
			this->weight = weight;
			this->value = value;
			this->unitValue = (double)value / weight;
		}

		int getWeight() {
			return this->weight;
		}

		int getValue() {
			return this->value;
		}

		double getUnitValue() {
			return this->unitValue;
		}
};

bool goodsSort(Goods& a, Goods& b) {
	return a.getUnitValue() > b.getUnitValue();
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
	double value = 0.0;

	vector<Goods> unitValues;

	for (int i = 0; i < weights.size(); i++) {
		unitValues.push_back(Goods (weights[i], values[i]));
	}

	std::sort(unitValues.begin(), unitValues.end(), goodsSort);

	for (int i = 0; i < unitValues.size(); i++) {
		if (capacity == 0) {
			break;
		}
		int curGoodWeight = unitValues[i].getWeight();
		if (curGoodWeight > capacity) {
			curGoodWeight = capacity;
		}
		value += unitValues[i].getUnitValue() * curGoodWeight;
		capacity -= curGoodWeight;
	}

	return value;
}

int main() {
	int n;
	int capacity;
	std::cin >> n >> capacity;
	vector<int> values(n);
	vector<int> weights(n);
	for (int i = 0; i < n; i++) {
		std::cin >> values[i] >> weights[i];
	}

	double optimal_value = get_optimal_value(capacity, weights, values);

	printf("%.4lf\n", optimal_value);

	return 0;
}
