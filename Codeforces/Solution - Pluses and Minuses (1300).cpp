#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <iterator>

typedef long long NUMERIC_TYPE_U;

using namespace std;

NUMERIC_TYPE_U Sum(NUMERIC_TYPE_U n) {
	NUMERIC_TYPE_U res = n;
	while (n > 0) {
		res += n;
		--n;
	}
	return res;
}

int main() {
	NUMERIC_TYPE_U tests = 0, result = 0, leftover_pluses = 0, m_counter = 0, p_counter = 0, m = 0, n = 0, a = 0, aux1 = 0, aux2 = 0, aux3 = 0, aux4 = 0, aux5 = 0, count = 0, aux6 = 0;
	NUMERIC_TYPE_U b = 0;
	bool bool1 = false;
	pair<NUMERIC_TYPE_U, NUMERIC_TYPE_U>p = { 0, 0 };
	vector<NUMERIC_TYPE_U> Results = {};
	vector<pair<NUMERIC_TYPE_U, NUMERIC_TYPE_U>> vec = {};
	char c = '0';
	string s = "";
	cin >> tests;
	while (tests > 0) {
		cin >> s;
		//Populating the vector of pair<int, int>.
		for (size_t i = 0; i < s.size(); ++i) {
			//cout << "i = " << i << ", bool1 = " << bool1 << ", sign = " << s[i] << "\n";
			if (!bool1) {
				if (s[i] == '+') {
					if (i < s.size() - 1) { ++p_counter; }
					//Reached the end of the string
					else {
						++p_counter;
						vec.push_back({ p_counter, m_counter });
						p_counter = 0; m_counter = 0;
						bool1 = false;
						break;
					}
				}
				else {
					bool1 = true;
					if (i < s.size() - 1) { ++m_counter; }
					//Reached the end of the string
					else {
						++m_counter;
						vec.push_back({ p_counter, m_counter });
						p_counter = 0; m_counter = 0;
						bool1 = false;
						break;
					}
				}
			}
			else {
				if (s[i] == '-' && i < s.size() - 1) { ++m_counter; }
				//Reached the end of the string
				else if (s[i] == '-' && i == s.size() - 1) {
					++m_counter;
					vec.push_back({ p_counter, m_counter });
					p_counter = 0; m_counter = 0;
					bool1 = false;
					break;
				}
				else {
					vec.push_back({ p_counter, m_counter });
					p_counter = 0; m_counter = 0;
					bool1 = false;
					--i;
				}
			}
		}

		for (size_t i = 0; i < vec.size(); ++i) {
			//cout << "Plus: " << vec[i].first << "\tMinus: " << vec[i].second << "\n";
		}

		//The Algorithm
		for (size_t i = 0; i < vec.size(); ++i) {
			//cout << "algorithm i = " << i << ", vec.size() = " << vec.size() << "\n";
			//vec[i].first += (leftover_pluses);
			m = vec[i].first;
			n = vec[i].second;
			a = 2 * m;
			b = n - (m + leftover_pluses);
			if (b < 0) {
				leftover_pluses = abs(b);
				result += (m + n);
			//	cout << "result += (" << aux6 + n << ") => " << result << "\n";
			}
			else {
				aux1 = Sum(b);
				//cout << "sum(b) = " << aux1 << "\n";
				aux2 = a + count + leftover_pluses;
				aux3 = aux2 * b;
				aux4 = aux3 + (a + leftover_pluses);
				aux5 = aux4 + aux1;
				result += aux5;
				leftover_pluses = 0;
				//cout << "aux5 = " << aux5 << ", result = " << result << " count = ";
			}
			count += (m + n);
			//cout << count << "\n";
			//cout << "count is now: " << count << "\n";
		}

		Results.push_back(result);

		--tests;
		vec = {};
		leftover_pluses = 0;
		result = 0;
		count = 0;

	}
	for (size_t i = 0; i < Results.size(); ++i) {
		cout << Results[i] << "\n";
	}

	return 0;
}