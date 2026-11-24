/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1159                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1159                           #+#        #+#      #+#    */
/*   Solved: 2026/01/20 20:04:48 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<int, int> mp;
int flag;

int main(void) {
	for(int i = 'a'; i <= 'z'; i++) {
		mp[i - 'a'] = 0;
	}

	int n;
	string s;
	cin >> n;
	while(n--) {
		cin >> s;
		mp[s[0] - 'a']++;
	}

	for(int i = 'a'; i <= 'z'; i++) {
		if (mp[i - 'a'] >= 5) {
			cout << (char)i;
			flag = 1;
		}
	}

	if (!flag) {
		cout << "PREDAJA";
	}
}