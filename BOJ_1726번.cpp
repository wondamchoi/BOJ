//로봇 1726번
#include<iostream>
#include<queue>
using namespace std;
#define MAX_SIZE 101

class Point {

public :

	int x;
	int y;
	int direct;

public:

	Point(int a, int b, int c) {
		x = a;
		y = b;
		direct = c;
	}
};

int map[MAX_SIZE][MAX_SIZE];
int visit[MAX_SIZE][MAX_SIZE][4];
int m, n, st_x, st_y, st_d, en_x, en_y, en_d, ret;//방향 : 동쪽 1, 서쪽 2, 남쪽 3, 북쪽 4
queue<Point> q;

int turn_left(int d) {

	if (d == 1) return 4;
	else if (d == 2) return 3;
	else if(d == 3) return 1;
	else return 2;
}

int turn_right(int d) {

	if (d == 1) return 3;
	else if (d == 2) return 4;
	else if (d == 3) return 2;
	else return 1;

}

void BFS() {

	int size;

	while (!q.empty()) {

		size = q.size();
		ret++;

		for (int i = 0; i < size; i++) {

			int xp = q.front().x;
			int yp = q.front().y;
			int d = q.front().direct;
			q.pop();

			if (xp == en_x && yp == en_y && d == en_d) {

				cout << ret;
				exit(0);
			}

			// 명령 1. Go k

			int xp2, yp2, d2;

			bool flag = true;

			for (int j = 1; j <= 3; j++) { // k는 1, 2, 3

				if (!flag) break;

				if (d == 1) {//동쪽
					xp2 = xp;
					yp2 = yp + j;
				}

				else if (d == 2) { // 서쪽
					xp2 = xp;
					yp2 = yp - j;

				}

				else if (d == 3) { // 남쪽
					xp2 = xp + j;
					yp2 = yp;
				}

				else { //북쪽
					xp2 = xp - j;
					yp2 = yp;
				}
			
				if (xp2 < 1 || yp2 < 1 || m < xp2 || n < yp2) continue;
				if (visit[xp2][yp2][d] == 1) continue;
				if (map[xp2][yp2] == 1) {
					flag = false;
					continue;
				}

				visit[xp2][yp2][d] = 1;
				q.push(Point(xp2, yp2, d));
			}

			//명령 2, Turn dir

			// Left
			d2 = turn_left(d);
			if (visit[xp][yp][d2] == 0) {
				
				visit[xp][yp][d2] = 1;
				q.push(Point(xp, yp, d2));
			}

			// Right
			d2 = turn_right(d);
			if (visit[xp][yp][d2] == 0) {

				visit[xp][yp][d2] = 1;
				q.push(Point(xp, yp, d2));
			}
		}
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	cin >> st_x >> st_y >> st_d;
	
	cin >> en_x >> en_y >> en_d;

	ret = -1;
	visit[st_x][st_y][st_d] = 1;
	q.push(Point(st_x, st_y, st_d));
	BFS();

	return 0;
}
