/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 16637                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: ggul_pooh <boj.kr/u/ggul_pooh>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/16637                          #+#        #+#      #+#    */
/*   Solved: 2026/02/11 18:18:03 by ggul_pooh     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int op_cnt;
char in[20];
vector<char> line;
long long ret = -2147483648;
vector<int> combi;
queue<int> q;
int combi_idx;

long long sub_cal() {
	int num1 = q.front() - '0'; q.pop();;
	char op = q.front(); q.pop();
	int num2 = q.front() -'0'; q.pop();
	q.front(); q.pop();	//right paren

	switch(op) {
		case '+':
			return num1 + num2;
		case '*':
			return num1 * num2;
		case '-':
			return num1 - num2;
	}
	return 0;
}

void debug() {
	cout << "=== cal ===\n";
	cout << "combination : ";
	for(int a : combi) {	
		cout << a;
	}
	cout << '\n';

	cout << "q : ";
	int num = q.size();
	while (num--) {
		cout << (char)q.front();
		q.push(q.front());
		q.pop();
	}
	cout << '\n';
}

long long cal() {
	char op = 0;
	char num;
	long long cal_ret = 0;

	// debug();
	while(q.size()) {
		if (op == 0) {
			num = q.front(); q.pop();
			cal_ret = num -'0';
		}

		op = q.front(); q.pop();
		num = q.front(); q.pop();
		if (num == '(')
			num = sub_cal();
		else
			num = num - '0';
		switch(op) {
			case '+':
				cal_ret += num;
				break;
			case '*':
				cal_ret *= num;
				break;
			case '-':
				cal_ret -= num;
				break;
		}
	}
	// cout << "cal_ret : " << cal_ret << "\n\n";
	return cal_ret;
}

void make_combination(int n, int r, int idx) {
	if (combi.size() == r) {
		combi_idx = 0;

		bool is_first = true;
		for(int i = 0; i < op_cnt; i++) {
			//1. 첫 숫자
			if (is_first) {
				q.push(in[2 * i]);
				is_first = false;
			}

			int paren_op_idx;
			if (combi.size() && (paren_op_idx = combi[combi_idx])) {
				q.push(in[2 * i + 1]);	//operator
				if (i + 1 == paren_op_idx) {
					q.push('(');
				}
				q.push(in[2 * i + 2]);	//operand
				if (i == paren_op_idx) {
					q.push(')');
					combi_idx++;
				}
				// line.push_back(in[2 * i]);
				// line.push_back(in[2 * i + 1]);
			}
			else {
				//2. operator, operand
				q.push(in[2 * i + 1]);
				q.push(in[2 * i + 2]);
			}
			
		}
		ret = max(ret, cal());
		while(q.size()) q.pop();
		return ;
	}

	for(int i = idx + 1; i < op_cnt; i++) {
		if (combi.size() && (combi[combi.size() - 1] + 1 == i)) {	//인접 건너뜀
			continue;
		}
		combi.push_back(i);
		make_combination(n, r, i);
		combi.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n; op_cnt = n / 2;

	string tmp;
	cin >> tmp;
	for(int i = 0; i < n; i++) {
		in[i] = tmp[i];
	}

	if (n == 1) {
		cout << in[0];
		return 0;
	}

	for(int i = 0; i <= op_cnt / 2; i++) {
		make_combination(op_cnt, i, 0);
		combi.clear();
	}
	cout << ret << '\n';
}