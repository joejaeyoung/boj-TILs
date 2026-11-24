/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2562                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2562                           #+#        #+#      #+#    */
/*   Solved: 2026/03/10 10:09:03 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int idx = -1;
	int mx = -1;
	int tmp;

	for(int i = 1; i <= 9; i++) {
		cin >> tmp;
		if (tmp > mx) {
			idx = i;
			mx = tmp;
		}
	}
	cout << mx << '\n' << idx << '\n';
}