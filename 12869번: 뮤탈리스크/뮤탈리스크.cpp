/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 12869                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/12869                          #+#        #+#      #+#    */
/*   Solved: 2026/02/10 18:04:58 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
3!
60 * 3!
60 * 2!
60
*/

int csv_num;
int tmp;

int mn_cnt = 1e7;
int cnt = 0;
int global_cnt = 0;

int attack[] = {9, 3, 1};
int csv[3];
vector<int> order;

void debug(vector<int> csv) {
	cout << "=== " << tmp << " : " << mn_cnt << " " << cnt << "\n";
	for(auto a : csv) {
		cout << a << " ";
	}
	cout << '\n';
}

void cal(vector<int> csv, int *cnt) {
	// debug(csv);

	//재귀 탈출
	if (csv.empty()) {
		// cout << "공격 끝 모두 죽음 : " << *cnt << '\n';
		global_cnt = *cnt;
		return ;
	}
	if (mn_cnt < *cnt) {
		global_cnt = *cnt;
		// cout << "이미 최소값 넘김\n";
		return ;
	}

	//공격 및 삭제
	vector<int> tmp_csv;
	int i;
	for(i = 0; i < csv.size(); i++) {
		csv[i] -= attack[i];
	}

	for(int j = 0; j < csv.size(); j++) {
		if (csv[j] > 0)
			tmp_csv.push_back(csv[j]);
	}

	csv = tmp_csv;
	sort(csv.begin(), csv.end());
	do {
		(*cnt)++;
		cal(csv, cnt);
		(*cnt)--;
	} while(next_permutation(csv.begin(), csv.end()));
}

int main() {
	int in = 0;
	cin >> csv_num;
	for(int i = 0; i < csv_num; i++) {
		cin >> csv[i];
		order.push_back(i);
	}

	tmp = 0;

	//첫 순열
	do {
		cnt = 0;
		cal(csv, &cnt);
		// cout << "mn : " << mn_cnt << "cal() : " << cnt << '\n';
		mn_cnt = min(mn_cnt, global_cnt);
	} while(next_permutation(order.begin(), order.end()));
	cout << mn_cnt << '\n';
}