#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[101];
vector<int> rocks;
int n;

bool is_prime(int num) {
	if (n <= 1) return false;
	if (n == 2) return true;

	if (!(n & 1)) return false;
	for(int i = 2; i < num; i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

int make_combi(int num, int idx) {
	int ret = 0;

	if (rocks.size() == num) {
		int sum = 0;
		for(auto i : rocks) sum += i;

		if (is_prime(sum)) {
			return 1;
		}
		return 0;
	}

	for(int i = idx; i < n; i++) {
		rocks.push_back(arr[i]);
		ret += make_combi(num, i + 1);
		rocks.pop_back();
	}
	return ret;
}

int main() {
	int ret = 0;
	int tmp;
	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for(int i = 1; i <= n; i++) {
		tmp = make_combi(i, 0);
		cout << i << " : " << tmp << '\n';
		ret += tmp;
	}
	cout << ret << '\n';
}