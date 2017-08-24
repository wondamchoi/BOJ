//맥주 마시면서 걸어가기 9205번

#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
#define MAX_SIZE 100
typedef pair<int, int> P;

queue<P> q;
P store[MAX_SIZE];
int visit[MAX_SIZE];
int T, n, my_x, my_y, festival_x, festival_y;
bool flag;

int get_distance(int x1, int y1, int x2, int y2) {

	return abs(x2 - x1) + abs(y2 - y1);
}

void BFS() {

	int size;

	while (!q.empty()) {

		size = q.size();
		for (int i = 0; i < size; i++) {

			int xp = q.front().first;
			int yp = q.front().second;
			q.pop();

			if (get_distance(xp, yp, festival_x, festival_y) <= 1000) {
				flag = true;
				return;
			}

			for (int j = 0; j < n; j++) {
				
				if (1000 >= get_distance(xp, yp, store[j].first, store[j].second) &&
					visit[j] == 0) {

					visit[j] = 1;
					q.push(P(store[j].first, store[j].second));
				}
			}
		}
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {

		cin >> n;

		cin >> my_x >> my_y;
		
		for (int i = 0; i < n; i++) visit[i] = 0;
		while (!q.empty()) q.pop();

		for (int i = 0; i < n; i++) {
			cin >> store[i].first >> store[i].second;
		}

		cin >> festival_x >> festival_y;

		flag = false;
		q.push(P(my_x, my_y));
		BFS();
		
		if (flag) cout << "happy\n";
		else cout << "sad\n";

	}

	return 0;
}

