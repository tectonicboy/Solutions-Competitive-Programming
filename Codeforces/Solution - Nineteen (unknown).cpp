#include <iostream>
#include <iterator>
#include <string>
 
using namespace std;
 
int CountNineteen(string& s) {
	int n = 0, i = 0, e = 0, t = 0, count = 0;
	for (string::const_iterator i1 = s.cbegin(); i1 < s.cend(); ++i1) {
 
		if (*i1 == 'n') { ++n; }
		else if (*i1 == 'i') { ++i; }
		else if (*i1 == 'e') { ++e; }
		else if (*i1 == 't') { ++t; }
	}
 
	while ((n >= 3) && (i > 0) && (e >= 3) && (t > 0)) {
		++count;
		n -= 2; --i; e -= 3; --t;
	}
	return count;
}
 
int main() {
	string S;
	cin >> S;
	
	cout << CountNineteen(S);
 
 
	return 0;
}