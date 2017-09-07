//탈출 3055번 
#include<iostream>
#include<queue>
using namespace std;
#define MAX_SIZE 50
typedef pair<int, int> P;

char map[MAX_SIZE][MAX_SIZE];
int visit_water[MAX_SIZE][MAX_SIZE];
int visit_viva[MAX_SIZE][MAX_SIZE];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
queue<P> water, viva;
int R, C, ret;
bool flag;

void BFS_Water() {

	int size;

	while (!water.empty()) {

		size = water.size();

		for (int i = 0; i < size; i++) {

			int xp = water.front().first;
			int yp = water.front().second;
			water.pop();

			for (int j = 0; j < 4; j++) {

				int xp2 = xp + dx[j];
				int yp2 = yp + dy[j];

				if (xp2 < 0 || yp2 < 0 || R <= xp2 || C <= yp2) continue;
				if (visit_water[xp2][yp2] != 0) continue;
				if (map[xp2][yp2] == 'X' || map[xp2][yp2] == 'D') continue;

				visit_water[xp2][yp2] = visit_water[xp][yp] + 1;
				water.push(P(xp2, yp2));
			}
		}
	}
}

void BFS_Viva() {

	int size;

	while (!viva.empty()) {

		size = viva.size();
		ret++;

		for (int i = 0; i < size; i++) {

			int xp = viva.front().first;
			int yp = viva.front().second;
			viva.pop();

			for (int j = 0; j < 4; j++) {

				int xp2 = xp + dx[j];
				int yp2 = yp + dy[j];

				if (map[xp2][yp2] == 'D') {
					flag = true;
					return;
				}

				if (xp2 < 0 || yp2 < 0 || R <= xp2 || C <= yp2) continue;
				if (visit_viva[xp2][yp2] != 0) continue;
				if (map[xp2][yp2] == 'X' || map[xp2][yp2] == '*') continue;
				if (visit_water[xp2][yp2] != 0 && visit_water[xp2][yp2] <= visit_viva[xp][yp] + 1) continue;				

				visit_viva[xp2][yp2] = visit_viva[xp][yp] + 1;
				viva.push(P(xp2, yp2));
			}
		}
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];

			if (map[i][j] == '*') {
				visit_water[i][j] = 1;
				water.push(P(i, j));
			}
		
			if (map[i][j] == 'S') {
				visit_viva[i][j] = 1;
				viva.push(P(i, j));
			}
		}
	}
	
	ret = 0;
	flag = false;

	BFS_Water();
	BFS_Viva();

	if (flag) cout << ret;
	else cout << "KAKTUS";
	
	return 0;
}
