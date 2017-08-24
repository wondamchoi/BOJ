//트리의 부모 찾기 11725번

#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define MAX_SIZE 100001

vector<int> edge[MAX_SIZE];
int visit[MAX_SIZE];
int parent[MAX_SIZE];
queue<int > q;

void BFS() {

	int size;

	while (!q.empty()) {

		size = q.size();
		for (int i = 0; i < size; i++) {

			int p = q.front();
			q.pop();
			
			for (int j = 0; j < edge[p].size(); j++) {

				int c = edge[p][j];

				if (visit[c] == 0) {
					parent[c] = p;

					visit[c] = 1;
					q.push(c);
				}
			}
		}
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;

	cin >> n;
	int a, b;
	for (int i = 0; i < n - 1; i++) {

		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	visit[1] = 1;
	q.push(1); //루트 노드를 기준으로 bfs돌림

	BFS();
	
	for (int i = 2; i <= n; i++) cout << parent[i] << '\n';

	return 0;
}
