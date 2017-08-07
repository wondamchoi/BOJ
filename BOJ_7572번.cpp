//간지 7572번
#include<iostream>
#include<string>
using namespace std;

int main(void) {

	int n;

	cin >> n;

	cout << char((n  + 8) % 12 + 'A')  << (n + 6) % 10;
	
	return 0;
}

