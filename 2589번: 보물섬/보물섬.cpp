/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2589                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2589                           #+#        #+#      #+#    */
/*   Solved: 2026/02/09 17:47:03 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int map[51][51];
int visited[51][51];
queue<pair<int, int>> q;
vector<pair<int, int>> lands;
pair<int, int> sp;
pair<int, int> ep;

int h, w;
int ret = 0;

int bfs(int start_point) {
	int dis = 0;

	while(q.size()) {
		pair<int, int> p = q.front(); q.pop();

		for(int i = 0; i < 4; i++) {
			int ny = p.first + dy[i];
			int nx = p.second + dx[i];

			if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
			if (visited[ny][nx] || map[ny][nx] == 0) continue;

			visited[ny][nx] = visited[p.first][p.second] + 1;
			dis = max(dis, visited[ny][nx]);
			q.push({ny, nx});
		}
	}
	if (dis == 0) return 0;
	return dis - 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string tmp;
	cin >> h >> w;

	for(int i = 0; i < h; i++) {
		cin >> tmp;
		for(int j = 0; j < tmp.size(); j++) {
			if (tmp[j] == 'W') {
				map[i][j] = 0;
			}
			else {
				map[i][j] = 1;
				lands.push_back({i, j});
			}
		}
	}

	pair<int, int> p;
	for(int i = 0; i < lands.size(); i++) {
		p = lands[i];
		q.push(p);
		visited[p.first][p.second] = 1;

		ret = max(ret, bfs(i));

		memset(visited, 0, sizeof(visited));
		while(q.size()) q.pop();
	}
	cout << ret << '\n';
}