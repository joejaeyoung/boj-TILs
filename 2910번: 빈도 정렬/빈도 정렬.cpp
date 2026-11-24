/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2910                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2910                           #+#        #+#      #+#    */
/*   Solved: 2026/01/29 19:29:29 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

typedef struct {
	int count;
	int rank;
} num;

int n, c;

map<int, num> mp;

bool cmp(const pair<int, num>&a, const pair<int, num>&b) {
	if (a.second.count > b.second.count) return a.first > b.first;
	if (b.second.count > a.second.count) return b.first > a.first;

	if (a.second.rank > b.second.rank) return a.first < b.first;
	return b.first < a.first;
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	cin >> n >> c;

	int tmpNum;
	for(int i = 0; i < n; i++) {
		cin >> tmpNum;
		auto it = mp.find(tmpNum);
		if (it == mp.end()) {
			num n;
			n.count = 1;
			n.rank = i;
			mp[tmpNum] = n;
		}
		else {
			it->second.count++;
		}
	}

	vector<pair<int, num>> v(mp.begin(), mp.end());

	stable_sort(v.begin(), v.end(), cmp);

	for(auto it : v) {
		for(int i = 0; i < it.second.count; i++)
			cout << it.first << " ";
	}
}