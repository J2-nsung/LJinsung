#include<iostream>
using namespace std;

int main() {
	int n;
	int answer;
	cin >> n;
	if (n % 2 == 0) { // ���� or ����
		if ((n / 4) % 2 == 0) answer = 2; // ����
		else answer = 4; // ����
	}

	else { // ���� or ���� or ����
		if ((n / 2) % 2 == 1) answer = 3; // ����
		else { // ���� or ����
			if (((n / 2) / 2) % 2 == 0) answer = 1; // ����
			else answer = 5; // ����
		}
	}
	cout << answer;

	return 0;
}