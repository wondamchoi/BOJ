//Puyo Puyo 11559번
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int, int> P;

char map[12][6];
int visit[12][6];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
vector<P> tmp, vt;
int cnt, ret;
bool flag;

void dfs(int x, int y, char ch) {

	for (int i = 0; i < 4; i++) {

		int xp = x + dx[i];
		int yp = y + dy[i];

		if (xp < 0 || yp < 0 || 12 <= xp || 6 <= yp) continue;
		if (visit[xp][yp] == 1) continue;
		if (map[xp][yp] == '.') continue;
		if (map[x][y] != map[xp][yp]) continue;

		visit[xp][yp] = 1;
		cnt++;
		tmp.push_back(P(xp, yp));
		dfs(xp, yp, map[xp][yp]);
	}
}

int main(void) {

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> map[i][j];
		}
	}	

	ret = -1;

	while (1) {

		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				visit[i][j] = 0;
			}
		}
		
		vt.clear();

		flag = false;
		ret++;

		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {

				if (map[i][j] != ',' && visit[i][j] == 0) {

					cnt = 1;
					tmp.push_back(P(i, j));
					visit[i][j] = 1;
					dfs(i, j, map[i][j]);

					if (4 <= cnt) {

						flag = true;
						for (int i = 0; i < tmp.size(); i++) {
							vt.push_back(P(tmp[i].first, tmp[i].second));
						}
					}

					tmp.clear();
				}
			}
		}

		for (int i = 0; i < vt.size(); i++) { //4개 이상 인접한 블록 터트리기
			map[vt[i].first][vt[i].second] = '.';
		}

		for (int i = 11; 0 <= i; i--) { //블록 내림
			for (int j = 5; 0 <= j; j--) {

				if (map[i][j] == '.') continue;
				if (i == 11) continue;

				int idx = i;

				while (1) {

					if (idx == 11 || map[idx + 1][j] != '.') break;
					
						map[idx + 1][j] = map[idx][j];
						map[idx][j] = '.';
						idx++;
				}
			}
		}

		if (!flag) break;
	}

	cout << ret;

	return 0;
}
