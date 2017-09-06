#include<iostream>
#include<string>
using namespace std;
#define MAX_SIZE 1001

int alpha[26];
char output[MAX_SIZE];
int len;
string s;

void dfs(int idx, int d) {

	if (d == len) {
		cout << output << '\n';
		return;
	}

	for (int i = 0; i < 26; i++) {

		if (0 < alpha[i]) {

			alpha[i]--;
			output[d] = 'a' + i;
			dfs(i, d + 1);
			alpha[i]++;
		}
	}
}


int main(void) {

    ios::sync_with_stdio(false);
	cin.tie(0);

	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < 26; j++) alpha[j] = 0;

		cin >> s;
		
		len = s.length();
		for (int j = 0; j <len; j++) {
			alpha[s[j] - 'a']++;
		}

		dfs(0, 0);
	}

	return 0;
}
