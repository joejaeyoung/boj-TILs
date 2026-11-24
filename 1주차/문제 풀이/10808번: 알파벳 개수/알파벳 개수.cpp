/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10808                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10808                          #+#        #+#      #+#    */
/*   Solved: 2026/01/20 19:12:59 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stdlib.h>
#include <string.h>

using namespace std;

char in[101];
map<int, int> mp;

int main(void) {
	cin >> in;

	for(int i = 'a'; i <= 'z'; i++) {
		mp[i] = 0;
	}

	for(int i = 0; i < strlen(in); i++) {
		mp[in[i]]++;
	}

	for(int i = 'a'; i <= 'z'; i++) {
		cout << mp[i] << " ";
	}

	cout << '\n';
}