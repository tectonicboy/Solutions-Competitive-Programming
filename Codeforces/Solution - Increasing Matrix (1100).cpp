#include <iostream>
#include <algorithm>
 
using namespace std;
 
int main(void) {
	ios_base::sync_with_stdio(false);
	int M[512][512];
	int n, m, a = 0, x, r = 0, c = 0;
	cin >> n >> m;
	while (r < n) {
		while (cin >> x) {
			M[r][c] = x;
			++c;
			if (c >= m) { break; }
		}
		c = 0;
		++r;
	}
	for (int i = n-2; i >= 1; --i) {
		for (int j = m-2; j >= 1; --j) {
			if (M[i][j] == 0) { M[i][j] = min(M[i][j + 1], M[i + 1][j]) - 1; }
		} 
	}
	for (int i = n - 1; i >= 0; --i) {
		for (int j = m - 1; j >= 0; --j) {
			if (((i == 0) || (i == (n - 1))) && (j > 0)) { if (M[i][j] <= M[i][j - 1]) { cout << -1; return 0; } }
			else if (((j == 0) || (j == (m - 1))) && (i > 0)) {  if (M[i][j] <= M[i - 1][j]) { cout << -1; return 0; } }
			else if (i > 0 && j > 0 && i < n - 1 && j < m - 1) {
				if ((M[i][j] >= min(M[i][j+1], M[i+1][j])) || (M[i][j] <= max(M[i][j-1], M[i-1][j]))) { cout << -1; return 0; } 
			}
			a += M[i][j];
		}
	}
	if ((M[0][0] >= min(M[0][1], M[1][0])) 
		|| ((M[n - 1][0] <= M[n - 2][0]) || (M[n - 1][0] >= M[n - 1][1])) 
		|| (M[n - 1][m - 1] <= max(M[n - 1][m - 2], M[n - 2][m - 1])) 
		|| ((M[0][m - 1] <= M[0][m - 2]) || (M[0][m - 1] >= M[1][m - 1]))) 
	{ cout << -1; return 0; }
	cout << a;
	return 0;
}