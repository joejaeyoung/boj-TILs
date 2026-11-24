/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 4375                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/4375                           #+#        #+#      #+#    */
/*   Solved: 2026/01/21 18:54:40 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

typedef long long ll;

using namespace std;

int n;

int main() {
	while (scanf("%d", &n) != EOF) {
		ll cnt = 1, ret = 1;
		while(true) {
			if(cnt % n == 0) {
				printf("%lld\n", ret);
				break;
			}
			else {
				cnt = (cnt * 10) + 1;
				cnt %= n;
				ret++;
			}
		}
	}
}