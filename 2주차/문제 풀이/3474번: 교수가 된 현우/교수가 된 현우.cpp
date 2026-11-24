/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 3474                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/3474                           #+#        #+#      #+#    */
/*   Solved: 2026/02/02 14:03:13 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

long long n;
vector<long long> v;
long long num_5, num_2;
long long in, tmp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> in;
		
		for(int j = 2; j <= in; j *= 2)
			num_2 += in / j;

		for(int j = 5; j <= in; j *= 5) {
			num_5 += in / j;
		}
		cout << min(num_2, num_5) << '\n';
		num_2 = num_5 = 0;
	}
}