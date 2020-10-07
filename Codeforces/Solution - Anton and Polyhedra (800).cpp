
﻿#include <iostream>
#include <string>
using namespace std;
 
int main(void) {
	ios_base::sync_with_stdio(false);
 
	int x = 0, result = 0;
	string s = "";
 
	cin >> x;
 
	while (x > 0) {
		cin >> s;
		switch (*(s.begin())) {
		case 'T': result += 4; goto label1;
		case 'C': result += 6; goto label1;
		case 'O': result += 8; goto label1;
		case 'D': result += 12; goto label1;
		case 'I': result += 20; goto label1;
		}
		label1:
		--x;
	}
 
	cout << result;
	return 0;
}