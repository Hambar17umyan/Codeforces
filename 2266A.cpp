#include <iostream>
using namespace std;

void solve() {
	int n;
	cin >> n;
	int a, b, c;
	cin >> a >> b >> c;
	cout << n - min(a, min(b, c)) << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}