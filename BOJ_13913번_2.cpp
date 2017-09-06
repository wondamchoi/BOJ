//다익스트라로 풀이

#include<iostream>
#include<queue>
#include<vector>
#include<functional>
using namespace std;

#define MAX_SIZE 100001
#define INF 987654321
typedef pair<int, int> P;

int n, k;
vector<int> vt;
priority_queue<P, vector<P>, greater<P>> pq;
int dist[MAX_SIZE];
int parent[MAX_SIZE];

void dikstra(int start) {

	dist[start] = 0;
	pq.push(P(dist[start], start));

	while (!pq.empty()) {

		int now = pq.top().second;
		pq.pop();

		if (now == k) return;

		// X - 1
		int next = now - 1;

		if (0 <= next) {

			if (dist[next] > dist[now] + 1) {

				dist[next] = dist[now] + 1;
				pq.push(P(dist[next], next));
				parent[next] = now;
			}
		}

		// X + 1
		next = now + 1;
		if (next <= 100000) {

			if (dist[next] > dist[now] + 1) {

				dist[next] = dist[now] + 1;
				pq.push(P(dist[next], next));
				parent[next] = now;
			}
		}

		// 2*X
		next = now * 2;
		if (next <= 100000) {

			if (dist[next] > dist[now] + 1) {

				dist[next] = dist[now] + 1;
				pq.push(P(dist[next], next));
				parent[next] = now;
			}
		}
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 0; i <= 100000; i++) dist[i] = INF;

	dikstra(n);

	for (int i = k; i != n; i = parent[i]) {
		vt.push_back(i);
	}

	vt.push_back(n);

	cout << vt.size() - 1 << '\n';
	for (int i = vt.size() - 1; 0 <= i; i--) cout << vt[i] << " ";

	return 0;
}

