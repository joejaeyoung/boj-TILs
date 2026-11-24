/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1992                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1992                           #+#        #+#      #+#    */
/*   Solved: 2026/01/27 16:48:28 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int map[65][65];
int n;

int cnt = 0;

void leftParen() {
	if (cnt > 0) cout << "(";
}

void rightParen() {
	if (cnt > 0) cout << ")";
}

void solve(int ly, int lx, int ry, int rx) {
	cnt++;

	if (ly < 0 || lx < 0 || ry < 0 || rx < 0) return ;
	if (ly >= n || lx >= n || ry >= n || rx >= n) return ;
	if (ly > ry || lx > rx) return ;

	int zero = 0;
	int one = 0;

	if (n != 2) {
		for(int ty = ly; ty <= ry; ty++) {
			for(int tx = lx; tx <= rx; tx++) {
				if (map[ty][tx] == 1) one++;
				if (map[ty][tx] == 0) zero++;
			}
		}

		if (one > 0 && zero == 0) {
			cout << "1";
			return ;
		}
		if (one == 0 && zero > 0) {
			cout << "0";
			return ;
		}
	}

	if (ry - ly <= 1) {
		leftParen();
		for(int ty = ly; ty <= ry; ty++) {
			for(int tx = lx; tx <= rx; tx++) {
				cout << map[ty][tx];
			}
		}
		rightParen();
		return ;
	}

	leftParen();
	// printf("1. %d %d %d %d\n", ly, lx, ly + (ry - ly) / 2, lx + (rx - lx) / 2);
	solve(ly, lx, ly + (ry - ly) / 2, lx + (rx - lx) / 2);
	cnt--;

	// printf("2. %d %d %d %d\n", ly, lx + (rx - lx) / 2 + 1, ly + (ry - ly) / 2, rx);
	solve(ly, lx + (rx - lx) / 2 + 1, ly + (ry - ly) / 2, rx);
	cnt--;

	// printf("3. %d %d %d %d\n", ly + (ry - ly) / 2 + 1, lx, ry, lx + (rx - lx) / 2);
	solve(ly + (ry - ly) / 2 + 1, lx, ry, lx + (rx - lx) / 2);
	cnt--;

	// printf("4. %d %d %d %d\n", ly + (ry - ly) / 2 + 1, lx + (rx - lx) / 2 + 1, ry, rx);
	solve(ly + (ry - ly) / 2 + 1, lx + (rx - lx) / 2 + 1, ry, rx);
	cnt--;

	rightParen();
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	string s;
	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> s;

		for(int j = 0; j < s.size(); j++) {
			map[i][j] = s[j] - '0';
		}
	}
	solve(0, 0, n-1, n-1);
}