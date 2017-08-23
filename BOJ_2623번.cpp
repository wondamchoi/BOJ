//음악프로그램 2623번
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define MAX_SIZE 1001

vector<int> vt[MAX_SIZE];
int in[MAX_SIZE];
queue<int> q;
vector<int> ret;
int n, m;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	int cnt, a, b;

	for (int i = 0; i < m; i++) {

		cin >> cnt;
		for (int j = 0; j < cnt; j++) {

			if (j == 0) cin >> a;
			else {

				cin >> b;
				vt[a].push_back(b);
				in[b]++;
				a = b;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (in[i] == 0) q.push(i);
	}

	while (!q.empty()) {

		int now = q.front();
		ret.push_back(now);
		q.pop();

		for (int i = 0; i < vt[now].size(); i++) {

			int next_v = vt[now][i];

			in[next_v]--;
			if (in[next_v] == 0) q.push(next_v);
		}
	}

	if (n == ret.size()) {
		for (int i = 0; i < ret.size(); i++) {
			cout << ret[i] << '\n';
		}
	}

	else cout << 0;
	
	return 0;
}
