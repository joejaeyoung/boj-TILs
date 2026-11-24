/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2870                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2870                           #+#        #+#      #+#    */
/*   Solved: 2026/01/30 15:39:56 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
string in;
vector<int> v_int;
vector<string> v_str;


int find_number(int start) {
	for(int i = start; i < in.size(); i++) {
		if (!isalpha(in[i]))
			return i;
	}
	return -1;
}

int find_alpha(int start) {
	for(int i = start; i < in.size(); i++) {
		if (isalpha(in[i]))
			return i;
	}
	return -1;
}

void solve() {
	// cout << "=== " << in << " ===" << '\n';

	int start;
	int end;

	for(int i = 0; i < in.size(); i++) {
		start = find_number(i);
		end = find_alpha(start);
		// cout << i << " " << start << " : " << end << '\n';

		if (start == -1) return ;
		if (end == -1 && start != -1) {
			end = in.size();
		}

		bool flag = true;
		int tmp_start = start;
		// cout << "start : " << start << " end : " << end << '\n';
		for(int i = start; i < end - 1; i++) {
			if (in[i] == '0')
				start++;
			else
				break;
		}
		v_str.push_back(in.substr(start, end - start));
		i = end;
	}
}

bool compare(string &a, string &b) {
	if (a.size() > b.size()) return false;
	if (a.size() < b.size()) return true;

	if (strcmp(a.c_str(), b.c_str()) > 0)
		return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	cin >> n;

	while(n--) {
		cin >> in;
		solve();
	}

	sort(v_str.begin(), v_str.end(), compare);

	for(auto s : v_str) {
		cout << s << '\n';
	}
}