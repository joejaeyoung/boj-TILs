/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9934                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9934                           #+#        #+#      #+#    */
/*   Solved: 2026/02/11 20:39:07 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nodes;
vector<int> graph[10];
int depth;

void traversal(int l, int m, int r, int de) {
	// cout << de << " : " << l << " " << m << " " << r << '\n';
	if (de == depth - 1) {
		graph[de].push_back(nodes[m]);
		return ;
	}

	traversal(l, (l + m - 1) / 2, m - 1, de + 1);
	graph[de].push_back(nodes[m]);
	traversal(m + 1, (m + r + 1) / 2, r, de + 1);
}

int main() {
	int tmp, node_num;
	cin >> depth;

	node_num = (2 << (depth - 1)) - 1;
	// cout << node_num << '\n';
	for(int i = 0; i < node_num; i++) {
		cin >> tmp;
		nodes.push_back(tmp);
	}

	traversal(0, node_num / 2, node_num - 1, 0);

	for(int i = 0; i < depth; i++) {
		for(auto j : graph[i])
			cout << j << " ";
		cout << '\n';
	}
}