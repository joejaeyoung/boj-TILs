/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2529                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2529                           #+#        #+#      #+#    */
/*   Solved: 2026/02/11 20:39:02 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n;
vector<char> oper;
vector<int> numbers = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
vector<int> arr;
string mn = "9876543210";
string mx = "000000000";

bool is_valid(vector<int> &line) {
	bool flag = true;
	for(int i = 0; i < n; i++) {
		if (oper[i] == '<') {
			if (line[i] > line[i + 1]) {
				flag = false;
				break ;
			}
		}
		else {
			if (line[i] < line[i + 1]) {
				flag = false;
				break;
			}
		}
	}
	return flag;
}

int main() {
	char c_tmp;
	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> c_tmp;
		oper.push_back(c_tmp);
	}

	do {
		vector<int> tmp_ret(numbers.begin(), numbers.begin() + n + 1);

		if (is_valid(tmp_ret)) {
			string tmp;
			for(auto item : tmp_ret) {
				tmp += (char)'0' + item;
			}

			// for(auto i : tmp_ret) cout << i;
			// cout << '\n';
			// cout << "tmp : " << tmp << '\n';
			if (atoll(tmp.c_str()) < atoll(mn.c_str()))
				mn = tmp;
			if (atoll(tmp.c_str()) > atoll(mx.c_str()))
				mx = tmp;
		}
	}while(next_permutation(numbers.begin(), numbers.end()));

	cout << mx << '\n';
	cout << mn << '\n';

}