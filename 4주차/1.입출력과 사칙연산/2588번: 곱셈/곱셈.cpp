/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2588                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2588                           #+#        #+#      #+#    */
/*   Solved: 2026/02/25 08:35:47 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int num, a, tmp, b;
	cin >> num >> a;
	b = a;

	while(a) {
		tmp = a % 10;

		cout << num * tmp << '\n';
		a /= 10;
	}
	cout << num * b << '\n';
}