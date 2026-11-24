/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 17298                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/17298                          #+#        #+#      #+#    */
/*   Solved: 2026/02/02 19:08:02 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <stack>
#include <cstring>

using namespace std;

int arr[1000001];
int dp[1000001];
stack<pair<int, int>> st;
int n, tmp;
pair<int, int> t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(dp, -1, sizeof(dp));

	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> tmp;

		while(st.size()) {
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