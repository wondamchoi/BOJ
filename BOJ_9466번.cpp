//텀 프로젝트 9466번
#include<iostream>
#include<vector>
using namespace std;
#define MAX_SIZE 100001

int A[MAX_SIZE];
int visit[MAX_SIZE];
int visit2[MAX_SIZE];//사이클이 생기는 곳 방문체크
int visit3[MAX_SIZE];//사이클이 안생기는 곳 방문체크
int value, ret;
bool flag;
vector<int> vt;

void dfs(int now) {

	if (now == value) {
		flag = true;
		return;
	}
	
	if (visit[now] == 1) return;
	if (visit2[now] == 1) return;
	if (visit3[now] == 1) return;

	visit[now] = 1;
	vt.push_back(now);
	dfs(A[now]);
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, n;
	cin >> T;

	while (T--) {

		cin >> n;

		ret = 0;

		for (int i = 1; i <= n; i++) {
			visit[i] = visit2[i] = visit3[i] = 0;
			cin >> A[i];
		}

		for (int i = 1; i <= n; i++) {

			if (visit2[i] == 1) continue;

			flag = false;
			value = i;
			
			vt.clear();
			dfs(A[i]);

			if (!flag) {
				ret++;
				visit3[i] = 1;

				for (int j = 0; j < vt.size(); j++) {
					visit[vt[j]] = 0;
				}
			}
			else {
				for (int j = 0; j < vt.size(); j++) {
						visit2[vt[j]] = 1;
						visit[vt[j]] = 0;
					}
				}
		}
		
		cout << ret << '\n';
	}

	return 0;
}
