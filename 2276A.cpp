#include <iostream>
using namespace std;

void solve() {
	int a, b;
	cin >> a >> b;
	if (a <= b) {
		cout << -1 << endl;
		return;
	}

	if (b * 2 <= a) {
		cout << b << endl;
		return;
	}

	int res = a % b;
	if (res == 0) {
		res = b;
	}

	cout << res << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}