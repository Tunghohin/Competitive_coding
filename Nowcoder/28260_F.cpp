#include <iostream>
#include <vector>

using namespace std;
using LL = long long;

const int N = 1000010;

int n;
int sz[N];
LL dp[N];
LL res[N];
vector<int> G[N];

void dfs_1(int u, int from)
{
	sz[u] = 1;
	for (auto v : G[u])
	{
		if (v == from) continue;
		dfs_1(v, u);
		dp[u] += dp[v] + sz[v];
		sz[u] += sz[v];
	}
}

void dfs_2(int u, int from)
{
	if (u != 1)
	{
		res[u] = res[from] + n - 2 * sz[u];
	}
	else res[u] = dp[u];

	for (auto v : G[u])
	{
		if (v == from) continue;
		dfs_2(v, u);
	}
}

void solve()
{
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	dfs_1(1, 0);
	dfs_2(1, 0);

	LL ans = (1ll << 60);
	for (int i = 1; i <= n; i++)
	{
		ans = min(res[i], ans);
	}

	cout << ans << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	solve();
}