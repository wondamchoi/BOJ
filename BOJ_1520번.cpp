//내리막 길 1520번

#include<iostream>
using namespace std;
#define MAX_SIZE 500

int map[MAX_SIZE][MAX_SIZE];
int dp[MAX_SIZE][MAX_SIZE];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int m, n;

int dfs(int x, int y) {
	
	if (dp[x][y] != -1) return dp[x][y];

	int ret = 0;

	for (int i = 0; i < 4; i++) {

		int xp = x + dx[i];
		int yp = y + dy[i];

		if (xp < 0 || yp < 0 || m <= xp || n <= yp) continue;
		if (map[x][y] <= map[xp][yp]) continue;

		ret += dfs(xp, yp);
	}

	dp[x][y] = ret;
	return dp[x][y];
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			dp[i][j] = -1;
		}
	} 

	dp[m - 1][n - 1] = 1;

	cout << dfs(0, 0);

	return 0;
}

