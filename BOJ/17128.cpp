#include<bits/stdc++.h>
using namespace std;

int quality[200001];
int cow[200001];

int main() {
	ios_base::sync_with_stdio(false); // �� ���� ��� �ð� �ʰ��� �߻����� ����.
	cin.tie(nullptr);

	int N, Q;
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		cin >> cow[i];
	}

	for (int i = 0; i < 200001; i++) quality[i] = 1; // ���ҵ��� ������� �ϱ� ������ 1�� �ʱ�ȭ

	int sum = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= i + 3; j++) { // quality[i]�� �������� �־��� S�� ���ϱ� ���� A_i * A_i+1 * A_i+2 * A_i+3�� ����.
			if (j%N == 0) quality[i] *= cow[j]; // 0��° index = N��° index
			else quality[i] *= cow[j%N];
		}
		sum += quality[i];
	}

	for (int i = 0; i < Q; i++) {
		int idx;
		cin >> idx;
		for (int j = idx - 3; j <= idx; j++) {
			if (j%N == 0) { // 0��° index = N��° index
				quality[N] *= -1;
				sum += 2 * quality[N];
			}
			else if (j%N < 0) { // �����̸� N+(j%N)��° �ε����� �ȴ�. ex) -1 -> N, -2 -> N-1
				quality[N + (j%N)] *= -1;
				sum += 2 * quality[N + (j%N)];
			}
			else {
				quality[j%N] *= -1;
				sum += 2 * quality[j%N];
			}
		}
		cout << sum << '\n';
	}

	return 0;
}