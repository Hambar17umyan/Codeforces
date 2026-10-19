#include <iostream>
using namespace std;

void solve() {
	string s;
	cin >> s;
	int res = 1;
	for (int i = 1; i < s.size() - 1; i++) {
		if (s[i] == s[i - 1] && s[i] == s[i + 1]) {
			res++;
		}

		if (s[i] != s[i - 1] && s[i] != s[i + 1]) {
			res++;
		}
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