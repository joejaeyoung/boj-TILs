/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9086                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9086                           #+#        #+#      #+#    */
/*   Solved: 2026/03/10 10:37:03 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	string s;
	int t;

	cin >> t;
	while(t--) {
		cin >> s;
		cout << s[0] << s[s.length() - 1] << '\n';
	}
}