/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2636                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2636                           #+#        #+#      #+#    */
/*   Solved: 2026/02/02 17:45:18 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int visited[101][101];
int map[101][101];
int pmap[101][101];

int h, w;
int hour = 0;
int cnt;

void DFS(int y, int x, int map[][101]) {
	visited[y][x] = 1;

	for(int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= h || nx >= w || visited[ny][nx]) continue;
		if (map[ny][nx] == 1) {
			visited[ny][nx] = 1;
			map[ny][nx] = 0;
			continue;
		}
		if (map[ny][nx] == 0) {
			DFS(ny, nx, map);
		}
	}
}

bool is_melted() {
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			if (map[i][j]) return true;
		}
	}
	return false;
}

void floodfill(int y, int x) {
	visited[y][x] = 1;
	cnt++;

	for(int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
		if (visited[ny][nx] || pmap[ny][nx] == 0) continue;
		floodfill(ny, nx);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> h >> w;

	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			cin >> map[i][j];
		}
	}

	while(is_melted()) {
		memcpy(pmap, map, sizeof(map));	// 다 녹기 한시간 전
		DFS(0, 0, map);
		memset(visited, 0, sizeof(visited));
		hour++;
	}

	// for(int i = 0; i < h; i++) {
	// 	for(int j = 0; j < w; j++) {
	// 		cout << pmap[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }

	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			if (pmap[i][j] == 1 && visited[i][j] == 0)
				floodfill(i, j);
		}
	}


	cout << hour << '\n';
	cout << cnt << '\n';
}
