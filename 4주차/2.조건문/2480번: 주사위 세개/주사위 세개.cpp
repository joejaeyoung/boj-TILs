/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2480                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2480                           #+#        #+#      #+#    */
/*   Solved: 2026/02/25 08:45:17 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <algorithm>

using namespace std;

int arr[6];
int mx;

int main() {
	int cnt = 0;
	int s_num = 0;
	int a, b, c;
	cin >> a >> b >> c;

	mx = max(a, mx);
	mx = max(b, mx);
	mx = max(c, mx);

	if ((a == b) && (b == c) && (a == c)) {
		cout << 10000 + a * 1000 << '\n';
		return 0;
	}

	if ((a != b) && (b != c) && (a != c)) {
		cout << mx * 100 << '\n';
		return 0;
	}

	if (a == b) {
		cnt = 2;
		s_num = a;
	}
	if (b == c) {
		cnt++;
		s_num = b;
	}
	if (a == c) {
		cnt++;
		s_num = c;
	}

	cout << 1000 + s_num * 100 << '\n';
}