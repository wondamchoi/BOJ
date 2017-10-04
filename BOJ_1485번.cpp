//정사각형 1485번
#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int, int> P;

P p[4];

int main(void) {

	int T;

	cin >> T;
	while (T--) {


		for (int i = 0; i < 4; i++) {
			cin >> p[i].first >> p[i].second;
		}

		sort(p, p + 4);

		int a, b, c, d;//네 변의 길이

		a = pow(p[1].first - p[0].first, 2) + pow(p[1].second - p[0].second, 2);
		b = pow(p[2].first - p[0].first, 2) + pow(p[2].second - p[0].second, 2);
		c = pow(p[3].first - p[1].first, 2) + pow(p[3].second - p[1].second, 2);
		d = pow(p[3].first - p[2].first, 2) + pow(p[3].second - p[2].second, 2);

		if (a == b && a == c && a == d) { // 네 변의 길이 같음(마름모 조건)

			int len_a, len_b;

			len_a = pow(p[3].first - p[0].first, 2) + pow(p[3].second - p[0].second, 2);
			len_b = pow(p[2].first - p[1].first, 2) + pow(p[2].second - p[1].second, 2);

			if (len_a == len_b) cout << 1 << '\n'; //네 각의 크기 같음 = 두 대각선의 길이 같음(직사각형 조건)
			else cout << 0 << '\n';
		}

		else cout << 0 << '\n';
	}

	return 0;
}
