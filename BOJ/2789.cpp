#include<iostream>
#include<string>
using namespace std;

int main() {
	string s;
	string answer = "";
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'C' || s[i] == 'A' || s[i] == 'M' || s[i] == 'B' || s[i] == 'R' || s[i] == 'I' || s[i] == 'D' || s[i] == 'G' || s[i] == 'E')
			continue;
		answer += s[i];
	}
	cout << answer << '\n';

	return 0;
}