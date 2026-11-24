/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 4949                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/4949                           #+#        #+#      #+#    */
/*   Solved: 2026/11/24 11:04:20 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <string>


using namespace std;

stack<int> st;
string s;

bool solve() {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			st.push(1);
		}
		if (s[i] == '[') {
			st.push(2);
		}

		if (s[i] == ')' || s[i] == ']') {
			if (st.size()) {
				if (s[i] == ')') {
					if (st.top() == 1) st.pop();
					else return false;
				}
				if (s[i] == ']') {
					if (st.top() == 2) st.pop();
					else return false;
				}
			}
			else {
				return false;;
			}
		}
	}

	if (st.size() == 0) return true;

	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	getline(cin, s, '\n');

	while (s != ".") {
		if (solve()) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}

		while(st.size()) st.pop();
		getline(cin, s, '\n');
	}


}