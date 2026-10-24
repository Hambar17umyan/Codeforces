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

const int N = 5e5 + 5;
vector<ll>g[N];

bool color[N];
ll ranks[N];

void set_ranks(ll x, ll r) {
	ranks[x] = r;
	color[x] = true;

	if (x == 0)
		return;

	for (int i = 0; i < g[x].size(); i++) {
		ll node = g[x][i];

		if (!color[node]) {
			set_ranks(node, r + 1);
		}
	}
}

void solve()
{
	ll n, m;
	cin >> n >> m;
	for (ll i = 0; i <= n; i++) {
		g[i].erase(all(g[i]));
		color[i] = false;
		ranks[i] = -1;
	}

	for (ll i = 0; i < n - 1; i++) {
		ll x, y;
		cin >> x >> y;
		x--;
		y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	set_ranks(n - 1, 0);

	ll res = ranks[0];
	for (int i = 0; i < m; i++) {
		ll k;
		cin >> k;
		k--;
		if (ranks[k] != -1) {
			res = max(res, ranks[k] + 1);
		}
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