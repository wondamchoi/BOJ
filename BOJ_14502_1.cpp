#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define MAX_SIZE 8
typedef pair<int, int> P;
vector<P> zero;//빈 공간
vector<P> virus;//바이러스
queue<P> q;

int N, M, MAX, cnt;
int map[MAX_SIZE][MAX_SIZE];
int tmp[MAX_SIZE][MAX_SIZE];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0 , 0, -1 , 1 };


void BFS() {

	int xp, yp, size;

	while (!q.empty()) {

		size = q.size();

		for (int i = 0; i < size; i++) {

			xp = q.front().first;
			yp = q.front().second;
			q.pop();

			for (int j = 0; j < 4; j++) {

				int xp2 = xp + dx[j];
				int yp2 = yp + dy[j];

				if (xp2 < 0 || yp2 < 0 || N <= xp2 || M <= yp2) continue;
				if (tmp[xp2][yp2] == 1 || tmp[xp2][yp2] == 2) continue;

				tmp[xp2][yp2] = 2;
				q.push(P(xp2, yp2));

			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin >> N >> M;

	MAX = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];

			if (map[i][j] == 0) {
				zero.push_back(P(i, j));
			}

			if (map[i][j] == 2) {
				virus.push_back(P(i, j));
			}
		}
	}

	int size = zero.size();

	for (int k = 0; k < size - 2; k++) {
		for (int i = k+1; i <size - 1; i++) {
			for (int j = i+1; j < size; j++) {

				for (int l = 0; l < N; l++) {
					for (int m = 0; m < M; m++) {
						tmp[l][m] = map[l][m];
					}
				}
				
				tmp[zero[k].first][zero[k].second] = 1;
				tmp[zero[i].first][zero[i].second] = 1;
				tmp[zero[j].first][zero[j].second] = 1;

				for (int l = 0; l < virus.size(); l++) {
					q.push(P(virus[l].first, virus[l].second));
				}
				
				cnt = 0;
				BFS();
				for (int l = 0; l < N; l++) {
					for (int m = 0; m < M; m++) {
						if (tmp[l][m] == 0) {
							cnt++;
						}
					}
				}

				MAX = max(MAX, cnt);
			}
		}
	}

	cout << MAX;
	
	return 0;
}
