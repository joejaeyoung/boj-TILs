#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[101];
int n;
int mx;

void go(int idx, int sum) {
	if (idx == n) {
		mx = max(sum % 11, mx);
		return ;
	}

	go(idx + 1, sum + arr[idx]);
	go(idx + 1, sum);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 

	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	go(0, 0);
	cout << mx << '\n';
}