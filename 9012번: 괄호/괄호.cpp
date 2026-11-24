/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9012                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9012                           #+#        #+#      #+#    */
/*   Solved: 2026/02/02 15:36:18 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;

int n;
stack<char> st;
string in;

bool solve() {
	cin >> in;

	for(int i = 0; i < in.size(); i++) {
		if (in[i] == '(') st.push(in[i]);
		else if (st.size()) st.pop();
		else return false;
	}

	if (st.size()) return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	while(n--) {
		if (solve())
			cout << "YES\n";
		else
			cout << "NO\n";
		while(st.size()) st.pop();
	}
}