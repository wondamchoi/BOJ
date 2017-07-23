//학교 탐방하기 13418번

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX_SIZE 1001

class Edge {

public:
	int cost;
	int v1;
	int v2;

public:
	Edge(int a, int b, int c) {
		cost = a;
		v1 = b;
		v2 = c;
	}
};

bool comp(Edge a, Edge b) {

	if (a.cost != b.cost) return a.cost < b.cost;
	else if (a.v1 != b.v1) return a.v1 < b.v1;
	else return a.v2 < b.v2;
}

vector<Edge> vt;
int parent[MAX_SIZE];

int find(int n) {

	if (parent[n] == n) return n;
	return parent[n] = find(parent[n]);
}

void Union(int a, int b) {

	a = find(a);
	b = find(b);

	parent[a] = b;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, a, b, c; //c = 0 오르막길 , c = 1 내리막길
	int best_path, worst_path;

	cin >> n >> m;

	best_path = worst_path = 0;

	for (int i = 0; i <= n; i++) parent[i] = i;
	for (int i = 0; i < m + 1; i++) {

		cin >> a >> b >> c;
		vt.push_back(Edge(c, a, b));
	}

	sort(vt.begin(), vt.end(), comp);

	//최악의 경로
	for (int i = 0; i < vt.size(); i++) {

		int V1 = vt[i].v1;
		int V2 = vt[i].v2;
		
		if (find(V1) != find(V2)) {

			int C = vt[i].cost;
			Union(V1, V2);

			if (C == 0) worst_path++;
		}
	}

	//최적의 경로
	for (int i = 0; i <= n; i++) parent[i] = i;

	for (int i = vt.size() - 1; 0 <= i; i--) {

		int V1 = vt[i].v1;
		int V2 = vt[i].v2;

		if (find(V1) != find(V2)) {

			int C = vt[i].cost;
			Union(V1, V2);

			if (C == 0) best_path++;
		}
	}

	cout << pow(worst_path, 2) - pow(best_path, 2);

	return 0;
}
