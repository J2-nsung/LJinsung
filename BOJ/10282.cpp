#include<bits/stdc++.h>
using namespace std;

void dijkstra(int n, int d, int c) {
	// test case���� �ʱ�ȭ ���־�� �ϹǷ� �Լ� ������ ����
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	vector<vector<pair<int, int> > > vp(n + 1);
	vector<int> dist(n + 1, INT_MAX);

	for (int i = 0; i < n + 1; i++) dist[i] = INT_MAX; // �ʱ� ���� �ִ밪���� �־��ش�.

	for (int i = 0; i < d; i++) { // ��ǻ���� �������� ��Ÿ���� �׷���
		int a, b, s;
		scanf("%d %d %d", &a, &b, &s);
		vp[b].push_back(make_pair(a, s));
	}

	// �������� ������(���)�� 0�̴�. 
	pq.push(make_pair(0, c));
	dist[c] = 0;
	while (!pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist[cur] < cost) continue; // �̹� �湮�� ����̸� �Ѿ��.

		for (int i = 0; i < vp[cur].size(); i++) {
			int next = vp[cur][i].first;
			int n_cost = vp[cur][i].second;
			if (dist[next] > cost + n_cost) { // ����� �� ���ٸ� ���� �������ش�.
				dist[next] = cost + n_cost;
				pq.push(make_pair(dist[next], next));
			}
		}
	}

	int cnt = 0;
	int max_dist = -1;
	for (int i = 1; i <= n; i++) {
		// dist�� ���ŵ� ���� ������ (INT_MAX�� �ƴϸ�) ������ ��ǻ��, ���� �ִ밪�� ������ ��ǻ�Ͱ� ������ �ð� 
		if (dist[i] != INT_MAX) {
			max_dist = max(max_dist, dist[i]);
			cnt++;
		}
	}

	printf("%d %d\n", cnt, max_dist);
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n, d, c;
		scanf("%d %d %d", &n, &d, &c);
		dijkstra(n, d, c);
	}

	return 0;
}