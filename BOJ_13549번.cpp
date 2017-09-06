//숨바꼭질 3 13549번
//1 8 -> 순간이동 계속하면 0 초에 갈수 있음
//0초 먼저 보내고 그다음 +1, -1 1초인경우해줌

#include<iostream>
#include<queue>
using namespace std;

#define MAX_SIZE 100001
typedef pair<int, int> P;

int map[MAX_SIZE];
int visit[MAX_SIZE];
queue<P> q;
int n, k;

void BFS() {

	int size;

	while (!q.empty()) {

		size = q.size();

		for (int i = 0; i < size; i++) {

			int now = q.front().first;
			int sec = q.front().second;
			q.pop();

			if (now == k) {
				cout << sec;
				exit(0);
			}

			// 2*X
			int next = now * 2;
			while (next <= 100000 && visit[next] == 0) {

				visit[next] = 1;
				q.push(P(next, sec));
				next = now * 2;
			}

			// X - 1
			next = now - 1;

			if (0 <= next && visit[next] == 0) {
				visit[next] = 1;
				q.push(P(next, sec+1));
			}

			// X + 1
			next = now + 1;
			if (next <= 100000 && visit[next] == 0) {
				visit[next] = 1;
				q.push(P(next, sec + 1));
			}
		}
	}
}

int main(void) {

	cin >> n >> k;

	visit[n] = 1;
	q.push(P(n, 0));
	BFS();

	return 0;
}
