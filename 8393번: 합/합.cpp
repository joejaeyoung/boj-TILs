/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 8393                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/8393                           #+#        #+#      #+#    */
/*   Solved: 2026/03/04 17:16:59 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

using namespace std;

int n;

int main() {
	cin >> n;
	long long ret = 0;

	for(int i = 1; i <= n; i++)
		ret += i;
	cout << ret << '\n';
}