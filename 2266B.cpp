#include <iostream>
typedef long long ll;
using namespace std;

void solve() {
	ll a, b, c;
	cin >> a >> b >> c;
	if (a < b) {
		ll w = b - a;
		if (a + c - b >= w){
			cout << a + c - b << endl;
		}
		else {
			cout << w << endl;
		}
	}
	else if (a >= b) {
		cout << a + c - b << endl;
	}
}

int main() {
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}