//소셜 네트워크 3098번
#include<iostream>
#include<vector>
using namespace std;
#define MAX_SIZE 51

int link[MAX_SIZE][MAX_SIZE];
int Size[MAX_SIZE];
vector<int> f[MAX_SIZE];
vector<int> vt;
int n, m, a, b;

bool can_allfriend() { //모든 친구가 친구가 됫는지 확인함

	for (int i = 1; i <= n; i++) {

		for (int j = 1; j <= n; j++) {

			if (i == j) continue;
			if (link[i][j] == 0) return false;
		}
	}

	return true;
}

void init_size() {

	for (int i = 1; i <= n; i++) {
		Size[i] = f[i].size();
	}
}

int main(void) {

	cin >> n >> m;
	for (int i = 0; i < m; i++) {

		cin >> a >> b;

		link[a][b] = 1;
		link[b][a] = 1;
		f[a].push_back(b);
		f[b].push_back(a);
	}

	while (1) {

		init_size();
		int cnt = 0;

		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < Size[i]; j++) {
				for (int k = 0; k < Size[f[i][j]]; k++) {

					if (i == f[f[i][j]][k]) continue;

					if (link[i][f[f[i][j]][k]] == 1 ||
						link[f[f[i][j]][k]][i] == 1) continue;

					link[i][f[f[i][j]][k]] = 1;
					link[f[f[i][j]][k]][i] = 1;
					f[i].push_back(f[f[i][j]][k]);
					f[f[f[i][j]][k]].push_back(i);
					cnt++;
				}
			}
		}

		vt.push_back(cnt);
		if (can_allfriend()) break;
	}

	cout << vt.size() << '\n';
	for (int i = 0; i < vt.size(); i++) cout << vt[i] << '\n';

	return 0;
}
