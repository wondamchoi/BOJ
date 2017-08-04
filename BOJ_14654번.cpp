//스테판 쿼리 14654번

#include<iostream>
#include<algorithm>
using namespace std;
#define MAX_SIZE 300

int A[MAX_SIZE];
int B[MAX_SIZE];
int n, win, cnt, MAX;

int func(int a, int b) {//승자를 구하는 함수
	
	if (a == b) {

		//비긴 경우 새로 들어오는 사람이 이김
		if (win == 1) return 2;
		else return 1;
	}

	if (a == 1 && b == 2) return 2;
	if (a == 1 && b == 3) return 1;
	if (a == 2 && b == 1) return 1;
	if (a == 2 && b == 3) return 2;
	if (a == 3 && b == 1) return 2;
	if (a == 3 && b == 2) return 1;
}

int main(void) {

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> B[i];
	}
	
	MAX = 0;

	for (int i = 0; i < n; i++) {

		if (i == 0) { 
			win = func(A[i], B[i]);
			cnt++;
		}

		else {

			if (win == 1) {

				if (func(A[i], B[i]) == 1) cnt++;
				else {

					MAX = max(MAX, cnt);
					cnt = 1;
					win = 2;
				}
			}

			else {

				if (func(A[i], B[i]) == 2) cnt++;
				else {
					MAX = max(MAX, cnt);
					cnt = 1;
					win = 1;
				}
				
			}
		}
	}

	MAX = max(MAX, cnt); //코너 케이스 조심!

	cout << MAX;
	
	return 0;
}
