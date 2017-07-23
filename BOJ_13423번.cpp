//three dots 13423번

#include<iostream>
#include<algorithm>
using namespace std;
#define MAX_SIZE 1000

int p[MAX_SIZE];

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, n, cnt;

	cin >> T;
	while (T--) {

		cnt = 0;

		cin >> n;
		for (int i = 0; i < n; i++) {

			cin >> p[i];
		}

		sort(p, p + n);

		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {

				int left = j + 1;
				int right = n - 1;

				while (left <= right) {

					int mid = (left + right) / 2;

					if (p[j] - p[i] == p[mid] - p[j]) {
						cnt++;
						break;
					}

					else if (p[j] - p[i] < p[mid] - p[j]) {
						right = mid - 1;
					}

					else {
						left = mid + 1;
					}
				}
			}
		}

		cout << cnt << '\n';
	}

	return 0;
}



