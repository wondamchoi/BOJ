//복날 1686번
#include<stdio.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
#define MAX_SIZE 1000
typedef pair<double, double> P;

P bunker[MAX_SIZE];
int visit[MAX_SIZE];
queue<P> q;
bool flag;
int cnt, idx;
double v, m, xs, ys, xt, yt, x, y, max_distance;

double get_distance(double x1, double y1, double x2, double y2) {

	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

void BFS() {

	int size;

	while (!q.empty()) {

		size = q.size();
		cnt++;

		for (int i = 0; i < size; i++) {

			double nx = q.front().first;
			double ny = q.front().second;
			q.pop();

			if (get_distance(nx, ny , xt, yt) < max_distance)  {
				flag = true;
				return;
			}

			for (int j = 0; j < idx; j++) { 

				if (visit[j] == 1) continue;

				if (get_distance(nx, ny, bunker[j].first, bunker[j].second) < max_distance) {

					visit[j] = 1;
					q.push(P(bunker[j].first, bunker[j].second));
				}
			}
		}
	}
}

int main(void) {

	scanf("%lf %lf", &v, &m);
	scanf("%lf %lf %lf %lf", &xs, &ys, &xt, &yt);

	idx = 0;
	while (scanf("%lf %lf", &x, &y) != EOF) {

		bunker[idx].first = x;
		bunker[idx].second = y;
		idx++;
	}

	q.push(P(xs, ys));
	flag = false;
	cnt = -1;
	max_distance = 60*v*m;

	BFS();

	if (flag) printf("Yes, visiting %d other holes.", cnt);
	else cout << "No.";

	return 0;
}
