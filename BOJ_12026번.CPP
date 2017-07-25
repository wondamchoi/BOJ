//boj 거리 12026번

#include<iostream>
#include<queue>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;
#define MAX_SIZE 1001
#define INF 987654321
typedef pair<int, int> P;

char block[MAX_SIZE];
int dist[MAX_SIZE];
vector<P> edge[MAX_SIZE];
priority_queue<P, vector<P>, greater<P>> pq;

void dikstra(int start) {

	dist[start] = 0;
	pq.push(P(dist[start], start));

	while (!pq.empty()) {

		int now = pq.top().second;
		pq.pop();

		for (int i = 0; i < edge[now].size(); i++) {

			int next_v = edge[now][i].second;
			int next_c = edge[now][i].first;

			if (dist[next_v] > dist[now] + next_c) {
				dist[next_v] = dist[now] + next_c;

				pq.push(P(dist[next_v], next_v));
			}
		}
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> block[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i+1; j <= n; j++) {

			if (block[i] == 'B' && block[j] == 'O' ||
				block[i] == 'O' && block[j] == 'J' ||
				block[i] == 'J' && block[j] == 'B') {

				edge[i].push_back(P(pow(j - i, 2), j));
			}
		}
	}
	
	for (int i = 1; i <= n; i++) dist[i] = INF;

	dikstra(1); //시작점 1

	if (dist[n] == INF) cout << -1;
	else cout << dist[n];

	return 0;
}

