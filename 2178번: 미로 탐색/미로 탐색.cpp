/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2178                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2178                           #+#        #+#      #+#    */
/*   Solved: 2026/01/27 15:23:49 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int map[101][101];
int visited[101][101];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int n, m;

queue<pair<int, int>> q;

void BFS() {
	
	while(q.size()) {
		pair<int, int> ne = q.front(); q.pop();

		for(int i = 0; i < 4; i++) {
			int ny = ne.first + dy[i];
			int nx = ne.second + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m || 
			map[ny][nx] == 0)
				continue;

			if (visited[ny][nx])
				continue;

			visited[ny][nx] = visited[ne.first][ne.second] + 1;
			q.push({ny, nx});
		}
	}
}

int main() {
	cin >> n >> m;
	getchar();
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			map[i][j] = getchar() - '0';
		}
		getchar();
	}

	visited[0][0] = 1;
	q.push({0, 0});
	BFS();

	// for(int i = 0; i < n; i++) {
	// 	for(int j = 0; j < m; j++) {
	// 		cout << map[i][j] << " ";
	// 	}
	// 	cout << '\n';
	// }
	cout << visited[n - 1][m - 1] << '\n';
	return 0;
}
