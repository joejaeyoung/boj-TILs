/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10807                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10807                          #+#        #+#      #+#    */
/*   Solved: 2026/03/05 15:14:08 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

using namespace std;

int arr[300];
int num, tmp, fin;

int main() {
	cin >> num;

	while(num--) {
		cin >> tmp;
		arr[tmp + 100]++;
	}
	cin >> fin;
	cout << arr[fin + 100];
}
