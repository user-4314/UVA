#include <iostream>
#include <cstdio>
#include<algorithm>
using namespace std;

char ma[1001][1001];
int up[1001][1001], le[1001][1001], ri[1001][1001];
int main() {

	int t;
	cin >> t;
	while (t--) {
        int m,n;
		cin >> m >> n;
		for (int i = 1; i <= m; i++){
            for (int j = 0; j < n; j++)
                cin >> ma[i][j];
        }

		for (int j = 0; j < n; j++) {
			up[0][j] = 0;
			le[0][j] = 0;
			ri[0][j] = n-1;
		}

		for (int i = 1; i <= m; i++) {
			int L = -1,R = n;
			for (int j = 0; j < n; j++) {
				if (ma[i][j] == 'F') {
					up[i][j] = up[i - 1][j] + 1;
					le[i][j] = max(L+1, le[i - 1][j]);
				}
				else {
					L = j;
					up[i][j] = 0;
					le[i][j] = 0;
					ri[i][j] = 0;
				}
			}
			for (int j = n-1; j >=0; j--) {
				if (ma[i][j] == 'F') {
					if (ma[i - 1][j] == 'R')
						ri[i][j] = R - 1;
					else
						ri[i][j] = min(R - 1, ri[i - 1][j]);
				}
				else
                    R = j;
			}
		}
		int ans = 0;
		for (int i = 1; i <= m; i++) {
			for (int j = 0; j < n; j++) {
				ans = max(ans, 3 * up[i][j] * (ri[i][j] - le[i][j] + 1));
			}
		}

		cout << ans << endl;
	}
}
