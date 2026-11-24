/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10818                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10818                          #+#        #+#      #+#    */
/*   Solved: 2026/03/10 10:05:42 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	int mn = 1000002;
	int mx = -1000002;
	int tmp;
	for(int i = 0; i < n; i++) {
		cin >> tmp;

		mn = min(mn, tmp);
		mx = max(mx, tmp);
	}
	cout << mn << " " << mx << '\n';
}