//멀티탭 스케줄링 1700번

#include<iostream>
#include<vector>
using namespace std;
#define MAX_SIZE 101
#define INF 987654321

int A[MAX_SIZE];
int plug[MAX_SIZE];
int cnt[MAX_SIZE];
vector<int> vt;
int n, k, ret, plug_use;

bool check(int index) {

	for (int i = 1; i <= n; i++) {
		if (plug[i] == A[index]) {
			cnt[A[index]]--;
			return true;
		}
	}

	return false;
}

int get_distance(int num, int start) {

	for (int i = start; i <= k; i++) {
			
		if (A[i] == num) return i - start;
	}

	return INF;
}

int main(void) {

	cin >> n >> k;

	for (int i = 1; i <= k; i++) {
		cin >> A[i];
		cnt[A[i]]++;
	}

	ret = plug_use = 0;

	int idx, plug_idx;

	plug_idx = 1;

	for (idx = 1; idx <= k; idx++) {

		if (!check(idx)) {

			if (plug_use < n) {

				plug_use++;
				cnt[A[idx]]--;
				plug[plug_idx] = A[idx];
				plug_idx++;
			}

			else {

				ret++;

				int max_idx;
				int MAX = 0;
				for (int j = 1; j <= n; j++) {

					int c = get_distance(plug[j], idx);
					if (MAX < c) {

						MAX = c;
						max_idx = j;
					}
				}

				cnt[A[idx]]--;
				plug[max_idx] = A[idx];
			}
		}

		else {

			cnt[A[idx]]--;
		}
	}

	cout << ret;

	return 0;
}

