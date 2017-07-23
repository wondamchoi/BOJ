//수강 신청 13414번

#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
using namespace std;
typedef pair<int, string> P;

int k, l;
string student;
map<string, int> mp;
vector<P> vt;
map<string, int>::iterator iter;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> k >> l;
	for (int i = 0; i < l; i++) {

		cin >> student;
		mp[student] = i;
	}

	for (iter = mp.begin(); iter != mp.end(); ++iter) {
	
		vt.push_back(P(iter -> second, iter -> first));
	}
	
	sort(vt.begin(), vt.end());

	int size;
	size = vt.size();

	if (k < vt.size()) {
		for (int i = 0; i < k; i++) {
			cout << vt[i].second << '\n';
		}
	}

	else {
		for (int i = 0; i < vt.size(); i++) {
			cout << vt[i].second << '\n';
		}
	}

	return 0;
}
