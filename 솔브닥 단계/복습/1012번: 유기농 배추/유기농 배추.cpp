/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1012                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1012                           #+#        #+#      #+#    */
/*   Solved: 2026/11/28 11:36:02 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int map[51][51];
int visited[51][51];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, 1, -1};

void dfs(int y, int x) {

	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny > 50 || nx < 0 || nx > 50) continue;
		if (visited[ny][nx] || map[ny][nx] == 0) continue;

		visited[ny][nx] = 1;
		dfs(ny, nx);
	}
}

int solve() {
	int ret = 0;

	memset(map, 0, sizeof(map));
	memset(visited, 0, sizeof(visited));

	int m, n, k;
	cin >> m >> n >> k;

	int x, y;
	while (k--) {
		cin >> x >> y;
		map[x][y] = 1;
	}

	for(int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j]) continue;
			if (map[i][j] == 0) continue;

			visited[i][j] = 1;
			dfs(i, j);
			ret++;
		}
	}
	return ret;
}

int main() {
	int T;
	cin >> T;

	while(T--) {
		cout << solve() << '\n';
	}
}