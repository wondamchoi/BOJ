//달팽이 2 1952번

#include<iostream>
using namespace std;
#define MAX_SIZE 100

int map[MAX_SIZE][MAX_SIZE];
int visit[MAX_SIZE][MAX_SIZE];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int m, n, check, direction, ret;

int main(void) {

	cin >> m >> n;

	check = 1;
	direction = 0;// 0 -> 오른쪽, 1 -> 아래, 2 -> 왼쪽, 3 -> 위

	int x, y;
	ret = x = y = 0;
	visit[x][y] = 1;

	while (check != m*n) {

		if (direction == 0) { // 오른쪽
		
			if (n <= y + 1 || visit[x][y+1] == 1) {
				ret++;
				direction = (direction + 1) % 4;
			}

			else {
				y++;
				visit[x][y] = 1;
				check++;
			}
		}

		else if (direction == 1) { //아래

			if (m <= x + 1 || visit[x+1][y] == 1) {
				direction = (direction + 1) % 4;
				ret++;
			}
			else {
				x++;
				visit[x][y] = 1;
				check++;
			}
		}

		else if (direction == 2) { //왼쪽
			
			if (y - 1 < 0 || visit[x][y-1] == 1) {
				direction = (direction + 1) % 4;
				ret++;
			}
			else {
				y--;
				visit[x][y] = 1;
				check++;
			}
		}

		else { //위

			if (x - 1 < 0 || visit[x-1][y] == 1) {
				direction = (direction + 1) % 4;
				ret++;
			}
			else {
				x--;
				visit[x][y] = 1;
				check++;
			}
		}
	}

	cout << ret;

	return 0;
}


