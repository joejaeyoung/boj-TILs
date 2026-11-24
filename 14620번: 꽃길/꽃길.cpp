/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 14620                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/14620                          #+#        #+#      #+#    */
/*   Solved: 2026/02/11 20:39:20 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int map[11][11];
int n;
int mn = 1e7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	for(int i = 0; i < n * n; i++) {
		for(int j = 0; j < i; j++) {
			for(int k = 0; k < j; k++) {
				int money = 0;

				//1. 경계값
				if ((i/n - 1) < 0 || (i/n + 1) >= n) continue;
				if ((i%n - 1) < 0 || (i%n + 1) >= n) continue;

				if ((j/n - 1) < 0 || (j/n + 1) >= n) continue;
				if ((j%n - 1) < 0 || (j%n + 1) >= n) continue;

				if ((k/n - 1) < 0 || (k/n + 1) >= n) continue;
				if ((k%n - 1) < 0 || (k%n + 1) >= n) continue;

				//2. 겹침
				if (abs(i/n - j/n) + abs(i%n - j%n) < 3) continue;
				if (abs(i/n - k/n) + abs(i%n - k%n) < 3) continue;
				if (abs(k/n - j/n) + abs(k%n - j%n) < 3) continue;

				// cout << i / n << "_" << i % n;
				// cout << " : " << j / n << "_" << j % n;
				// cout << " : " << k / n << "_" << k % n << '\n';
				//상하좌우 똑바로...? 
				money += (map[i/n][i%n] + map[i/n-1][i%n] + map[i/n+1][i%n] + map[i/n][i%n+1] + map[i/n][i%n -1]);
				money += (map[j/n][j%n] + map[j/n-1][j%n] + map[j/n+1][j%n] + map[j/n][j%n+1] + map[j/n][j%n -1]);
				money += (map[k/n][k%n] + map[k/n-1][k%n] + map[k/n+1][k%n] + map[k/n][k%n+1] + map[k/n][k%n -1]);
				// cout << money << '\n';
				mn = min(mn, money);
			}
		}
	}
	cout << mn << '\n';
}