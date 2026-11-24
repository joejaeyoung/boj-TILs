/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1008                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1008                           #+#        #+#      #+#    */
/*   Solved: 2026/01/21 18:58:31 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	long double a, b;
	cin >> a >> b;

	cout << fixed;
	cout.precision(15);

	cout << a / b;
}