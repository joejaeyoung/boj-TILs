/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11655                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11655                          #+#        #+#      #+#    */
/*   Solved: 2026/01/20 20:28:47 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	string s;
	getline(cin, s);

	for(int i = 0; i < s.length(); i++) {
		if (isalpha(s[i])) {
			int c = s[i];
			c += 13;
			if ('A' <= s[i] && s[i] <= 'Z') {
				if (c > 'Z')
					c = c - 'Z' + 'A' - 1;
			}
			
			if ('a' <= s[i] && s[i] <= 'z') {
				// cout << (int)c << endl;
				if (c > 'z')
					c = c - 'z' + 'a' - 1;
			}
			s[i] = (char)c;
		}
	}

	cout << s;
}