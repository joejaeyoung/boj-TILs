/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10871                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10871                          #+#        #+#      #+#    */
/*   Solved: 2026/03/05 15:19:36 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

using namespace std;

int arr[10001];
int N, X;

int main() {
	cin >> N >> X;

	for(int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int tmp;
	for(int i = 0; i < N; i++) {
		tmp = arr[i];
		if (tmp < X) cout << tmp << " ";
	}
	cout << '\n';
}