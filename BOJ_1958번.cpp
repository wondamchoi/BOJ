#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define MAX_SIZE 101

int dp[MAX_SIZE][MAX_SIZE][MAX_SIZE];

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	string a, b, c;
	int len_a, len_b, len_c;

	cin >> a >> b >> c;

	len_a = a.length();
	len_b = b.length();
	len_c = c.length();

	for (int i = 1; i <= len_a; i++) {
		for (int j = 1; j <= len_b; j++) {
			for (int k = 1; k <= len_c; k++) {

				if ((a[i - 1] == b[j - 1]) && (a[i-1] == c[k-1])) dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				else {
					dp[i][j][k] = max({ dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1] });
				}
			}
		}
	}

	cout << dp[len_a][len_b][len_c];

	return 0;
}


