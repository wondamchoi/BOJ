//합분해 2225번

#include<iostream>
using namespace std;
#define MAX_SIZE 201
#define MOD 1000000000
typedef long long int ll;

ll dp[MAX_SIZE][MAX_SIZE];// i개의 수를 더해서 합이 j가 되는 경우의 수
int n, k;

int dfs(int d, int sum) {

	if (n < sum) return 0; //배열 범위가 넘어감

	if (d == k) {
		if (sum == n) return 1;
		else return 0;
	}

	if (dp[d][sum] != 0) return dp[d][sum];

	for (int i = 0; i <= n; i++) {

		dp[d][sum] = (dp[d][sum] + dfs(d + 1, sum + i)) % MOD;
	}

	return dp[d][sum];
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;

	cout << dfs(0, 0);

	return 0;
}


