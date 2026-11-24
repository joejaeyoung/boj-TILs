/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1213                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1213                           #+#        #+#      #+#    */
/*   Solved: 2026/01/21 18:54:04 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;
map<int, int> mp;

string in;
string in_dup;

int odd_alpha = -1;
int length;

vector<char> result;

int is_palindrome() {
	if (in.size() % 2 == 0) {
		for(int i = 'A'; i <= 'Z'; i++) {
			if (mp[i] == 0) continue;
			
			if (mp[i] % 2 != 0) {
				return -1;
			}
			
			int num = mp[i] / 2;
			while(num--)
				result.push_back(i);
		}

		for(int i = 0; i < result.size(); i++) {
			cout << result[i];
		}

		for(int i = result.size() - 1; i >= 0; i--) {
			cout << result[i];
		}
	}
	else {
		int idx = 0;

		for(int i = 'A'; i <= 'Z'; i++) {
			if (mp[i] == 0) continue;

			if (mp[i] % 2 != 0) {
				odd_alpha = i;
				idx++;

				if (mp[i] > 1) {
					int num = mp[i] / 2;
					while(num--)
						result.push_back(i);
				}
			}
			else {
				int num = mp[i] / 2;
				while(num--)
					result.push_back(i);
			}
		}
		if (idx != 1) return -1;
		
		for(int i = 0; i < result.size(); i++) {
			cout << (char)result[i];
		}

		cout << (char)odd_alpha;

		for(int i = result.size() - 1; i >= 0; i--) {
			cout << (char)result[i];
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	cin >> in;
	in_dup = in;
	length = in.size();

	for(int i = 'A'; i <= 'Z'; i++) {
		mp[i] = 0;
	}
	for(int i = 0; i < in.size(); i++) {
		mp[in[i]]++;
	}

	if (is_palindrome() < 0) {
		cout << "I'm Sorry Hansoo" << '\n';
		return 0;
	}

	return 0;
}