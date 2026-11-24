/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1012                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1012                           #+#        #+#      #+#    */
/*   Solved: 2026/01/27 15:49:19 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int n, m, k;
bool map[51][51];
bool visited[51][51];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int cnt;

void DFS(int y, int x) {
	visited[y][x] = true;

	for(int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (map[ny][nx] == false) continue;
		if (visited[ny][nx] == true) continue;

		DFS(ny, nx);
	}
}

void solve() {
	int x, y;
	cin >> m >> n >> k;

	while(k--) {
		cin >> x >> y;
		map[y][x] = true;
	}

	for(int i = 0; i < 51; i++) {
		for(int j = 0; j < 51; j++) {
			if (map[i][j] == false || visited[i][j]) continue;

			DFS(i, j);
			cnt++;
		}
	}

	cout << cnt << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(0);
	
	int testCase;
	cin >> testCase;
	while(testCase--) {
		solve();
		
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
		cnt = 0;
	}
	return 0;
}