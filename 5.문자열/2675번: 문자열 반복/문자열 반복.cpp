/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2675                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2675                           #+#        #+#      #+#    */
/*   Solved: 2026/03/10 10:45:00 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int tc;
	cin >> tc;

	while(tc--) {
		int n; 
		string s;
		cin >> n >> s;

		for(int i = 0; i < s.length(); i++) {
			for(int k = 0; k < n; k++) {
				cout << s[i];
			}
		}
		cout << '\n';
	}

}