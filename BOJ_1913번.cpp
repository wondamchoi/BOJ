//달팽이 1913번 -> 1부터가 아닌 맨 마지막 수부터 즉 (0,0) 부터 아래 -> 오른쪽 -> 위 -> 왼쪽 ! 반대로 간다 !

#include<iostream>
using namespace std;
#define MAX_SIZE 999

int map[MAX_SIZE][MAX_SIZE];
int visit[MAX_SIZE][MAX_SIZE];

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, find;

	cin >> n >> find;

	int x, y, direction; //0 -> 아래, 1 -> 오른쪽 , 2 -> 위, 3-> 왼쪽
	int value = n*n;
	int ret_x, ret_y;

	direction = x = y = 0;
	visit[x][y] = 1;
	map[x][y] = value--;

	while (value != 0) {

		if (map[x][y] == find) {
			ret_x = x + 1;
			ret_y = y + 1;
		}

		if (direction == 0) { // 아래

			if ( x == n-1 || visit[x+1][y] == 1) {
				direction = (direction + 1) % 4;
			}

			else {
				x++;
				visit[x][y] = 1;
				map[x][y] = value--;
			}
		}

		else if (direction == 1) { // 오른쪽

			if ( y == n-1 || visit[x][y + 1] == 1) {
				direction = (direction + 1) % 4;
			}
			else {
				y++;
				visit[x][y] = 1;
				map[x][y] = value--;
			}
		}

		else if (direction == 2) { // 위
			
			if ( x == 0 || visit[x-1][y] == 1) {
				direction = (direction + 1) % 4;
			}

			else {
				x--;
				visit[x][y] = 1;
				map[x][y] = value--;
			}
		}

		else { // 왼쪽

			if (y == 0 || visit[x][y - 1] == 1) {
				direction = (direction + 1) % 4;
			}

			else {
				y--;
				visit[x][y] = 1;
				map[x][y] = value--;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << " ";
		}
		cout << '\n';
	}

	cout << ret_x << " " << ret_y << '\n';
	
	return 0;
}
