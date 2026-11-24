/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2583                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2583                           #+#        #+#      #+#    */
/*   Solved: 2026/01/27 16:28:21 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

bool map[101][101];
bool visited[101][101];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int area;
int areaCnt;
vector<int> ret;

int my, mx, k;

void fillMap() {
	int lx, ly, rx, ry;
	cin >> lx >> ly >> rx >> ry;

	for(int ty = ry - 1; ty >= ly; ty--) {
		for (int tx = rx - 1; tx >= lx; tx--) {
			map[ty][tx] = true;
		}
	}
}

void DFS(int y, int x) {
	visited[y][x] = true;
	area++;
	
	for(int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= my || nx >= mx) continue;
		if (visited[ny][nx] || map[ny][nx]) continue;

		DFS(ny, nx);
	}
}

int main() {
	cin >> my >> mx >> k;

	while(k--) {
		fillMap();

		// for(int i = 0; i < my; i++) {
		// 	for(int j = 0; j < mx; j++) {
		// 		cout << map[i][j] ? "1" : "0";
		// 	}
		// 	cout << '\n';
		// }
		// cout << '\n';
	}

	for(int i = 0; i < my; i++) {
		for(int j = 0; j < mx; j++) {
			if (map[i][j] == false && visited[i][j] == false) {
				area = 0;
				DFS(i, j);
				areaCnt++;
				ret.push_back(area);
			}
		}
	}

	cout << areaCnt << '\n';
	sort(ret.begin(), ret.end());
	for(auto i : ret) {
		cout << i << ' ';
	}

	return 0;
}