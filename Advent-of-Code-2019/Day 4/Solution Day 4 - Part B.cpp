#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <iterator>
#include <tuple>
#include <fstream>

using namespace std;

vector<string> SeparateStrings(string &s) {
	vector<string> V;
	string str = "";
	for (size_t i = 0; i < s.size(); ++i) {
		while (!((s[i] == ',') || (i == s.size() - 1))) {
			str.push_back(s[i]);
			++i;
		}
		if (s[i] == ',') {
			V.push_back(str);
			str = "";
			continue;
		}
		if (i == s.size() - 1) {
			str.push_back(s[i]);
			V.push_back(str);
			return V;
		}
	}
}

bool isValidPass(string s) {
	bool two_adjacent = false;
	int same_count = 0;
	for (size_t i = 1; i < s.size(); ++i) {
		if (s[i] == s[i - 1]) {
			if (i == s.size() - 1) {
				two_adjacent = true;
				break;
			}
			else {
				if (i == s.size() - 2) {
					if (s[i] != s[i + 1]) {
						two_adjacent = true;
						break;
					}
					else {
						return false;
					}
				}
				else {
					for (size_t j = i + 1; j < s.size(); ++j) {

						if (s[j] == s[j - 1]) {
							++same_count;
						}
						else {
							i = j;
							break;
						}
					}
					if (same_count == 0) {
						two_adjacent = true;
						break;
					}
					same_count = 0;
				}
			}
		}
	}
	for (size_t i = 1; i < s.size(); ++i) {
		if ((int)s[i - 1] > (int)s[i]) {
			return false;
		}
	}
	if (!two_adjacent) {
		return false;
	}
	return true;
}

int main(){
	int count = 0;
	for (int i = 183564; i <= 657474; ++i) {
		if (isValidPass(to_string(i))) {
			++count;
			cout << "COUNT = " << count << "\n";
		}
	}
	return 0;
}