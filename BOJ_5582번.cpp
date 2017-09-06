#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define MAX_SIZE 4001

int dp[MAX_SIZE][MAX_SIZE];

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	string a, b;

	cin >> a >> b;

	for (int i = 1; i <= a.length(); i++) {
		for (int j = 1; j <= b.length(); j++) {

			if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
		}
	}
	 
	int MAX = 0;
	for (int i = 1; i <= a.length(); i++) {
		for (int j = 1; j <= b.length(); j++) {

			MAX = max(MAX, dp[i][j]);
		}
	}

	cout << MAX;

	return 0;
}
