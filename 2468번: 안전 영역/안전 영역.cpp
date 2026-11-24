/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2468                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2468                           #+#        #+#      #+#    */
/*   Solved: 2026/01/27 16:04:20 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int map[101][101];
bool visited[101][101];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int n;
int maxH, tmpH;
int cnt, ret;

void DFS(int y, int x) {
	// cout << "y : " << y << " x : " << x << '\n';

	for(int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		if (visited[ny][nx]) continue;
		if (map[ny][nx] - tmpH >= 0) {
			visited[ny][nx] = true;
			DFS(ny, nx);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	cin >> n;

	maxH = -1;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> map[i][j];
			maxH = max(maxH, map[i][j]);
		}
	}

	for(tmpH = 1; tmpH <= maxH; tmpH++) {
		// cout << "높이 : " << tmpH << '\n';
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if (visited[i][j] == false && map[i][j] - tmpH >= 0) {
					visited[i][j] = true;
					DFS(i, j);
					cnt++;
				}
			}
		}
		ret = max(ret, cnt);

		memset(visited, 0, sizeof(visited));
		cnt = 0;
	}
	cout << ret << '\n';
}