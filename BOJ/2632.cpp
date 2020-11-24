#include<iostream>
#include<unordered_map>
using namespace std;

int A[1001], B[1001];

unordered_map<int, int> partialSum(int arr[], int size) {
	unordered_map<int, int> ump;
	int sum = 0;
	ump[sum]++;
	for (int i = 0; i < size; i++) {
		sum = arr[i];
		for (int j = i + 1; j < size; j++) {
			ump[sum]++;
			sum += arr[j];
		}
		ump[sum]++;
	}

	sum = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}

	for (int i = size - 2; i >= 1; i--) {
		int tmp = arr[i];
		for (int j = i - 1; j >= 1; j--) {
			ump[sum - tmp]++;
			tmp += arr[j];
		}
		ump[sum - tmp]++;
	}

	return ump;
}

int main() {
	unordered_map<int, int> psum;
	int target, m, n;
	long long answer = 0;
	cin >> target >> m >> n;
	for (int i = 0; i < m; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> B[i];
	}

	psum = partialSum(A, m);

	// �� ��° ������ �κ� �� [0 ~ n) ���� �κ� ��
	int sum = 0;
	answer += psum[target - sum];
	for (int i = 0; i < n; i++) {
		sum = B[i];
		for (int j = i + 1; j < n; j++) {
			answer += psum[target - sum];
			sum += B[j];
		}
		answer += psum[target - sum];
	}

	/*
	���ڴ� �����̱� ������ ���� �ε������� �� �ε����� �̾�����
	���������� �κ��յ� �����־�� �Ѵ�. ��ü �տ��� ��� �κи� ���� ������� ����
	*/
	sum = 0;
	for (int i = 0; i < n; i++) {
		sum += B[i];
	}

	for (int i = n - 2; i >= 1; i--) {
		int tmp = B[i];
		for (int j = i - 1; j >= 1; j--) {
			answer += psum[target - (sum - tmp)];
			tmp += B[j];
		}
		answer += psum[target - (sum - tmp)];
	}
	cout << answer << '\n';

	return 0;
}