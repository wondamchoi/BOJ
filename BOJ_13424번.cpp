//비밀 모임 13424번

#include<iostream>
using namespace std;
#define MAX_SIZE 101
#define INF 987654321

int A[MAX_SIZE]; //모임에 참석하는 친구들
int link[MAX_SIZE][MAX_SIZE];

int main(void) {


	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, n, m, a, b, c, k;

	cin >> T;
	while (T--) {

		cin >> n >> m;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {

				if (i == j) link[i][j] = 0;
				else link[i][j] = INF;
			}
		}

		for (int i = 0; i < m; i++) {

			cin >> a >> b >> c;
			link[a][b] = c;
			link[b][a] = c;
		}

		cin >> k;
		for (int i = 0; i < k; i++) {
			cin >> A[i];
		}

		//폴로이드
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {

					if (i == j || i == k || j == k) continue;
					if (link[i][j] > link[i][k] + link[k][j]) {
						link[i][j] = link[i][k] + link[k][j];
					}
				}
			}
		}

		int min_dis = INF;
		int min_room, sum_dis;

		for (int i = 1; i <= n; i++) { //방 번호

			sum_dis = 0;
			for (int j = 0; j < k; j++) {//모임 참석 친구들
				sum_dis += link[i][A[j]];
			}

			if (sum_dis < min_dis) {
				min_dis = sum_dis;
				min_room = i;
			}
		}

		cout << min_room << '\n';
	}

	return 0;
}


