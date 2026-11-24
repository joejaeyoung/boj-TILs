/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 4179                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/4179                           #+#        #+#      #+#    */
/*   Solved: 2026/02/09 20:33:43 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

#define WALL 1
#define FIRE 2
#define DEAD -1
#define ESCAPE 2

using namespace std;

int map[1001][1001];
int visited[1001][1001];
bool fire_visited[1001][1001];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

queue<pair<int, int>> q;
queue<pair<int, int>> tmp_q;
queue<pair<int, int>> fire_q;
queue<pair<int, int>> fire_tmp_q;

int h, w;
int sy, sx;
int t;
bool stopped = true;

void debug() {
	cout << "=== " << t << " ===\n";
	cout << "map\n";
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}

	cout << "visited\n";
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w ;j++)
			cout << visited[i][j];
		cout << '\n';
	}
	
	cout << "queue front\n";
	cout << q.front().first << ", " << q.front().second << '\n';
}

int is_dead() {
	int ret = 0;
	pair<int, int> cur;

	if (q.size() == 0)
		return DEAD;

	if (q.size() == 1) {
		cur = q.front();
		if (map[cur.first][cur.second] == FIRE)
			return DEAD;
	}
	return ret;
}

int is_escape(int y, int x) {
	int ret = 0;

	if ((1 && (y == 0 || y == h - 1))
		|| (1 && (x == 0 || x == w - 1)))
			return visited[y][x];
	
	return ret;
}

void fire() {
	while(fire_q.size()) {
		pair<int, int> fire = fire_q.front(); fire_q.pop();

		for(int i = 0; i < 4; i++) {
			int ny = fire.first + dy[i];
			int nx = fire.second + dx[i];

			if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
			if (map[ny][nx] == WALL) continue;
			if (map[ny][nx] == FIRE) continue;
			map[ny][nx] = FIRE;
			
			fire_tmp_q.push({ny, nx});
		}
	}

	fire_q = fire_tmp_q;
	while(fire_tmp_q.size()) 
		fire_tmp_q.pop();
}

int move() {
	while(q.size()) {
		pair<int, int> p = q.front(); q.pop();

		for(int i = 0; i < 4; i++) {
			int ny = p.first + dy[i];
			int nx = p.second + dx[i];

			if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
			if (map[ny][nx] == WALL || map[ny][nx] == FIRE) continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = visited[p.first][p.second] + 1;
			
			tmp_q.push({ny, nx});
			if (is_escape(ny, nx))
				return visited[ny][nx];
		}
	}

	while(tmp_q.size()) {
		q.push(tmp_q.front());
		tmp_q.pop();
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string tmp;
	cin >> h >> w;
	for(int i = 0; i < h; i++) {
		cin >> tmp;
		for(int j = 0; j < w; j++) {
			if (tmp[j] == '#') {
				map[i][j] = WALL;
			}
			else if (tmp[j] == 'F') {
				map[i][j] = FIRE;
				fire_q.push({i, j});
				fire_visited[i][j] = 1;
			}
			else if (tmp[j] == 'J') {
				q.push({i, j});
				visited[i][j] = 1;
			}
		}
	}

	// debug();
	int ret = 0;
	while(true) {
		// debug();
		//3. 죽었나 판단
		//4. 탈출했나 판단
		if ((ret = is_escape(q.front().first, q.front().second)) || (ret = is_dead()) ) break;
		//1. 불
		fire();
		//2. 사람 이동
		ret = move();
		if (ret) break;

		t++;
	}
	if (ret == DEAD)
		cout << "IMPOSSIBLE\n";
	else
		cout << ret << '\n';
	return 0;
}

