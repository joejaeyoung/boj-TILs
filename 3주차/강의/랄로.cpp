#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;

	int i = 2400;
	for(; ; i++) {
		if (to_string(i).find("2400") != string::npos) n--;
		if (n == 0) break;
	}
	cout << i << '\n';
}