#include <iostream>
 
using namespace std;
 
int main(void) {
	ios_base::sync_with_stdio(false);
	double a, b, c, d, n, m;
	int k, t;
	cin >> t;
	while (t > 0) {
		cin >> a >> b >> c >> d >> k;
		n = a / c;
		m = b / d;
		int x = ceil(n);
		int y = ceil(m);
		if ((y + x) <= k) { cout << x << " " << y << "\n"; }
		else { cout << -1 << "\n"; }
		--t;
	}
	return 0;
}