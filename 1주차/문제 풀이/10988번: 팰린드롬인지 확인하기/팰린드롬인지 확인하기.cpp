/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10988                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10988                          #+#        #+#      #+#    */
/*   Solved: 2026/01/20 19:58:34 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main(void) {
	string a, b;

	cin >> a;
	b = a;
	
	reverse(a.begin(), a.end());

	if (a == b)
		cout << 1;
	else
		cout << 0;
	return 0;
}