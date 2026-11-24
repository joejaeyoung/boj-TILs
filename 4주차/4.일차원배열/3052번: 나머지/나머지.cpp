/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 3052                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/3052                           #+#        #+#      #+#    */
/*   Solved: 2026/03/10 10:18:28 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

set<int> s;
int main() {
	int tmp;
	for(int i = 0; i < 10; i++) {
		cin >> tmp;
		s.insert(tmp % 42);
	}
	cout << s.size() << '\n';
}