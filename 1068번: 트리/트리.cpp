/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1068                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1068                           #+#        #+#      #+#    */
/*   Solved: 2026/02/02 19:07:29 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v[51];

int n;
int root_node;
int cnt;
int eraser;

void solve(int root) {
	if (root == eraser) return;

	if (v[root].size() == 0 || (v[root].size() == 1 && v[root][0] == eraser)) {
		cnt++;
		return ;
	}

	for(auto s : v[root]) {
		solve(s);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tmp;
	
	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> tmp;
		if (tmp == -1) {
			root_node = i;
			continue;
		}
		v[tmp].push_back(i);
	}

	cin >> eraser;

	solve(root_node);

	cout << cnt << '\n';

	// for(auto s : v) {
	// 	for(auto t : s) {
	// 		cout << t << " ";
	// 	}
	// 	cout << '\n';
	// }
}