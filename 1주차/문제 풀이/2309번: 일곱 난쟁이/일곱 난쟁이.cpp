/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2309                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2309                           #+#        #+#      #+#    */
/*   Solved: 2026/01/20 18:07:21 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;

vector<int> v;
int psum[10];

int tmp;
int total = 100;
int idx = 0;

void solve(vector<int> &result, int idx, int depth) {
	if (result.size() == 8 && psum[depth - 1] == 100) {
		for(int i = 1; i < 8; i++)
			cout << result[i] << '\n';
		exit(0);
	}

	for(int i = idx; i < 10; i++) {
		psum[depth] = psum[depth - 1] + v[i];
		result.push_back(v[i]);
		solve(result, i + 1, depth + 1);
		result.pop_back();
		psum[depth] = 0;
	}
}

int main() {
	vector<int> result;

	psum[0] = 0;
	v.push_back(0);
	result.push_back(0);

	for (int i = 1; i < 10; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	solve(result, 1, 1);
}