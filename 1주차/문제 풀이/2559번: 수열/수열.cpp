/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2559                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2559                           #+#        #+#      #+#    */
/*   Solved: 2026/01/21 18:53:22 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>

#define INT_MIN -2147483648

using namespace std;

int arr[100001];
int psum[100001];
int num, ran, tmp;

int solve() {
	int sum_max = INT_MIN;
	int sum = 0;

	for(int i = ran; i <= num; i++) {
		sum_max = max(sum_max, psum[i] - psum[i-ran]);
	}
	return sum_max;
}

int main() {
	cin >> num >> ran;

	for(int i = 1; i <= num; i++) {
		cin >> arr[i];
		psum[i] = psum[i - 1] + arr[i];
	}

	cout << solve();

	return 0;
}