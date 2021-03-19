/*

�� �������� ��Ƽ ��ҷ� �̵��ϴ� �Ÿ��� ��Ƽ ��ҿ��� �ٽ� �ڽ��� ������ ���ƿ��� �Ÿ��� �ٸ� �� �ִ�.
�׷��� go, come �� ���� vector�� �� ��, �� �� �ִ� �Ÿ��� ����.
�� ��, �� �л����� �̵��Ÿ��� ���ϸ鼭 ū ���� �����ߴ�.

*/
#include<bits/stdc++.h>
#define INF 987654321
using namespace std;

int N, M, X;
vector<pair<int, int> > vp[1001];

vector<int> dijkstra(int start, int dest) {
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	vector<int> dist(N + 1, INF);
	bool visited[1001] = { false, }; // ����� �湮 üũ
	pq.push(make_pair(0, start)); // ���� ��带 �־��ش�. (���, ���)
	dist[start] = 0; // ���� �Ÿ��� 0

	while (!pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (visited[cur]) continue; // ������ �湮�ߴ� ����̸� pass

		visited[cur] = true;
		for (int i = 0; i < vp[cur].size(); i++) {
			int next = vp[cur][i].first;
			int n_cost = vp[cur][i].second;
			if (dist[next] > cost + n_cost) { // next�� �������� ����� ������ ��뺸�� �� ���ٸ� ����� �����Ѵ�.
				dist[next] = cost + n_cost;
				pq.push(make_pair(dist[next], next));
			}
		}
	}

	return dist;
}

int main() {
	cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		int u, v, cost;
		cin >> u >> v >> cost;
		vp[u].push_back(make_pair(v, cost));
	}

	int answer = 0;
	for (int i = 1; i <= N; i++) {
		vector<int> go = dijkstra(i, X); // �� �л�(i)�� ��Ƽ ���(X)�� �̵��ϴ� �ִܰŸ�
		vector<int> come = dijkstra(X, i); // ��Ƽ ���(X)���� �� �л����� ��(i)���� ���ƿ��� �ִ� �Ÿ�

		if (go[X] + come[i] >= INF) continue; // �̵� ��ΰ� ���� ���.
		answer = max(answer, go[X] + come[i]);
	}

	cout << answer << '\n';

	return 0;
}