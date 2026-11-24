/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 12851                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/12851                          #+#        #+#      #+#    */
/*   Solved: 2026/02/11 20:38:24 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

queue<int> q;
int visited[100001];
int g_n, g_k;
int g_count;

void bfs(int n, int k) {
	while (q.size()) {
		int p = q.front(); q.pop();

		if (p == k) {
			g_count++;
		}

		/*
		for(int next : {p + 1, p - 1, p * 2})
		*/
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

			if (np < 0 || np > 100001) continue;
			if (visited[np] == 0 || (visited[np] == visited[p] + 1)) {
				visited[np] = visited[p] + 1;
				q.push(np);
			}
		}
	}
}

int main() {
	cin >> g_n >> g_k;

	visited[g_n] = 1;
	q.push(g_n);
	bfs(g_n, g_k);

	if (visited[g_k] == 0)
		cout << "0\n";
	else
		cout << visited[g_k] - 1<< '\n';
	cout << g_count << '\n';
}
