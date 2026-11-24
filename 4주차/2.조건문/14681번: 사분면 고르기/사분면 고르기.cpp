/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 14681                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/14681                          #+#        #+#      #+#    */
/*   Solved: 2026/02/25 08:45:03 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int x, y;
	cin >> x >> y;

	if (x > 0 && y > 0) {
		cout << "1\n";
	}
	else if (x > 0 && y < 0) {
		cout << "4\n";
	}
	else if (x < 0 && y > 0) {
		cout << "2\n";
	}
	else {
		cout << "3\n";
	}
}