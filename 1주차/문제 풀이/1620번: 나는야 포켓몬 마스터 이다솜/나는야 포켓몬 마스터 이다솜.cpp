/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1620                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1620                           #+#        #+#      #+#    */
/*   Solved: 2026/01/21 18:53:36 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string poketmons[100001];
map<string, int> mps;

int N_pokets;
int M_problems;

void solve(const string& in) {
	if (isalpha(in[0])) {	//이름 -> 숫자
		cout << mps[in] << '\n';
	}
	else {	//숫자 -> 이름
		cout << poketmons[atoi(in.c_str())] << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(0);

	string tmp;
	string in;
	cin >> N_pokets >> M_problems;

	for(int i = 0; i < N_pokets; i++) {
		cin >> tmp;
		poketmons[i + 1] = tmp;
		mps[tmp] = i + 1;
	}

	while(M_problems--) {
		cin >> in;
		solve(in);
	}

	return 0;
}