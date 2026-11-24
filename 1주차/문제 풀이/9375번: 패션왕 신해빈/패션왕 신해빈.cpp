/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9375                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9375                           #+#        #+#      #+#    */
/*   Solved: 2026/01/21 18:53:54 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stdlib.h>
#include <cstring>

using namespace std;

int case_num, input_num;
map<string, int> mp;

int main(void) {
	ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	cin >> case_num;
	string a, b;
	while(case_num--) {
		cin >> input_num;
		for(int i = 0; i < input_num; i++) {
			cin >> a >> b;
			mp[b]++;
		}

		unsigned int total = 1;
		for(auto it : mp) {
			total *= (it.second + 1);
		}

		total--;

		cout << total << '\n';
		mp.clear();
	}


	return 0;
}