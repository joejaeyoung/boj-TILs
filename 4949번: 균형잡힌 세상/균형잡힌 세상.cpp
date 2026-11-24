/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 4949                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/4949                           #+#        #+#      #+#    */
/*   Solved: 2026/02/02 15:47:41 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

stack<int> st1;
bool flag;
string s, tmp;

bool solve() {
	for(int i = 0; i < s.size(); i++) {
		if (s[i] == '[') st1.push(1);
		else if (s[i] == ']') {
			if (st1.empty()) return false;
			else if (st1.top() == 1) st1.pop();
			else return false;
		}

		if (s[i] == '(') st1.push(2);
		else if (s[i] == ')') {
			if (st1.empty()) return false;
			else if (st1.top() == 2) st1.pop();
			else return false;
		}
	}

	if (st1.size() == 0) return true;
	else return false;
}

int main() {
	getline(cin, s, '\n');
	// cin >> tmp;
	// cout << "===" << s << "===\n";

	while(s != ".") {
		if (solve()) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}

		while(st1.size()) st1.pop();

		getline(cin, s, '\n');
		// cin >> tmp;
		// cout << "===" << s << "===\n";
	}
}