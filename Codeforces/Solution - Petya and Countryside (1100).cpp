#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int RainLength(int x, vector<int>& V) {
	int base = V[x], counter = 1, original_index = x, current_height = base;
	++x;
	while ((x <= V.size() - 1) && (V[x] <= current_height)) {
		++counter;
		current_height = V[x];
		++x;
	}
	x = original_index;
	current_height = base;
	--x;
	while ((x >= 0) && (V[x] <= current_height)) {
		++counter;
		if (x >= 0) {
			current_height = V[x];
		}
		--x;
	}
	return counter;
}

int main() {
	int M = 0, N = 0, result = 0, highest_so_far = 0;
	vector<int>Vec = {};
	cin >> M;
	while (M > 0) {
		cin >> N;
		Vec.push_back(N);
		--M;
	}
	int blah = 0;
	for (int i = blah; i < Vec.size(); ++i) {
		result = RainLength(i, Vec);
		if (result > highest_so_far) {
			highest_so_far = result;
		}
	}
	cout << highest_so_far << "\n";
	return 0;
}