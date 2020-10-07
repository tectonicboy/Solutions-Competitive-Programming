#include <iostream>
#include <math.h>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
 
int main(void) {
	ios_base::sync_with_stdio(false);
	int a, b, c, x, y, z;
	vector<int>V;
	cin >> a >> b >> c;
	V.push_back(a); V.push_back(b); V.push_back(c);
	sort(V.begin(), V.end());
	x = *V.begin(); y = *(V.begin() + 1); z = *(V.begin() + 2);
	int result = z - (x + y) + 1;
	if (result < 0) { result = 0; }
	cout << result;
	return 0;
}