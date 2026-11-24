#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v = {1, 2, 3};

    do {
        for(int a : v) cout << a << " ";
        cout << '\n';
    } while(next_permutation(v.begin(), v.end()));

}
