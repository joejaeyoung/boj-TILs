/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1546                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1546                           #+#        #+#      #+#    */
/*   Solved: 2026/03/10 10:23:15 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int scores[1001];
int mx = -1;

int main() {
	int N;
	int tmp;
	double score;
	double sum = 0;

	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> scores[i];
		mx = max(scores[i], mx);
	}


	for(int i = 0; i < N; i++) {
		score = (double)scores[i];
		sum += (score / mx * 100);
	}

	// cout << fixed << setprecision(14);
	cout << (double)sum / N;
}