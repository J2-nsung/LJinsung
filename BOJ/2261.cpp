#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

class Point {
public:
	int x;
	int y;
};

vector<Point> p;

bool compX(Point a, Point b) {
	if (a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

bool compY(Point a, Point b) {
	if (a.y == b.y) return a.x < b.x;
	return a.y < b.y;
}

int dist(Point a, Point b) {
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

int closet(int left, int right) {
	int size = right - left + 1;
	if (size == 2) return dist(p[0], p[1]);
	if (size == 3) return min(min(dist(p[0], p[1]), dist(p[1], p[2])), dist(p[0], p[2]));

	int mid = (left + right) / 2;

	// �߾Ӽ� ���� ����, ������ ���������� �ּҰ�
	int ret = min(closet(left, mid), closet(mid + 1, right));

	// d �Ÿ� �̳��� �����ϴ� ���鸸 üũ, y��ǥ �������� ����
	vector<Point> tmp;
	for (int i = left; i <= right; i++) {
		int t = p[mid].x - p[i].x;
		if (i == mid) {
			tmp.push_back(p[mid]);
			continue;
		}
		if (t*t < ret)
			tmp.push_back(p[i]);
	}
	sort(tmp.begin(), tmp.end(), compY);

	// �ڽź��� y��ǥ ���� ū ���� üũ
	for (int i = 0; i < tmp.size() - 1; i++) {
		for (int j = i + 1; j < tmp.size(); j++) {
			int t = tmp[j].y - tmp[i].y;
			if (t*t < ret)
				ret = min(ret, dist(tmp[i], tmp[j]));
			else break;
		}
	}

	return ret;
}

int main() {
	int n;
	scanf("%d", &n);
	Point point;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &point.x, &point.y);
		p.push_back(point);
	}
	sort(p.begin(), p.end(), compX);

	printf("%d\n", closet(0, n - 1));

	return 0;
}