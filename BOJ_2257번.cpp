// 화학식량 2257번

#include<iostream>
#include<string>
#include<stack>
using namespace std;

stack<string> st;

int main(void) {

	string s;

	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		
		if (s[i] == '(') st.push("(");

		else if (s[i] == ')') {
			
			int sum = 0;
	
			while (st.top() != "(") {

				if (st.top() == "H") sum += 1;
				else if (st.top() == "C") sum += 12;
				else if(st.top() == "O")  sum += 16;
				else sum += stoi(st.top());

				st.pop();
			}

			st.pop();
			st.push(to_string(sum));
		}

		else if (s[i] == 'H') st.push("H");
		else if (s[i] == 'C') st.push("C");
		else if (s[i] == 'O') st.push("O");
		else { //숫자

			int k = 0;

			if (st.top() == "H" || st.top() == "C" || st.top() == "O") { //스택에 'H', 'C', 'O'가 있을때 (문자 뒤에 있는 숫자)
			
				if (st.top() == "H") {
					st.pop();
					k += 1;
				}
				else if (st.top() == "C") {
					st.pop();
					k += 12;
				}
				else {
					st.pop();
					k += 16;
				}

				k *= s[i] - '0';
				st.push(to_string(k));
			}
		
			else { //스택에 숫자가 있을 때 (괄호 뒤에 있는 숫자)
				
				k += stoi(st.top());
				st.pop();
				k *= s[i] - '0';
				st.push(to_string(k));
			}
		}
		}

	int ret = 0;
	while (!st.empty()) {

		if (st.top() == "H") ret += 1;
		else if (st.top() == "C") ret += 12;
		else if (st.top() == "O") ret += 16;
		else ret += stoi(st.top());
			
		st.pop();
	}

	cout << ret;

	return 0;
}
