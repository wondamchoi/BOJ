#include<iostream>
#include<deque>
using namespace std;
#define MAX_SIZE 101
typedef pair<int, int> P;
typedef pair<int, char> PP;

int map[MAX_SIZE][MAX_SIZE];
int visit[MAX_SIZE][MAX_SIZE];
PP info[MAX_SIZE];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0 ,0 };
deque<P> dq;

int turn_direction(int now_d, char d) {
	
	if (d == 'D') {
		if (now_d == 0) return 2;
		else if (now_d == 1) return 3;
		else if (now_d == 2) return 1;
		return 0;
	}

	else {
		if (now_d == 0) return 3;
		else if (now_d == 1) return 2;
		else if (now_d == 2) return 0;
		else return 1;
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k, l, row, col;
	int x, y, dir, seconds, idx;// 0(동), 1(서), 2(남), 3(북)

	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> row >> col;

		map[row][col] = 1;
	}

	cin >> l;
	for (int i = 0; i < l; i++) {
		cin >> info[i].first >> info[i].second;
	}

	x = y = 1;
	dir = seconds = idx = 0;

	dq.push_back(P(x, y));

	while (1) {
		
		int xp, yp;
		
		if (idx <= l - 1) {
			if (seconds == info[idx].first) {

				dir = turn_direction(dir, info[idx].second);
				idx++;
			}
		}

		xp = x + dx[dir];
		yp = y + dy[dir];
		seconds++;

		if (xp < 1 || yp < 1 || n < xp || n < yp
			|| visit[xp][yp] == 1) {
			cout << seconds;
			break;
		}

		visit[xp][yp] = 1;
		dq.push_back(P(xp, yp));
		
		if (map[xp][yp] != 1) { //사과가 없는경우

			visit[dq.front().first][dq.front().second] = 0;
			dq.pop_front();
		}

		else { //사과가 있는 경우
			map[xp][yp] = 0;
		}

		x = xp;
		y = yp;
	}

	return 0;
}
