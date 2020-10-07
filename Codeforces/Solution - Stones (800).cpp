#include <iostream>
#include <vector>
 
using namespace std;
 
int take_stones(int& x, int& y) {
	int counter = 0;
	while (x >= 1 && y >= 2) {
		x -= 1;
		y -= 2;
		counter += 3;
	}
	return counter;
}
 
int main() {
	int T, a, b, c, aux1;
	vector<int>V;
	cin >> T;
	while (T > 0) {
		cin >> a >> b >> c;
		aux1 = take_stones(b, c);
		aux1 += take_stones(a, b);
		V.push_back(aux1);
		--T;
	}
	for (int i = 0; i < V.size(); ++i) {
		cout << V[i] << "\n";
	}
 
	return 0;
}