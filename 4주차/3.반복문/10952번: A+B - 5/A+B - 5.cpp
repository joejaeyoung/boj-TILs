/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10952                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10952                          #+#        #+#      #+#    */
/*   Solved: 2026/03/05 15:09:01 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

using namespace std;

int main() {
	bool flag = true;

	do {
		int a, b;
		cin >> a >> b;
		if (a == 0 && b == 0) return 0;
		cout << a + b << '\n';
	} while(1);
}