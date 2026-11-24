/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10813                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10813                          #+#        #+#      #+#    */
/*   Solved: 2026/03/10 10:13:37 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <algorithm>

using namespace std;

int map[102];

int main() {
	int N, M;
	cin >> N >> M;

	int i, j;
	for(int i = 1; i <= N; i++) {
		map[i] = i;
	}

	while(M--) {
		cin >> i >> j;
		swap(map[i], map[j]);
	}

	for(int i = 1; i <= N; i++) {
		cout << map[i] << " ";
	}
	cout << '\n';
}