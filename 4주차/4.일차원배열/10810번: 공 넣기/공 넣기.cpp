/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10810                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10810                          #+#        #+#      #+#    */
/*   Solved: 2026/03/10 10:11:14 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <algorithm>

using namespace std;

int map[102];

int main() {
	int N, M;
	cin >> N >> M;

	int i, j, k;
	while(M--) {
		cin >> i >> j >> k;

		for(int idx = i; idx <= j; idx++) {
			map[idx] = k;
		}
	}

	for(int i = 1; i <= N; i++) {
		cout << map[i] << " ";
	}
	cout << '\n';
}