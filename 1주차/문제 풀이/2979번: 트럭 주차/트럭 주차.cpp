/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2979                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2979                           #+#        #+#      #+#    */
/*   Solved: 2026/01/20 19:33:55 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[3][101];
int a, b, c;
int start_s, end_s;
int total = 0;
int cnt = 0;

int main(void)
{
	cin >> a >> b >> c;

	for(int i = 0; i < 3; i++) {
		cin >> start_s >> end_s;
		arr[i][start_s] = 1;
		arr[i][end_s] = 2;
	}

	for(int i = 1; i <= 100; i++) {
		for(int j = 0; j < 3; j++) {
			if (arr[j][i] == 0) continue;

			if (arr[j][i] == 1) cnt++;
			if (arr[j][i] == 2) cnt--;
		}

		if (cnt >= 1) {
			if (cnt == 3) {
				total += 3 * c;
				// cout << "c ";
			}
			if (cnt == 2) {
				total += 2 * b;
				// cout << "b ";
			}
			if (cnt == 1) {
				total += 1 * a;
				// cout << "a ";
			}
		}
	}

	cout << total << '\n';
}