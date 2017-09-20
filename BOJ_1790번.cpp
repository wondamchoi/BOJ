//비숍 1790번
#include<iostream>
#include<algorithm>
using namespace std;
#define MAX_SIZE 10

int map[MAX_SIZE][MAX_SIZE];
int visit[MAX_SIZE][MAX_SIZE];
int n, MAX;

bool check(int x, int y) {

	while (0 <= x && 0 <= y) {

		if (visit[x][y] == 1) return false;
		x--;
		y--;
	}
	return true;
}

void dfs(int d, int cnt) {

	if (d == 2 * n - 1) return;
	
	int x, y;
	bool flag;

	if (d < n - 1) {
		x = d;
		y = 0;
	}

	else {
		x = n - 1;
		y = d - n + 1;
	}
	
	flag = false;

	while (0 <= x && y < n) {

		if (map[x][y] == 1 && check(x, y)) {

			flag = true;
			visit[x][y] = 1;
			MAX = max(MAX, cnt + 1);
			dfs(d + 1, cnt + 1);
			visit[x][y] = 0;
		}

		x--;
		y++;
	}

	if (!flag) dfs(d + 1, cnt);
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	MAX = 0;
	
	dfs(0, 0);

	cout << MAX;

	return 0;
}
