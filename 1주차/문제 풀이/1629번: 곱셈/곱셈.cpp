/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1629                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1629                           #+#        #+#      #+#    */
/*   Solved: 2026/01/21 18:54:31 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <cstring>

using namespace std;

typedef unsigned long long int ull;

ull A, B, C;

ull multiply(ull A, ull s) {
	if (s == 1) {
		return A % C;
	}

	ull ret = multiply(A, s / 2);
	ret = (ret * ret) % C;
	if (s & 1) ret = (ret * A) % C;
	return ret;
}


int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	string result;

	cin >> A >> B >> C;
	cout << multiply(A, B) << '\n';
}