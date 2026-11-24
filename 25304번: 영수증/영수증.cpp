/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 25304                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/25304                          #+#        #+#      #+#    */
/*   Solved: 2026/03/04 17:17:55 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

using namespace std;

int main () {
	int total = 0;
	int total_cal = 0;
	int test_cnt;
	int price, cnt;

	cin >> total;
	cin >> test_cnt;
	while(test_cnt--) {
		cin >> price >> cnt;
		total_cal += (price * cnt);
	}

	if (total == total_cal)
		cout << "Yes\n";
	else
		cout << "No\n";
}