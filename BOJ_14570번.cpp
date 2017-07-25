#include<iostream>
using namespace std;
typedef pair<int, int> P;
typedef long long int ll;
#define MAX_SIZE 200001
P A[MAX_SIZE];

void dfs(int now, ll h) {

	if (A[now].first == -1 && A[now].second == -1) { //리프노드 일때
		cout << now;
		exit(0);
	}

	else if (A[now].first == -1 && A[now].second != -1) { //오른쪽 자식만 있는 경우
		dfs(A[now].second, h);
	}
	else if (A[now].first != -1 && A[now].second == -1) { //왼쪽 자식만 있는 경우
		dfs(A[now].first, h);
	}

	else { //양쪽 자식이 있는 경우
		if (h % 2 == 0)  dfs(A[now].second, h / 2);
		else dfs(A[now].first, (h / 2) + 1);
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	ll k;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> A[i].first >> A[i].second;
	}

	cin >> k;

	int root = 1;
	dfs(root, k);

	return 0;
}
