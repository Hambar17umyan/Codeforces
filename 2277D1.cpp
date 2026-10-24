#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
#include <iomanip>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <vector>
#include <iterator>
using namespace std;

typedef long long ll;
typedef unsigned usg;

#define speed ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ratdig(x) cout << fixed << setprecision(x);
#define xfixdig(x) cout << setprecision(x);
#define rev(x) reverse(x.begin(), x.end())
#define all(x) x.begin(), x.end()

#define midd mid + 1
#define middle ll mid = (l + r) / 2
#define poss pos * 2

void yn(bool b)
{
	if (b)
	{
		cout << "YES\n";
		return;
	}
	cout << "NO\n";
}

ll gcd(ll a, ll b) {
	if (a == 0)
		return b;
	if (b == 0)
		return a;
	return gcd(b % a, a);
}

ll lcm(ll a, ll b)
{
	return (a * b) / gcd(a, b);
}

string to2(ll a, ll n = -1)
{
	string r = "";
	for (ll i = 0; ((ll)1 << i) <= a; i++)
	{
		char c = ((((ll)1 << i) & a) != 0) + '0';
		r += c;
	}
	if (a == 0)
	{
		r = "0";
	}
	if (n != -1)
	{
		for (int i = 0; i < n - r.size(); i++)
			r += '0';
	}
	rev(r);

	return r;
}

ll binpow(ll a, ll b, ll mod = -1)
{
	ll ans = 1;
	while (b)
	{
		if ((b & 1) == 1)
		{
			ans *= a;
			if (mod != -1)
				ans %= mod;
		}
		b >>= 1;
		a *= a;
		if (mod != -1)
			a %= mod;
	}
	return ans;
}

ll to10(string a)
{
	ll ans = 0;
	for (ll i = 0; i < a.size(); i++)
	{
		if (a[i] == '1')
		{
			ans += binpow(2, a.size() - i - 1);
		}
	}
	return ans;
}

ll lgg2(ll n) {
	int m = 0;
	while (n >>= 1)
		++m;
	return m;
}

ll find(ll x, ll n) {
	ll mod = 998244353;

	ll o = n + 1 - x;
	ll m = lgg2(o);

	if ((1ll << m) == o) {
		return m;
	}
	else {
		if (m != 1)
		{
			ll res = m + 1 + find(x + ((1ll << m) - 1) - 1, n);
			res = min(res, m + 1 + x + (1ll << (m + 1)) - 1 - n);
			return res % mod;
		}
		else {
			ll res = m + 1 + x + (1ll << (m + 1)) - 1 - n;
			return res % mod;
		}
	}
}

void solve()
{
	ll x;
	ll l, r;
	cin >> l >> r;
	ll res = 0;
	ll mod = 998244353;

	for (ll n = l; n <= r; n++) {
		res += find(0, n);
		res %= mod;
	}

	cout << res << endl;
}


int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		solve();
	}
}