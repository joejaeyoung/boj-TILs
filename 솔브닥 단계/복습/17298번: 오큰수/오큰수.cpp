/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 17298                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/17298                          #+#        #+#      #+#    */
/*   Solved: 2026/11/24 11:12:56 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <algorithm>
#include <stack>
#include <cstring>

using namespace std;

stack<pair<int, int>> st;
int dp[1000001];
int n;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	memset(dp, -1, sizeof(dp));

	cin >> n;

	int tmp;
	pair<int, int> t;

	for(int i = 0; i < n; i++) {
		cin >> tmp;
		while(!st.empty()) {
			t = st.top();

			if (tmp > t.second) {
				dp[t.first] = tmp;
				st.pop();
			}
			else {
				break;
			}
		}
		st.push({i, tmp});
	}

	for(int i = 0; i < n; i++) {
		cout << dp[i] << " ";
	}
	cout << '\n';
}
