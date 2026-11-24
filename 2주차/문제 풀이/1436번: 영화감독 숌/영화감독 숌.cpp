/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1436                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1436                           #+#        #+#      #+#    */
/*   Solved: 2026/02/02 15:29:27 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;

	int i = 666;
	for( ; ; i++) {
		if (to_string(i).find("666") != string::npos) {
			n--;
		}
		if (n == 0) break;
	}
	cout << i << '\n';
}