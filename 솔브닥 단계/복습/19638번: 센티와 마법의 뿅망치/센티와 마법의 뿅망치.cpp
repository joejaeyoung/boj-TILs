/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 19638                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/19638                          #+#        #+#      #+#    */
/*   Solved: 2026/11/25 20:00:24 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, H, T;
    cin >> N >> H >> T;

    priority_queue<int> giants;
    for (int i = 0; i < N; ++i) {
        int height;
        cin >> height;
        giants.push(height);
    }

    int cnt = 0;
    while (cnt < T && giants.top() >= H && giants.top() > 1) {
        int tallest = giants.top();
        giants.pop();
        giants.push(tallest / 2);
        ++cnt;
    }

    if (giants.top() < H) {
        cout << "YES\n" << cnt << '\n';
    } else {
        cout << "NO\n" << giants.top() << '\n';
    }
}