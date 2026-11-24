/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 18108                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/18108                          #+#        #+#      #+#    */
/*   Solved: 2026/02/25 08:30:19 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int year;
	cin >> year;

	cout << year - (2541 - 1998) << '\n';
}