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

int main(){
	string s1 = "", s2 = "", number = "";
	cin >> s1 >> s2;
	vector<string> vec1 = SeparateStrings(s1), vec2 = SeparateStrings(s2);
	pair<int, int> P1 = { 0, 0 }, P2 = { 0, 0 };
	vector<pair<int, int>> points1 = {}, points2 = {};
	bool b1 = false, b2 = false;
	int low_moves = 0, d = 0, moves1 = 0, moves2 = 0, lowest_distance = 1999999999, intersections = 0;
	for (size_t i = 0; i < vec1.size(); ++i) {
		cout << "i = " << i << "\t | \tIntersections Found: " << intersections << ". \t | \t Lowest = " << lowest_distance << "\n";
		for (size_t j = 1; j < vec1[i].size(); ++j) { number.push_back(vec1[i][j]); }
		moves1 = stoi(number);
		number = "";
		for (size_t j = 1; j < vec2[i].size(); ++j) { number.push_back(vec2[i][j]); }
		moves2 = stoi(number);
		number = "";
		if (moves1 == moves2) { low_moves = moves1; }
		else if (moves1 < moves2) { low_moves = moves1; b1 = true; }
		else { low_moves = moves2; b2 = true; }
		while (low_moves > 0) {
			switch (vec1[i][0]) {
			case 'U':
				++get<1>(P1);
				break;

			case 'D':
				--get<1>(P1);
				break;

			case 'R':
				++get<0>(P1);
				break;
			case 'L':
				--get<0>(P1);
				break;
			default:
				break;
			}
			points1.push_back(P1);
			for (size_t x = 0; x < points2.size(); ++x) {
				if (P1 == points2[x]) {
					cout << "Intersection found with P1! " << P1.first << ", " << P1.second << " AND " << points2[x].first << ", " << points2[x].second << ". Distance = ";
					++intersections;
					d = abs(get<0>(P1)) + abs(get<1>(P1));
					cout << d << "\n";
					if (d < lowest_distance) {
						lowest_distance = d;
					}
				}
			}
			switch (vec2[i][0]) {
			case 'U':
				++get<1>(P2);
				break;

			case 'D':
				--get<1>(P2);
				break;

			case 'R':
				++get<0>(P2);
				break;
			case 'L':
				--get<0>(P2);
				break;
			default:
				break;
			}
			points2.push_back(P2);
			for (size_t x = 0; x < points1.size(); ++x) {
				if (P2 == points1[x]) {
					cout << "Intersection found with P2! " << P2.first << ", " << P2.second << " AND " << points1[x].first << ", " << points1[x].second << ". Distance = ";
					++intersections;
					d = abs(get<0>(P2)) + abs(get<1>(P2));
					cout << d << "\n";
					if (d < lowest_distance) {
						lowest_distance = d;
					}
				}
			}
			--low_moves;
		}
		if (b1) {
			cout << "at i = " << i << ", vec2 will be moving more!\n";
			moves2 -= moves1;
			while (moves2 > 0) {
				switch (vec2[i][0]) {
				case 'U':
					++get<1>(P2);
					break;

				case 'D':
					--get<1>(P2);
					break;

				case 'R':
					++get<0>(P2);
					break;
				case 'L':
					--get<0>(P2);
					break;
				default:
					break;
				}
				points2.push_back(P2);
				for (size_t x = 0; x < points1.size(); ++x) {
					if (P2 == points1[x]) {
						cout << "Intersection found with P2! " << P2.first << ", " << P2.second << " AND " << points1[x].first << ", " << points1[x].second << ". Distance = ";
						++intersections;
						d = abs(get<0>(P2)) + abs(get<1>(P2));
						cout << d << "\n";
						if (d < lowest_distance) {
							lowest_distance = d;
						}
					}
				}

				--moves2;
			}
			b1 = false;
		}
		else if (b2) {
			cout << "at i = " << i << ", vec1 will be moving more!\n";
			moves1 -= moves2;
			while (moves1 > 0) {
				switch (vec1[i][0]) {
				case 'U':
					++get<1>(P1);
					break;

				case 'D':
					--get<1>(P1);
					break;

				case 'R':
					++get<0>(P1);
					break;
				case 'L':
					--get<0>(P1);
					break;
				default:
					break;
				}
				points1.push_back(P1);
				for (size_t x = 0; x < points2.size(); ++x) {
					if (P1 == points2[x]) {
						cout << "Intersection found with P1!" << P1.first << ", " << P1.second << " AND " << points2[x].first << ", " << points2[x].second << ". Distance = ";
						++intersections;
						d = abs(get<0>(P1)) + abs(get<1>(P1));
						cout << d << "\n";
						if (d < lowest_distance) {
							lowest_distance = d;
						}
					}
				}
				--moves1;
			}
			b2 = false;
		}
		cout << "FINISHED i = " << i << ". P1 = " << get<0>(P1) << ", " << get<1>(P1) << ") and P2 = " << get<0>(P2) << ", " << get<1>(P2) << "\n";
	}
	cout << lowest_distance << "\n";
	return 0;
}