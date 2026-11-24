/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 17071                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/17071                          #+#        #+#      #+#    */
/*   Solved: 2026/02/11 20:38:38 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

queue<int> q;
int visited[500001];
int g_n, g_k, t;

void bfs(int n, int k, int t) {
	while(q.size()) {
		int p = q.front(); q.pop();

		g_k = g_k + visited[p];
		cout << "new g_k : " << g_k << '\n';
		if (g_k >= 500000) {
			g_k = 500000;
			visited[500000] = -1;
			return ;
		}
		if (p == g_k) {
			return ;
		}

		for(int i = '0'; i< '3'; i++) {
			int np;
			switch(i) {
				case '1' :
					np = p - 1;
				case '2' :
					np = p + 1;
				case '3' :
					np = p * 2;
			}

			if (np < 0 || np >= 500000) continue;
			if (visited[np] == 0 || (visited[np] == visited[p] + 1)) {
				visited[np] = visited[p] + 1;
				q.push(np);
			}
		}
	}

}

int main() {
	cin >> g_n >> g_k;
	if (g_n == g_k) {
		cout << "0\n";
		return 0;
	}
	else if (g_k >= 500000) {
		cout << "-1\n";
		return 0;
	}

	q.push(g_n);
	visited[g_n] = 1;
	bfs(g_n, g_k, t++);

	cout << visited[g_k];
}