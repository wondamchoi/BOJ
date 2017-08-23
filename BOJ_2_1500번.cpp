
// 최대곱 1500번
//곱이 최대이려면 서로 비슷한 숫자이여야 한다.

#include<iostream>
using namespace std;
typedef long long int ll;

int main(void) {

	int s, k, t, r;
	ll ret;

	cin >> s >> k;

	ret = 1;

	t = s / k;
	r = s % k;

	for (int i = 0; i < k; i++) {
		
		if (r != 0) {
			ret *= (t + 1);
			r--;
		}

		else ret *= t;
	}
	
	cout << ret;

	return 0;
}
