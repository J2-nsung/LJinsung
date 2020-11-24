/*
ù ��° �迭�� �κ� ���� ��� ������ map�� �����Ѵ�.
�� �� �� ��° �迭�� �κ� ���� ���ϸ鼭 (target - sum)���� map�� �����ϸ�
�� ������ŭ answer���� �������� �ش�.
(target-sum)���� �����Ѵٴ� ���� ù�� ° �迭�� �κ� �հ� �� ��° �迭�� �κ�����
���� target���� �ϼ��� �� �ִٴ� ��.
*/
#include<iostream>
#include<unordered_map>
using namespace std;

int A[1001], B[1001];

int main() {
	unordered_map<int, int> ump;
	long long T;
	long long sum_A = 0, sum_B = 0;
	long long answer = 0;
	int n, m;
	cin >> T >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		sum_A += A[i];
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> B[i];
		sum_B += B[i];
	}

	// partial sum of first array
	for (int i = 0; i < n; i++) {
		int sum = A[i];
		for (int j = i + 1; j < n; j++) {
			ump[sum]++;
			sum += A[j];
		}
		ump[sum]++;
	}

	// partial sum of second array
	// find the target
	for (int i = 0; i < m; i++) {
		int sum = B[i];
		for (int j = i + 1; j < m; j++) {
			answer += ump[T - sum];
			sum += B[j];
		}
		answer += ump[T - sum];
	}
	cout << answer << '\n';

	return 0;
}