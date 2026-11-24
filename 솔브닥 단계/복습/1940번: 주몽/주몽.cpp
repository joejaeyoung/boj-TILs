/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1940                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1940                           #+#        #+#      #+#    */
/*   Solved: 2026/11/24 10:45:17 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int m, n;

int arr[15001];
int ret;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	cin >> m;

	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for(int i = 0; i < n ; i++) {
		for (int j = i + 1; j < n; j++) {
			if (m == (arr[i] + arr[j])) {
				ret ++;
			}
		}
	}

	cout << ret << '\n';

}