/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10430                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10430                          #+#        #+#      #+#    */
/*   Solved: 2026/02/25 08:32:02 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int a, b, c;

	cin >> a >> b >> c;

	cout << (a + b) % c << '\n';
	cout << ((a % c) + (b % c)) % c << '\n';
	cout << (a * b) % c << '\n';
	cout << ((a % c) * (b % c)) % c << '\n';
}