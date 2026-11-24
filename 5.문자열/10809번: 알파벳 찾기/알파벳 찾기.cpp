/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10809                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10809                          #+#        #+#      #+#    */
/*   Solved: 2026/03/10 10:40:33 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int map['z' - 'a' + 1];

int main() {
	string s;
	cin >> s;
	memset(map, -1, sizeof(map));

	for(int i = 0; i < s.length(); i++) {
		if (map[s[i] - 'a'] == -1) {
			map[s[i] - 'a'] = i;
		}
	}

	for(auto i : map) cout << i << " ";
	cout << '\n';
}