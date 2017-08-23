//최대 곱 1500번
//곱이 최대이려면 서로 비슷한 숫자이여야 한다.

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long int ll;

int s, k;
vector<int> vt;
ll MAX;

void dfs(int sum, int before_add, int d) {

	if (s < sum) return; //깊이가 k가 되기전에 이미 sum가 s를 넘음

	if (d == k) {

		if (sum != s) return; //깊이가 k됬을때 합이 s가 아님

		ll ret = 1;
		for (int i = 0; i < vt.size(); i++) {
			ret *= vt[i];
		}

		MAX = max(MAX, ret);
		return;
	}

	for (int i = before_add; i <= s - sum; i++) {
		
		vt.push_back(i);
		dfs(sum + i, i, d + 1);
		vt.pop_back();
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	
	cin >> s >> k;

	MAX = 0;

	for (int i = s/k - 1; i <= s - k + 1; i++) { // 시작점이 1이 아닌 s/k -1 이라는것이 핵심!
		vt.push_back(i);
		dfs(i, i, 1);
		vt.pop_back();
	}

	cout << MAX;

	return 0;
}

