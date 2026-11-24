/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11720                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11720                          #+#        #+#      #+#    */
/*   Solved: 2026/03/10 10:39:07 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main () {
	int n;
	cin >> n;

	string s;
	cin >> s;

	long long sum = 0;
	for(int i = 0; i < n; i++) {
		sum += (s[i] - '0');
	}
	cout << sum << '\n';
}