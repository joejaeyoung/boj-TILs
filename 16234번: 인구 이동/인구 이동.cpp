/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 16234                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/16234                          #+#        #+#      #+#    */
/*   Solved: 2026/02/09 19:23:52 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int val[51][51];
int visited[51][51];

int n, l, r, t;
int cnt_area, asso_num;

vector<pair<int, int>> asso;

int dfs(int y, int x) {
	int cal = 0;
	int ret = 0;

	asso.push_back({y, x});
	visited[y][x] = 1;
	cnt_area++;
	ret += val[y][x];

	//첫 왕국이 고립되어 있는 경우 있어서 dfs도 반복문으로 다 돌려야함.
	//

	for(int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		if (visited[ny][nx]) continue;

		cal = abs(val[y][x] - val[ny][nx]);
		if (l <= cal && cal <= r) {
			ret += dfs(ny, nx);
		}
	}
	return ret;
}

void print() {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout << val[i][j] << " ";
		}
		cout << '\n';
	}
}

void refresh_map() {
	int area_humans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			//하나의 connected component 찾음
			if (visited[i][j] == 0) {
				area_humans = dfs(i, j);
				asso_num++;

				// cout << "시간 : " << t << " asso_num : " << asso_num << " 벡터 아이템 수 : " << asso.size() << " 총 인원 : " << area_humans << '\n';
				// print();

				//인구수 변경
				for(auto a : asso) {
					val[a.first][a.second] = area_humans / asso.size();
				}

				area_humans = 0;
				asso.clear();
			}
		}
	}
	return ;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> l >> r;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> val[i][j];
		}
	}

	while(true) {
			refresh_map();
			if (asso_num == n * n) break;
			asso_num = 0;
			t++;
			memset(visited, 0, sizeof(visited));
	}
	cout << t << '\n';
}