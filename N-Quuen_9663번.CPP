
//n queen 9663번
//1행에 1개의 말을 놓는다.

#include<iostream>
using namespace std;
#define MAX_SIZE 15

int map[MAX_SIZE][MAX_SIZE];
int visit[MAX_SIZE][MAX_SIZE];

int n, ret;

bool check(int x, int y) {

	//세로 검사
	for (int i = 0; i < x; i++) { 
		if (visit[i][y] == 1) return false;
	}
	//대각선 검사
	int tmp_x, tmp_y;
	
	tmp_x = x;
	tmp_y = y;
	//우상
	while (0 <= tmp_x && tmp_y < n) {

		if (visit[tmp_x][tmp_y] == 1) return false;
		tmp_x--;
		tmp_y++;
	}

	//좌상
	tmp_x = x;
	tmp_y = y;
	while (0 <= tmp_x && 0 <= tmp_y) {

		if (visit[tmp_x][tmp_y] == 1) return false;
		tmp_x--;
		tmp_y--;
	}

	return true;
}

void dfs(int x, int y, int d) {

	if (visit[x][y] == 1) return;
	if (d == n - 1) {
		ret++;
		return;
	}

	visit[x][y] = 1;

	for (int i = 0; i < n; i++) {

		if (check(x + 1, i)) {
			dfs(x + 1, i, d + 1);
			visit[x + 1][i] = 0;
		}
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin >> n;

	ret = 0;

		for (int i = 0; i < n; i++) {

			dfs(0, i, 0);
			visit[0][i] = 0;
		}

		cout << ret;

	return 0;
}
