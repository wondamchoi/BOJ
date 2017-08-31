//키 순서 2458번

#include<iostream>
using namespace std;
#define MAX_SIZE 501
#define INF 987654321

int relation[MAX_SIZE][MAX_SIZE];
int up_cnt[MAX_SIZE]; //나 보다 키 큰 학생 수
int down_cnt[MAX_SIZE]; //나 보다 키 작은 학생 수

int main(void) {
	
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, a, b;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			relation[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++) {

		cin >> a >> b;
		relation[a][b] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				
				if (i == j || i == k || j == k) continue;
				if (relation[i][j] > relation[i][k] + relation[k][j]) {
					relation[i][j] = relation[i][k] + relation[k][j];
				}
			}
		}
	}

	int ret = 0;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {

			if (i == j) continue;
			if (relation[i][j] != INF) {
				up_cnt[i]++;
				down_cnt[j]++;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (up_cnt[i] + down_cnt[i] == n - 1) ret++;
	}

	cout << ret;

	return 0;
}
