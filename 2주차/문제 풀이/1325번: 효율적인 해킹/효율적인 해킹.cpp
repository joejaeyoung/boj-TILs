/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1325                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1325                           #+#        #+#      #+#    */
/*   Solved: 2026/02/02 19:07:54 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
int n, m;
int cnt;

vector<int> v[10001];
vector<pair<int, int>> ret;
int visited[10001];

void traversal(int root) {
	if (visited[root]) return ;

	visited[root] = 1;
	cnt++;
	if (v[root].size() == 0) return ;

	for(auto s : v[root]) {
		traversal(s);
	}
}

bool comp(pair<int, int> &a, pair<int, int> &b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second > b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	int a, b;

	while(m--) {
		cin >> a >> b;
		if (a == b)
			v[b].push_back(n + 1);
		else
			v[b].push_back(a);
	}

	for(int i = 1; i <= n; i++) {
		traversal(i);

		ret.push_back({i, cnt});
		cnt = 0;
		memset(visited, 0, sizeof(visited));
	}

	sort(ret.begin(), ret.end(), comp);

	// for(auto s : ret) {
	// 	cout << s.first << " " << s.second << '\n';
	// }

	int max_num = ret[0].second;
	for(auto s : ret) {
		if (s.second == max_num)
			cout << s.first << " ";
		else break;
	}
	return 0;
}