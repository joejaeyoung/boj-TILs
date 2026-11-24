/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2753                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2753                           #+#        #+#      #+#    */
/*   Solved: 2026/02/25 08:44:56 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int year;
	cin >> year;

	if ((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0))) {
		cout << "1\n";
	}
	else {
		cout << "0\n";
	}
}