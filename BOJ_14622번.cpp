//소수 마을 14622번

#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;
#define MAX_SIZE 100000
typedef long long int ll;

int A;//대웅
int B;//규성
bool check[5000000];
vector<int> a, b;

bool prime(int n) {

	if (n == 1) return false;

	for (int i = 2; i*i <= n; i++) {
		if (n%i == 0) return false;
	}

	return true;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, ret_A, ret_B;

	cin >> n;

	ret_A = ret_B = 0;
	for (int i = 0; i < n; i++) {
		cin >> A >> B;

		if (prime(A)) { //대웅이 소수

			if (check[A]) ret_A -= 1000;
			else {
				a.push_back(A);
				sort(a.begin(), a.end(), greater<int>());
				check[A] = true;
			}
		}

		else { //대웅이 소수 아님

			if (b.size() < 3) ret_B += 1000;
			else ret_B += b[2];
		}

		if (prime(B)) { //규성이 소수

			if (check[B]) ret_B -= 1000;
			else {
				b.push_back(B);
				sort(b.begin(), b.end(), greater<int>());
				check[B] = true;
			}
		}

		else {

			if (a.size() < 3) ret_A += 1000;
			else ret_A += a[2];
		}
	}

	if (ret_A < ret_B) cout << "소수 마스터 갓규성";
	else if (ret_A > ret_B) cout << "소수의 신 갓대웅";
	else cout << "우열을 가릴 수 없음";

	return 0;
}

