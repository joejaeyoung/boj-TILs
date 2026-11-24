#include <iostream>
using namespace std;

int dy[] = {0, 1};
int dx[] = {1, 0};

int map[301][301];
int visited[301][301];

int ret = 0;
int width = 0, height = 0;

void solve(int y, int x) {
	if (visited[y][x]) return ;

	visited[y][x] = 1;

	if (visited[height - 1][width - 1]) {
		ret = 1;
		return ;
	}
	
	for(int i = 0; i < 2; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= height || nx >= width) continue;
		if (map[ny][nx] == 0)

		solve(ny, nx);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);


	cin >> width >> height;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cin >> map[i][j];
		}
	}

	solve(0, 0);

	if (ret) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}

	// 코드 작성
	return 0;
}