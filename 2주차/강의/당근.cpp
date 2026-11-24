#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

const int N = 101;
const int M = 101;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

bool map[N][M];
int visited[N][M];
queue<pair<int, int>> q;

int n, m;
int s_y, s_x;
int e_y, e_x;


int main(void) {
	ios::sync_with_stdio(false);
	std::cin.tie(0);

	cin >> n >> m;
	cin >> s_y >> s_x;
	cin >> e_y >> e_x;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	q.push(make_pair(s_y, s_x));
	visited[s_y][s_x] = 1;
	while(q.size()) {
		pair<int, int> p = q.front(); q.pop();

		for(int i = 0; i < 4; i++) {
			int ny = p.first + dy[i];
			int nx = p.second + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m || map[ny][nx] == 0) continue;
			if (visited[ny][nx]) continue;

			visited[ny][nx] = visited[p.first][p.second] + 1;
			q.push(make_pair(ny, nx));
			// cout << "y : " << ny << " x : " << nx << '\n';
		}
	}

	cout << visited[e_y][e_x];

	return 0;
}