#include <iostream>
#include <string>
 
using namespace std;
 
int main(void) {
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	int m = (int)(*(s.begin()));
	char r;
 
	if ((97 <= m) && (m <= 122)) {
		m -= 32;
		r = (char)m;
		*s.begin() = r;
	}
	cout << s;
	return 0;
}