/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 3986                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/3986                           #+#        #+#      #+#    */
/*   Solved: 2026/01/21 18:54:24 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

stack<char> st;

int N;
int totalSum;
bool flag = false;

int isGoodWord(const string &word) {
	st.push(word[0]);
	for(int i = 1; i < word.size(); i++) {
		if (!st.empty() && st.top() == word[i]) {
			st.pop();
		}
		else {
			st.push(word[i]);
		}
	}

	if (st.empty()) {
		return 0;
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	string tmp;

	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> tmp;

		if (tmp.length() % 2 != 0) continue;
		if (isGoodWord(tmp) >= 0) totalSum++;
		while(!st.empty()) {
			st.pop();
		}
	}

	cout << totalSum;
	return 0;
}