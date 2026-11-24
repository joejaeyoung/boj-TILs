#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];
int arr_sum[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n = 0; int seq = 0;
	cin >> n >> seq;

	int ret = -999999;

	for(int i = 0; i < n; i++) {
		cin >> arr[i];
		if (i == 0) {
			arr_sum[0] = arr[0];
		}
		else {
			arr_sum[i] = arr[i] + arr_sum[i - 1];
		}
	}

	ret = arr_sum[seq - 1];
	int tmp_sum;
	for(int i = 0; i < n - seq; i++) {
		tmp_sum = arr_sum[i + seq] - arr_sum[i];
		ret = max(tmp_sum, ret);
	}	

	cout << ret << '\n';
	// 코드 작성
	return 0;
}