
//암호 만들기 1759번
//최소 1개의 모음과 최소 2개의 자음 + 정렬된 문자(증가된 순서)

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define MAX_SIZE 20

char amho[MAX_SIZE];
char output[MAX_SIZE];
int L, C;

int cnt_moum(char* arr) {

	int cnt = 0;
	for (int i = 0; i < L; i++) {
		if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') cnt++;
	}

	return cnt;
}

int cnt_zaum(char* arr) { // L개의 문자를 선택해야 되는데 그 중 자음의 갯수는 L - 모음의 갯수와 같다.!

	return L - cnt_moum(arr);
}

void dfs(int idx, int d) {

	output[d] = amho[idx];

	if (d == L - 1) {

		if (1 <= cnt_moum(output) && 2 <= cnt_zaum(output)) {
			for (int i = 0; i < l; i++) {
				cout << output[i];
			}
			cout << '\n';
		}
		return;
	}

	for (int i = idx + 1; i < C; i++) {
		dfs(i, d + 1);
	}
}

int main(void) {

	cin >> L >> C;

	for (int i = 0; i < C; i++) {
		cin >> amho[i];
	}

	//미리 정렬을 하면 깊이가 l이 되었을때 정렬되어있는지 검사할 필요 없다.
	sort(amho, amho + C);
	
	for (int i = 0; i <= C - L; i++) {
		dfs(i, 0);
	}

	return 0;
}

