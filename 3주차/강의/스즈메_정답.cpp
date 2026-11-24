#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[101];
vector<int> rocks;
int n;

int is_prime(int num) {
	if (n <= 1) return 0;
	if (n == 2) return 1;

	if (!(n & 1)) return 0;
	for(int i = 2; i * i <= num; i++) {
		if (num % i == 0) {
			return 0;
		}
	}
	return 1;
}

int go(int idx, int sum) {
	if (idx == n) {
		return is_prime(sum);
	}
	return go(idx + 1, sum + arr[idx]) + go(idx + 1, sum);
}

int main() {
	int ret = 0;
	int tmp;
	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cout << go(0, 0) << '\n';
;}