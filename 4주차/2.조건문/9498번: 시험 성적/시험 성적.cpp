/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9498                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9498                           #+#        #+#      #+#    */
/*   Solved: 2026/02/25 08:44:43 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int s;
	cin >> s;

	if (s >= 90) {
		cout << "A\n";
	}
	else if (s >= 80) {
		cout << "B\n";
	}
	else if (s >= 70) {
		cout << "C\n";
	}
	else if (s >= 60) {
		cout << "D\n";
	}
	else {
		cout << "F\n";
	}
}