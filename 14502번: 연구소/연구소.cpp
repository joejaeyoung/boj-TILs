/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 14502                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/14502                          #+#        #+#      #+#    */
/*   Solved: 2026/02/02 16:40:24 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;
int max_a = -1;

int map[9][9];
int visited[9][9];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

vector<pair<int, int>> v;
vector<int> walls;

void DFS(int y, int x) {
	visited[y][x] = 2;

	for(int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

		if (map[ny][nx] != 1 && visited[ny][nx] == 0) {
			DFS(ny, nx);
		}
	}
}

void cal() {
	int tmp = 0;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if (map[i][j] == 0 && visited[i][j] == 0)
				tmp++;
		}
	}
	max_a = max(tmp, max_a);

	// if (max_a == 1) {
	// 	for(int i = 0; i < n; i++) {
	// 		for(int j = 0; j < m; j++) {
	// 			cout << visited[i][j] << " ";
	// 		}
	// 		cout << '\n\n';
	// 	}
	// }
}

void solve(int start) {
	if (walls.size() == 3) {
		int a = walls[0];
		int b = walls[1];
		int c = walls[2];
		map[a/m][a%m] = 1;
		map[b/m][b%m] = 1;
		map[c/m][c%m] = 1;

		// cout << "y : " << a/m << " x : " << a%m << '\n';
		// cout << "y : " << b/m << " x : " << b%m << '\n';
		// cout << "y : " << c/m << " x : " << c%m << "\n\n";

		for(auto s : v)
			DFS(s.first, s.second);
		cal();

		memset(visited, 0, sizeof(visited));
		map[a/m][a%m] = 0;
		map[b/m][b%m] = 0;
		map[c/m][c%m] = 0;
		return ;
	}

	for(int i = start + 1; i < n*m; i++) {
		if (map[i/m][i%m] >= 1) continue;
		walls.push_back(i);;
		solve(i);
		walls.pop_back();
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) 
				v.push_back({i, j});
		}
	}

	solve(-1);

	cout << max_a;
}