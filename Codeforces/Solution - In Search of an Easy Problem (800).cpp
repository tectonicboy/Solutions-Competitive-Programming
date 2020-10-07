#include <iostream>
using namespace std;
 
int main(void) {
	ios_base::sync_with_stdio(false);
	bool hard = false;
	int a, b;
	cin >> a;
	while (cin >> b) {
		if (b == 1) { cout << "HARD"; return 0; }
		--a;
		if (a == 0) { break; }
	}
	cout << "EASY";
	return 0;
}