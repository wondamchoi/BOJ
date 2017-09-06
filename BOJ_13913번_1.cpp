//숨바꼭질 4 13913번 BFS로 풀이

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

#define MAX_SIZE 100001
#define INF 987654321
typedef pair<int, int> P;

int n, k;
vector<int> vt;
queue<int> q;
int parent[MAX_SIZE];
int visit[MAX_SIZE];

void BFS() {

	int size;

	while (!q.empty()) {

		size = q.size();

		for (int i = 0; i < size; i++) {

			int now = q.front();
			q.pop();

			if (now == k) {

				for (int i = k; i != n; i = parent[i]) {
					vt.push_back(i);
				}

				vt.push_back(n);

				cout << vt.size() - 1 << '\n';
				for (int i = vt.size()-1; 0<=i; i--) cout << vt[i] << " ";

				return;
			}

			int next = now - 1;
			if (0 <= next && visit[next] == 0) {
				visit[next] = 1;
				q.push(next);
				parent[next] = now;
			}

			// X + 1
			next = now + 1;
			if (next < MAX_SIZE && visit[next] == 0) {
				visit[next] = 1;
				q.push(next);
				parent[next] = now;
			}

			// 2*X
			next = now * 2;
			if (next < MAX_SIZE && visit[next] == 0) {
				visit[next] = 1;
				q.push(next);
				parent[next] = now;
			}
		}
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;
		
	visit[n] = 1;
	q.push(n);
	BFS();

	return 0;
}
