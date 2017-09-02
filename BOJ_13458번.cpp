// 시험 감독 13458번

#include<iostream>
using namespace std;
#define MAX_SIZE 1000000
typedef long long int ll;

int A[MAX_SIZE];

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, B, C;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	cin >> B >> C;

	ll ret = 0;

	for (int i = 0; i < n; i++) {
		
		A[i] = A[i] - B;
		ret++; //총 감독 할당

		if (A[i] <= 0)  continue;
		else {
			
			ret += A[i] / C; //부 감독 할당

			if (A[i] % C == 0) continue;
			else ret++;
		}
	}

	cout << ret;

	return 0;
}
