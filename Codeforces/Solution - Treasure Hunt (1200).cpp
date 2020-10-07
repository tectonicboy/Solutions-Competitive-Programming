#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
 
using namespace std;
 
int main() {
	bool possible = true;
	short inputs = 6U;
	long input = 0;
	vector<long>coords = {};
	while (inputs > 0) {
		cin >> input;
		coords.push_back(input);
		--inputs;
	}
	long result_x = coords[2] - coords[0], result_y = coords[3] - coords[1];
	if ((result_x % coords[4] != 0) || (result_y % coords[5] != 0)) {
		possible = false;
	}
	else {
		result_x /= coords[4];
		result_y /= coords[5];
 
		result_x = abs(result_x);
		result_y = abs(result_y);
 
		result_x = (result_x % 2);
		result_y = (result_y % 2);
 
		if (result_x != result_y) {
			possible = false;
		}
	}
	if (!possible) {
		cout << "NO\n";
	}
	else {
		cout << "YES\n";
	}
	return 0;
}