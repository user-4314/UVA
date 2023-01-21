#include <cstdio>
#include <cstring>
using namespace std;
const int N = 80;
const int INF = 0x3f3f3f3f;
int grid[N*2][N*2];
int tot[N*2][N*2];
int res[N*2];
int n;

int maxSub(int start) {
	int maxn,dp;
	maxn = dp = res[start];
	for(int i = start+1; i < start + n; i++) {
		if(dp > 0) {
			dp += res[i];
		}else {
			dp = res[i];
		}
		if(maxn < dp) {
			maxn = dp;
		}
	}
	return maxn;
}

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		memset(grid,0,sizeof(grid));
		scanf("%d",&n);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				scanf("%d",&grid[i][j]);
				grid[n+i][j] = grid[i][n+j] = grid[n+i][n+j] = grid[i][j];
			}
		}
		int len = 2*n;
		memset(tot,0,sizeof(tot));
		for(int i = 0; i < len; i++) {
			for(int j = 0; j < len; j++) {
				if(i == 0) {
					tot[i][j] = grid[i][j];
				}else {
					tot[i][j] = tot[i-1][j] + grid[i][j];
				}
			}
		}
		int ma = -INF;
		for(int i = 0; i < len; i++) {
			for(int j = i; j < i + n && j < len; j++) {
				for(int k = 0; k < len; k++) {
					if(i == 0) {
						res[k] = tot[j][k];
					}else {
						res[k] = tot[j][k] - tot[i-1][k];
					}
				}
				for(int k = 0; k < n; k++) {
					int ans = maxSub(k);
					if(ma < ans) {
						ma = ans;
					}
				}
			}
		}
		printf("%d\n",ma);
	}
	return 0;
}
