#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned usg;

static class ProblemA
{
public: static void Solve()
{
	int n;
	cin >> n;
	int bac, zr;
	bac = zr = 0;
	for (int i = 0; i < n; i++)
	{
		short k;
		cin >> k;
		if (k == -1)
			bac++;
		else if (k == 0)
			zr++;
	}
	int y = bac % 2;
	y *= 2;
	cout << zr + y << "\n";
}
};

static class ProblemB
{
	static int arr[200005];
public: static void Solve()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);
	int ans = 0;
	for (int i = 1; i < n; i += 2)
	{
		ans = max(ans, arr[i] - arr[i - 1]);
	}
	cout << ans << endl;
}
};

static class ProblemC
{
private: static int arr[200005];

public: static void Solve()
{
	int n, k;
	cin >> n >> k;
	int k_count = 0;
	set<int>st;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (arr[i] == k)
		{
			k_count++;
		}
		st.insert(arr[i]);
	}

	int m = -1;
	int res = k_count;
	for (set<int>::iterator it = st.begin(); it != st.end();)
	{
		if (m == k - 1)
		{
			break;
		}

		if (*it != m + 1)
		{
			if (k_count > 0)
			{
				k_count--;
				m++;
			}
			else
			{
				res++;
				m++;
			}
		}
		else
		{
			m++;
			it++;
		}
	}
	if (m != k - 1)
	{
		res += k - 1 - m;
	}

	cout << res << endl;
}
};

static class ProblemD
{
private: static ll cost(string s, char c)
{
	vector<int> indexes;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == c)
			indexes.push_back(i);
	}

	int medInd = indexes.size() / 2;
	ll res = 0;
	for (int i = 0; i < indexes.size(); i++)
	{
		indexes[i] -= i;
	}

	for (int i = 0; i < indexes.size(); i++)
	{
		res += abs(indexes[i] - indexes[medInd]);
	}

	if (indexes.size() % 2 == 0)
	{
		ll res1 = 0;
		for (int i = 0; i < indexes.size(); i++)
		{
			res1 += abs(indexes[i] - indexes[medInd - 1]);
		}

		res = min(res, res1);
	}

	return res;
}

public:	static void solve()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	ll resA = cost(s, 'a');
	ll resB = cost(s, 'b');
	cout << min(resA, resB) << endl;
}

};

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		ProblemA::Solve();
		// ProblemB::Solve();
		// ProblemC::Solve();
		// ProblemD::solve();
	}
}