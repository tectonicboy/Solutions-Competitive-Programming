#include <iostream>
#include <algorithm>
using namespace std;
 
int main(void) {
	ios_base::sync_with_stdio(false);
	int n, m = 0, t, y, z = 0, r;
	char c;
	char M[1024];
	cin >> t;
	while (t > 0) {
		cin >> n; y = n;
		while (cin >> c) {
			M[n - y] = c;
			--y;
			if (y == 0) { break; }
		}
		if (n == 1) {
			if (M[0] == '1') { cout << 2 << "\n"; }
			else { cout << 1 << "\n"; }
		}
		else if (n % 2 == 0) {
			for (int i = (n / 2) - 1, j = (n / 2); i >= 0; ++j, --i) {
				++z;
				if (M[i] == '1' || M[j] == '1') { m = z; }
			}
			if (m > 0) {
				r = ((n / 2) + m) * 2;
			}
			else {
				r = n;
			}
			cout << r << "\n";
		}
		else if (n % 2 != 0){
			for (int i = ((n - 1) / 2) - 1, j = (n + 1) / 2; i >= 0; ++j, --i) {
				++z;
				if (M[i] == '1' || M[j] == '1') { m = z; }
			}
			if ((m > 0) || ( (m == 0) && (M[(n-1) / 2] == '1')) ) {
				r = (((n - 1) / 2) + m + 1) * 2;
			}
			else if (m == 0 && M[(n-1)/2]=='0') {
				r = n;
			}
			cout << r << "\n";
		}
		z = 0; m = 0;
		--t;
	}
	return 0;
}