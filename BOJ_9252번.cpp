//LCS22 9252번
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define MAX_SIZE 1001

int dp[MAX_SIZE][MAX_SIZE];

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	string a, b;
	int len_a, len_b;

	cin >> a >> b;

	len_a = a.length();
	len_b = b.length();


	for (int i = 1; i <= len_b; i++) {
		for (int j = 1; j <= len_a; j++) {

			if (b[i-1] == a[j-1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	cout << dp[len_b][len_a] << '\n';

	string ret;


	for (int i = len_b; 1 <= i; i--) {
		for (int j = len_a; 1 <= j; j--) {

			if (dp[i][j] != max(dp[i - 1][j], dp[i][j - 1])) { //문자열 a의 j-1번째 인덱스의 값과 문자열 b의 i-1번째 인덱스의 값이 같다. -> 문자 추가 !
				ret += a[j-1];
				len_a = j - 1;
				break;
			}

			if (dp[i][j] == dp[i][j - 1] && dp[i][j] != dp[i - 1][j]) continue; //왼쪽으로 
			if (dp[i][j] != dp[i][j - 1] && dp[i][j] == dp[i - 1][j]) break; // 위로
		}
	}

	reverse(ret.begin(), ret.end());

	cout << ret;

	return 0;
}
