/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 5597                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/5597                           #+#        #+#      #+#    */
/*   Solved: 2026/03/10 10:15:52 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <algorithm>

using namespace std;

int students[31];

int main() {
	int tmp;

	for(int i = 1; i <= 28; i++) {
		cin >> tmp;
		students[tmp] = 1;
	}

	for(int i = 1; i <= 30; i++) {
		if (!students[i]) {
			cout << i << '\n';
		}
	}
}