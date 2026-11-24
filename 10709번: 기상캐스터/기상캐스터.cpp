/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10709                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10709                          #+#        #+#      #+#    */
/*   Solved: 2026/02/02 13:55:23 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int h, w;
bool map[101][101];
int visited[101][101];

int main() {
	cin >> h >> w;
	char c;
	memset(visited, -1, sizeof(visited));

	int value = 0;
	int flag = false;
	for(int i = 0; i < h; i++) {
		value = 0;
		flag = false;
		for(int j = 0; j < w; j++) {
			cin >> c;
			if (c == 'c') {
				value = 0;
				map[i][j] = true;
				visited[i][j] = value;
				value++;
				flag = true;
			}
			else if (flag) {
				visited[i][j] = value;
				value++;
			}
		}
	}

	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			cout << visited[i][j] << " ";
		}
		cout << '\n';
	}
}