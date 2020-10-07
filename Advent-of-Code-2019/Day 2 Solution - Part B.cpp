#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <iterator>
#include <tuple>
#include <fstream>

using namespace std;

vector<int> CreateNumbersVec(string s) {
	vector<int> vec = {};
	string dummy = "";
	for (size_t i = 0; i < s.size(); ++i) {
		while (!((s[i] == ',') || (i == s.size() - 1))) {
			dummy.push_back(s[i]);
			++i;
		}
		if (s[i] == ',') {
			vec.push_back(stoi(dummy));
			dummy = "";
			continue;
		}
		else if (i == s.size() - 1) {
			dummy.push_back(s[i]);
			vec.push_back(stoi(dummy));
			dummy = "";
			return vec;
		}
	}
	
}

int main(){
	string input = "";
	cin >> input;
	vector<int> V = CreateNumbersVec(input);
	vector<int> origV = V;
	bool found = false;
	for (int x = 0; x <= 99; ++x) {
		for (int y = 0; y <= 99; ++y) {
			V[1] = x;
			V[2] = y;
			for (size_t i = 0; i < V.size(); ++i) {
				if (V[i] == 99) {
					break;
				}
				else {
					if (V[i] == 1) {
						V[V[i + 3]] = (V[V[i + 1]]) + (V[V[i + 2]]);
						i += 3;
						continue;
					}
					else if (V[i] == 2) {
						V[V[i + 3]] = (V[V[i + 1]]) * (V[V[i + 2]]);
						i += 3;
						continue;
					}
				}
			}
			cout << "For x = " << x << ", y = " << y << " OUTPUT = " << V[0] << "\n";
			if (V[0] == 19690720) {
				cout << (x * 100) + y << "\n";
				V = origV;
				found = true;
				break;
			}
			else {
				V = origV;
			}
		}
		if (found) {
			break;
		}
	}
	return 0;
}