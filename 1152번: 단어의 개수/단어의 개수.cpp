/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1152                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1152                           #+#        #+#      #+#    */
/*   Solved: 2026/03/10 10:47:49 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	string s;

	getline(cin, s);
	int cnt = 0;
	for(int i = 0; i < s.size(); i++) {
		if (i == 0 || i == s.size() - 1) continue;
		if (s[i] == ' ') cnt++;
	}
	cout << cnt + 1;
}