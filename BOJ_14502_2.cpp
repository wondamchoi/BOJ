#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
#define MAX_SIZE 500
typedef pair<int, int> P;

int map[MAX_SIZE][MAX_SIZE];
int tmp[MAX_SIZE][MAX_SIZE];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
vector<P> zero;
vector<P> virus;

queue<P> q;
int n, m, cnt, MAX;

void BFS() {

	int size; 

	while (!q.empty()) {

		size = q.size();
		for (int i = 0; i < size; i++) {

			int xp = q.front().first;
			int yp = q.front().second;
			q.pop();

			for (int j = 0; j < 4; j++) {

				int xp2 = xp + dx[j];
				int yp2 = yp + dy[j];

				if (xp2 < 0 || yp2 < 0 || n <= xp2 || m <= yp2) continue;
				if (map[xp2][yp2] == 1 || map[xp2][yp2] == 2) continue;

				map[xp2][yp2] = 2;
				q.push(P(xp2, yp2));
			}
		}
	}
}

int get_area() {

	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) ret++;
		}
	}

	return ret;
}

void dfs(int idx, int d) {

	if (d == 3) {

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				tmp[i][j] = map[i][j];
			}
		}

		for (int i = 0; i < virus.size(); i++) {
			q.push(P(virus[i].first, virus[i].second));
		}

		BFS();
		cnt = get_area();

		MAX = max(MAX, cnt);
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				map[i][j] = tmp[i][j];
			}
		}
		
		return;
	}

	for (int i = idx + 1; i < zero.size(); i++) {
		
		int x = zero[i].first;
		int y = zero[i].second;

		map[x][y] = 1;
		dfs(i, d + 1);
		map[x][y] = 0;
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);
		
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];

			if (map[i][j] == 0) zero.push_back(P(i, j));
			if (map[i][j] == 2) virus.push_back(P(i, j));	
		}
	}

	MAX = 0;

	for (int i = 0; i < zero.size(); i++) {

		int x = zero[i].first;
		int y = zero[i].second;

		map[x][y] = 1;
		dfs(i, 1);
		map[x][y] = 0;
	}

	cout << MAX;

	return 0;
}

