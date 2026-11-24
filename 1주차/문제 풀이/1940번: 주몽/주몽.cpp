/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1940                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1940                           #+#        #+#      #+#    */
/*   Solved: 2026/01/21 18:54:16 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int arr[15001];
int totalSum;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	cin >> N >> M;

	for(int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < i; j++) {
			if (M == (arr[i] + arr[j]))
				totalSum++;
		}
	}

	cout << totalSum;
}