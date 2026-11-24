/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10811                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10811                          #+#        #+#      #+#    */
/*   Solved: 2026/03/10 10:20:26 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <algorithm>

using namespace std;

int baskets[101];

int main() {
	int N, M;
	cin >> N >> M;

	for(int i = 1; i <= N; i++)
		baskets[i] = i;

	int i, j;
	while(M--) {
		cin >> i >> j;

		while(i < j) {
			swap(baskets[i], baskets[j]);
			i++;
			j--;
		}
	}

	for(int i = 1; i <= N; i++)
		cout << baskets[i] << " ";
}