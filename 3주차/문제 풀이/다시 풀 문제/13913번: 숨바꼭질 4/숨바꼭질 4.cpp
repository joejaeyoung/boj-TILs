/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 13913                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/13913                          #+#        #+#      #+#    */
/*   Solved: 2026/02/11 20:38:31 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

queue<int> q;
int visited[100001];
int path[100001];
int g_n, g_k;

void bfs(int n, int k) {
	while(q.size()) {
		int p = q.front(); q.pop();

		if (p == k) {
			return ;
		}

		for(char i = '0'; i < '3'; i++) {
			int np;
			switch(i) {
				case '0':
					np = p + 1;
					break;
				case '1':
					np = p - 1;
					break;
				case '2':
					np = p * 2;
					break;
			}

			if (np < 0 || np >= 100001) continue;
			if (visited[np] == 0 || (visited[np] == visited[p] + 1)) {
				visited[np] = visited[p] + 1;
				path[np] = p;
				q.push(np);
				// path.push_back(np);
			}
			// if (path.size())
			// 	path.pop_back();
		}
	}
}

int main() {
	cin >> g_n >> g_k;

	visited[g_n] = 1;
	path[g_n] = -1;
	q.push(g_n);
	// path.push_back(g_n);
	bfs(g_n, g_k);

	if (visited[g_k] == 0) 
		cout << "0\n";
	else
		cout << visited[g_k] - 1 << '\n';

	vector<int> ret;
	ret.push_back(g_k);
	int tmp = -1;
	tmp = path[g_k];

	//for(int i = k; k != n; i = prev[i]) while문 대체 가능
	while(tmp != -1) {
		ret.push_back(tmp);
		tmp = path[tmp];
	}

	for(int i = ret.size() - 1; i >= 0; i--) {
		cout << ret[i] << " ";
	}
	cout << '\n';
}