/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2828                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2828                           #+#        #+#      #+#    */
/*   Solved: 2026/01/27 18:28:53 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int n, m, j;
int ret;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	cin >> n >> m;
	cin >> j;

	int l = 0, r = m - 1;
	int idx;
	int tmp;

	while (j--) {
		tmp = 0;
		cin >> idx;
		idx--;


		//겹침
		if (l <= idx && idx <= r) {
			continue ;
		}
		//오른쪽 이동
		else if (r < idx) {
			tmp = idx - r;
			ret += tmp;
			r = idx;
			l += tmp;
		}
		//왼쪽 이동
		else if (idx < l) {
			tmp = l - idx;
			ret += tmp;
			l = idx;
			r -= tmp;
		}
		// cout << "distance : " << tmp << " l : " << l << " r : " << r << '\n';
	}
	cout << ret << '\n';
}