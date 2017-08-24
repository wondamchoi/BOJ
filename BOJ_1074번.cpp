// Z 1074번

#include<iostream>
#include<algorithm>
using namespace std;
typedef long long int ll;

ll ret;
int n, r, c;

void dfs(int size, int x, int y) {

	if (size == 2) {

		if (x == r && y == c) {
			cout << ret;
			exit(0);
		}

		else if (x == r && y + 1 == c) {
			cout << ret + 1;
			exit(0);
		}
		
		else if (x + 1 == r && y == c) {
			cout << ret + 2;
			exit(0);
		}

		else if (x + 1 == r && y + 1 == c ) {
			cout << ret + 3;
			exit(0);
		}
		
		ret += 4;
		return;
	}

	dfs(size / 2, x, y);
	dfs(size / 2, x , size / 2 + y);
	dfs(size / 2, x + size / 2, y);
	dfs(size / 2, x + size / 2, y + size / 2);

}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> r >> c;

	ret = 0;
	dfs(pow(2 , n), 0, 0);

	return 0;
}
