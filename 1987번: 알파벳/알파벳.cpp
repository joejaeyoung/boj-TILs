/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1987                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1987                           #+#        #+#      #+#    */
/*   Solved: 2026/02/11 20:38:56 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

char map[21][21];
int visited['Z' - 'A'];
queue<pair<int, int>> q;
int ret = -1;
int cnt = 0;
int h, w;

// void bfs() {
// 	ret++;

// 	while(q.size()) {
// 		pair<int, int> cur = q.front(); q.pop();

// 		for(int i = 0; i < 4; i++) {
// 			int ny = cur.first + dy[i];
// 			int nx = cur.second + dx[i];

// 			if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
// 			if (visited[map[ny][nx] - 'A']) continue;

// 			visited[map[ny][nx] - 'A'] = visited[map[cur.first][cur.second] - 'A'] + 1;
// 			ret = max(ret, visited[map[ny][nx] - 'A']);
// 			q.push({ny, nx});
// 		}
// 	}
// }

void dfs(int y, int x) {
	// cout << map[y][x] << " ";
	cnt++;
	ret = max(ret, cnt);
	

	for(int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
		if (visited[map[ny][nx] - 'A']) continue;

		visited[map[ny][nx] - 'A'] = visited[map[y][x] - 'A'] + 1;
		dfs(ny, nx);
		visited[map[ny][nx] - 'A'] = 0;
		cnt--;
	}
}

int main() {
	string tmp;

	cin >> h >> w;
	for(int i = 0; i < h; i++) {
		cin >> tmp;
		for(int j = 0; j < w; j++) {
			map[i][j] = tmp[j];
		}
	}

	visited[map[0][0] - 'A'] = 1;
	// q.push({0, 0});
	// bfs();
	dfs(0, 0);

	cout << ret << '\n';
}