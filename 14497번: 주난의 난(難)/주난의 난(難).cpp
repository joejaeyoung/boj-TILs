/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 14497                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/14497                          #+#        #+#      #+#    */
/*   Solved: 2026/02/11 20:38:45 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int map[301][301];
int visited[301][301];
pair<int, int> cur;
pair<int, int> cho;
int n, m;
queue<pair<int, int>> q;
queue<pair<int, int>> tmp_q;
int t = 0;


int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void bfs(int y, int x) {
	while(q.size()) {
		pair<int, int> pos = q.front(); q.pop();

		if (map[cho.first - 1][cho.second - 1] == 0) {
			return ;
		}

		for(int i = 0; i < 4; i++) {
			int ny = pos.first + dy[i];
			int nx = pos.second + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (visited[ny][nx]) continue;

			visited[ny][nx] = 1;
			if (map[ny][nx] == 0) {
				q.push({ny, nx});
			}
			if (map[ny][nx] != 0) {
				map[ny][nx] = 0;
				tmp_q.push({ny, nx});
			}
		}
	}
	while(q.size()) q.pop();
	q = tmp_q;
	while(tmp_q.size()) tmp_q.pop();
}

void debug() {
	cout << "=== " << t << " ===\n";
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	cin >> cur.first >> cur.second;
	cin >> cho.first >> cho.second;
	string tmp;
	for(int i = 0; i < n; i++) {
		cin >> tmp;
		for(int j = 0; j < m; j++) {
			if (tmp[j] == '#') map[i][j] = 2;
			else if (tmp[j] == '1') map[i][j] = 1;
			else if (tmp[j] == '0') map[i][j] = 0;
			else if (tmp[j] == '*') {
				map[i][j] = 3;
				q.push({i, j});
				visited[i][j] = 1;
			}
		}
	}

	// debug();
	while (1) {
		bfs(cur.first, cur.second);
		t++;
		// debug();
		if (map[cho.first - 1][cho.second - 1] == 0) break;
	}

	if (t == 0)
		cout << "0\n";
	else
		cout << t << '\n';
	return 0;
}