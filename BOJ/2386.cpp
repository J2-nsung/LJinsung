#include<bits/stdc++.h>
using namespace std;

string toLower(string s) {
	for (int i = 0; i < s.length(); i++) {
		s[i] = tolower(s[i]);
	}

	return s;
}

int main() {
	while (true) {
		char c;
		string s;
		cin >> c;
		getline(cin, s);

		if (c == '#') break;

		s = toLower(s); // ��� �ҹ��ڷ� �ٲ��ش�.
		int answer = 0;
		for (int i = 0; i < s.length(); i++) {
			if (c == s[i]) answer++; // ã������ ���ڰ� �����ϸ� ī��Ʈ���ش�.
		}

		cout << c << ' ' << answer << '\n';
	}


	return 0;
}