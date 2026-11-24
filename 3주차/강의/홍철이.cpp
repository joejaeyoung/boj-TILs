#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int map[3][3] = {
	{10, 20, 21},
	{70, 90, 12},
	{80, 110, 120}
};
bool visited[3][3];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
vector<int> path;

void dfs(int y, int x) {
	if (visited[y][x]) return;
	visited[y][x] = true;
	path.push_back(map[y][x]);


	if (y == 2 && x == 2) {
		for(auto i : path) cout << i << " ";
		cout << '\n';
		return ;
	}

	for(int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= 3 || nx >= 3)
			continue ;
		if (visited[ny][nx]) continue;

		dfs(ny, nx);
		visited[ny][nx] = false;
		path.pop_back();
	}

}

int main() {

	dfs(0, 0);
}