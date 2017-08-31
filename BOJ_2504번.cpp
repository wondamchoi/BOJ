//괄호의 값 2504번
#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(void) {

	string s;
	stack<string> st;

	cin >> s;
	for (int i = 0; i < s.length(); i++) {

		if (s[i] == '(') st.push("(");
		else if (s[i] == '[') st.push("[");
		else {

			if (s[i] == ')') {

				if (st.empty()) {
					cout << 0;
					exit(0);
				}

				else if (st.top() == "(") {
					st.pop();
					st.push("2");
				}
				else {

					int sum = 0;
					while (st.top() != "(") {

						if (st.top() == "[") {
							cout << 0;
							exit(0);
						}
						else {
							sum += stoi(st.top());
							st.pop();
						}

						if (st.empty()) { // ")"가 나왔으면 올바른 괄호쌍이 되기 위해선는 스택에 "("가 있어야 한다. 없으면 올바르지 못함.
							cout << 0;
							exit(0);
						}
					}

					st.pop();
					st.push(to_string(2*sum));
				}
			}

			else {

				if (st.empty()) {
					cout << 0;
					exit(0);
				}

				else if (st.top() == "[") {
					st.pop();
					st.push("3");
				}
				else {

					int sum = 0;
					while (st.top() != "[") {

						if (st.top() == "(") {
							cout << 0;
							exit(0);
						}
						else {
							sum += stoi(st.top());
							st.pop();
						}

						if (st.empty()) {// "]"가 나왔으면 올바른 괄호쌍이 되기 위해선는 스택에 "["가 있어야 한다. 없으면 올바르지 못함.
							cout << 0;
							exit(0);
						}
					}

					st.pop();
					st.push(to_string(3*sum));
				}
			}
		}
	}

	int ret = 0;
	stack<string> output_st;

	while (!st.empty()) {

		if (st.top() == "(" || st.top() == "[" || st.top() == ")" ||
			st.top() == "]") { //인풋만큼 다 돌았을때 스택에 괄호가 남아 있으면 올바르지 못한 괄호
			cout << 0;
			exit(0);
		}

		output_st.push(st.top());
		st.pop();
	}

	while (!output_st.empty()) {

		ret += stoi(output_st.top());
		output_st.pop();
	}

	cout << ret;

	return 0;
}
