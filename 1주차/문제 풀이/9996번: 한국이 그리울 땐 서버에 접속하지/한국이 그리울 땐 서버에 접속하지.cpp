/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9996                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9996                           #+#        #+#      #+#    */
/*   Solved: 2026/01/20 20:46:11 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
string pattern;
string in;

vector<string> split(const string &input, string deli) {
	vector<string> result;

	int start = 0;
	int end = input.find(deli);

	while(end != string::npos) {
		result.push_back(input.substr(start, end - start));
		start += end + deli.size();
		end = input.find(deli, start);
	}
	result.push_back(input.substr(start));
	return result;
}

int solve(const vector<string>& delis) {
	string head;
	string tail;

	if (delis.size() > 1) {
		int tail_start = in.size() - delis[1].size();
		if (tail_start < delis[0].size()) {
			return -1;
		}

		head = in.substr(0, delis[0].size());

		if (tail_start < 0) return -1;
		tail = in.substr(tail_start);

		// cout << "head : " << head << '\n';
		// cout << "tail : " << in.size() - delis[1].size() << " : "<< tail << '\n\n';

		if (head == delis[0] && tail == delis[1]) return 0;
		return -1;
	}
	else {
		if (in == delis[0]) return 0;
		else return -1;
	}
	return -1;
}

int main() {
	vector<string> delis;

	cin >> n;
	cin >> pattern;

	delis = split(pattern, "*");

	// for(string s : delis) {
	// 	cout << "delis : " << s << '\n';
	// }
	// cout << '\n';

	while(n--) {
		cin >> in;

		if (solve(delis) < 0) {
			cout << "NE" << '\n';
		}
		else {
			cout << "DA" << '\n';
		}
	}
	return 0;
}
