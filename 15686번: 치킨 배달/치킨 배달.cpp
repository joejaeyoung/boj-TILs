/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 15686                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/15686                          #+#        #+#      #+#    */
/*   Solved: 2026/02/09 14:48:35 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>

using namespace std;
int n, m;

int map[51][51];

vector<pair<int, int>> houses;
vector<pair<int, int>> chicken;
vector<pair<int, int>> cur_chicken;
int ret_dis = 1e7;

void make_chicken(int idx, int num) {
	int city_dis;
	int house_dis;
	if (cur_chicken.size() == num) {
		city_dis = 0;
		for(auto house : houses) {
			house_dis = 1e7;
			//집과 치킨집 거리
			for(auto c : cur_chicken) {
				house_dis = min(house_dis, abs(c.first - house.first) + abs(c.second - house.second));
			}
			//도시의 치킨 거리
			city_dis += house_dis;
			
			// if (ret_dis != 1e7 && city_dis > ret_dis) return ;
		}

		// cout << "num : " << num << " dis : " << city_dis << '\n';

		ret_dis = min(ret_dis, city_dis);
		return ;
	}

	for(int i = idx + 1; i < chicken.size(); i++) {
		pair<int, int> tmp = chicken[i];
		cur_chicken.push_back(tmp);
		make_chicken(i, num);
		cur_chicken.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int tmp;
	cin >> n >> m;
	for(int h = 0; h < n; h++) {
		for(int w = 0; w < n; w++) {
			cin >> tmp;
			map[h][w] = tmp;
			if (tmp == 1) {
				houses.push_back({h, w});
			}
			else if (tmp == 2) {
				chicken.push_back({h, w});
				map[h][w] = 0;
			}
		}
	}

	for(int i = m; i >= 1; i--)
		make_chicken(-1, i);

	cout << ret_dis << '\n';
}