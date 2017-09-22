//로봇 청소기 14503번
#include<iostream>
using namespace std;
#define MAX_SIZE 50

int turn_direction(int d) { //왼쪽으로 한번 회전

	if (d == 0) return 3;
	else if (d == 1) return 0;
	else if (d == 2) return 1;
	else return 2;
}

int map[MAX_SIZE][MAX_SIZE];
int visit[MAX_SIZE][MAX_SIZE];
int n, m, x, y, d, ret;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void dfs(int x, int y, int d) {

	bool flag = false;

	for (int i = 0; i < 4; i++) {

		d = turn_direction(d);

		int xp = x + dx[d];
		int yp = y + dy[d];

		if (map[xp][yp] == 1) continue;
		if (visit[xp][yp] == 1) continue;

		flag = true;
		ret++;
		visit[xp][yp] = 1;
		dfs(xp, yp, d);
	}

	if (!flag) { //3번 조건

		int xp, yp;

		xp = x;
		yp = y;

		if (d == 0) xp += 1;
		else if (d == 1) yp -= 1;
		else if (d == 2) xp -= 1;
		else yp += 1;
		
		if (map[xp][yp] == 1) {
			cout << ret << '\n';
			exit(0);
		}

		else {
			
			if (visit[xp][yp] == 0) {
				ret++;
				visit[xp][yp] = 1;
			}

			dfs(xp, yp, d);
		}
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	cin >> x >> y >> d;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	ret = 1;
	visit[x][y] = 1;
	dfs(x, y, d);

	return 0;
}
