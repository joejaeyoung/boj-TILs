/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 4659                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/4659                           #+#        #+#      #+#    */
/*   Solved: 2026/01/30 15:26:36 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

string in;

void print_not() {
	cout << "<" << in << ">" << " is not acceptable.\n";
}

void print_good() {
	cout << "<" << in << ">" << " is acceptable.\n";
}

bool is_gather(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return true;
	return false;
}

void solve() {
	int a_count = 0;
	int b_count = 0;

	int gather_count = 0;
	int consonant_count = 0;

	for(char c : in) {
		//1. 모음 하나를 반드시 포함하여야 한다.
		if (is_gather(c))
			a_count++;

		//2. 모음이 3개 혹은 자음이 3개 연속으로 오면 안된다.
		if (is_gather(c)) {
			gather_count++;
			consonant_count = 0;
		}
		else {
			consonant_count++;
			gather_count = 0;
		}

		if (gather_count >= 3 || consonant_count >= 3) {
			print_not();
			return ;
		}

		//3. 같은 글자가 연속적으로 두번 오면 안되나 (ee, oo 예외))
		if (b_count == (int)c) {
			if (c == 'e' || c == 'o') continue;
			print_not();
			return ;
		}

		b_count = c;
	}

	if (a_count <= 0) {
		print_not();
		return ;
	}
	print_good();
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	while(1) {
		cin >> in;

		if (in == "end") break;

		solve();
	}

	return 0;
}