//불 5427번
#include<iostream>
#include<queue>
using namespace std;
#define MAX_SIZE 1000
typedef pair<int, int> P;

char map[MAX_SIZE][MAX_SIZE];
int visit_fire[MAX_SIZE][MAX_SIZE];
int visit_sangn[MAX_SIZE][MAX_SIZE];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int T, w, h, ret, flag;
queue<P> fire, sangn;

void BFS_Fire() {

	int size;

	while (!fire.empty()) {

		size = fire.size();
		for (int i = 0; i < size; i++) {

			int xp = fire.front().first;
			int yp = fire.front().second;
			fire.pop();

			for (int j = 0; j < 4; j++) {

				int xp2 = xp + dx[j];
				int yp2 = yp + dy[j];

				if (xp2 < 0 || yp2 < 0 || h <= xp2 || w <= yp2) continue;
				if (visit_fire[xp2][yp2] != 0) continue;
				if (map[xp2][yp2] == '#') continue;

				visit_fire[xp2][yp2] = visit_fire[xp][yp] + 1;
				fire.push(P(xp2, yp2));
			}
		}
	}
}

void BFS_Sangn() {

	int size;

	while (!sangn.empty()) {

		size = sangn.size();
		ret++;

		for (int i = 0; i < size; i++) {

			int xp = sangn.front().first;
			int yp = sangn.front().second;
			sangn.pop();

			if (xp == 0 || xp == h - 1 || yp == 0 || yp == w - 1) {
				flag = true;
				return;
			}

			for (int j = 0; j < 4; j++) {

				int xp2 = xp + dx[j];
				int yp2 = yp + dy[j];

				if (xp2 < 0 | yp2 < 0 || h <= xp2 || w <= yp2) continue;
				if (map[xp2][yp2] == '#') continue;
				if (visit_sangn[xp2][yp2] != 0) continue;
				if (visit_fire[xp2][yp2] != 0 && visit_fire[xp2][yp2] <= visit_sangn[xp][yp] + 1) continue;

				visit_sangn[xp2][yp2] = visit_sangn[xp][yp] + 1;
				sangn.push(P(xp2, yp2));
			}
		}
}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {

		cin >> w >> h;

		while (!sangn.empty()) sangn.pop();
		while (!fire.empty()) fire.pop();

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				visit_fire[i][j] = 0;
				visit_sangn[i][j] = 0;
			}
		}

		flag = false;
		ret = 0;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];

				if (map[i][j] == '*') {
					fire.push(P(i, j));
					visit_fire[i][j] = 1;
				}

				if (map[i][j] == '@') {
					sangn.push(P(i, j));
					visit_sangn[i][j] = 1;
				}
			}
		}

		BFS_Fire();
		BFS_Sangn();

		if (flag) cout << ret << '\n';
		else cout << "IMPOSSIBLE\n";

	}

	return 0;
}
