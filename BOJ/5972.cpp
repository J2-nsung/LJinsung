#include<bits/stdc++.h>
#define INF 987654321
using namespace std;

int dist[50001]; // ���� node�� ���� i��° �������� �ִ� �Ÿ�
bool visited[50001];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq; // ����� ���� ��θ� �켱 Ž���ϱ� ���� �켱���� ť
vector<pair<int, int> > vp[50001]; // ����� ������ ǥ���ϱ� ���� (����� ���, ���) ��

void dijkstra(int start, int end) {
	pq.push(make_pair(0, start)); // ���� ������ ���(�Ÿ�), ��带 ���� ���ش�.
	dist[start] = 0; // ���� �������κ����� �Ÿ��� �翬�� 0�̴�.

	while (!pq.empty()) {
		int cost = pq.top().first;
		int cur_node = pq.top().second;
		pq.pop();

		if (cur_node == end) return; // ��ǥ ������ ���� ������ �� �̻� �������� �ʴ´�.
		if (visited[cur_node]) continue; // �̹� �湮�� ����̸� pass�Ѵ�.

		visited[cur_node] = true;
		for (int i = 0; i < vp[cur_node].size(); i++) {
			int next = vp[cur_node][i].first;
			int n_cost = vp[cur_node][i].second;

			// �湮�� ����� �Ÿ��� (��������� cost + ���� ���� �̵��� ���� cost)���� ũ�ٸ� ���� �������ָ� �̵�.
			if (dist[next] > cost + n_cost) {
				dist[next] = cost + n_cost;
				pq.push(make_pair(dist[next], next));
			}
		}
	}
}

int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int u, v, cost;
		cin >> u >> v >> cost;
		vp[u].push_back(make_pair(v, cost)); // �� �������� ��带 �������ش�.
		vp[v].push_back(make_pair(u, cost));
	}

	for (int i = 1; i <= N; i++) dist[i] = INF; // ���� �� ���� ū ���� ��뿡 �־��ش�. (�ּ����� ������� �����ϱ� ����)

	dijkstra(1, N);
	cout << dist[N] << '\n';

	return 0;
}