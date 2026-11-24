/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1189                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1189                           #+#        #+#      #+#    */
/*   Solved: 2026/02/11 20:39:26 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int map[6][6];
int visited[6][6];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int ret;
int h, w, k;

void dfs(int y, int x, int cnt) {
	// cout << y << " " << x << " " << cnt << '\n';
	if (y == 0 && x == w - 1 && cnt == k) {
		ret++;
		return ;
	}

	for(int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
		if (visited[ny][nx]) continue;
		if (map[ny][nx] == 'T') continue;

		visited[ny][nx] = 1;
		dfs(ny, nx, cnt + 1);
		visited[ny][nx] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> h >> w >> k;
	string tmp;

	for(int i = 0; i < h; i++) {
		cin >> tmp;
		for(int j = 0; j < w; j++) {
			map[i][j] = tmp[j];
		}
	}

	visited[h - 1][0] = 1;
	dfs(h - 1, 0, 1);
	cout << ret << '\n';
}