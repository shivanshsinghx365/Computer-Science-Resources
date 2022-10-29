#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define pii             pair<int,int>
#define vi              vector<int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define rep(i,a,b)      for(int i=a;i<b;i++)
#define mem1(a)			memset(a,-1,sizeof(a))
#define mem0(a)			memset(a,0,sizeof(a))
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
template<typename T, typename T1>T amax(T &a, T1 b) {if (b > a)a = b; return a;}
template<typename T, typename T1>T amin(T &a, T1 b) {if (b < a)a = b; return a;}
template<typename T>
using pbds = tree<T , null_type , less<T> , rb_tree_tag , tree_order_statistics_node_update>;
const int N = 3e5 + 5;
// vector<int>tr;
 
 
 
struct FenwickTree
{
	int N;
	vector<int> tree;
 
	void init(int n)
	{
		N = n;
		tree.assign(n + 1, 0);
	}
 
	void update(int idx, int val)
	{
		while (idx <= N)
		{
			tree[idx] += val;
			idx += idx & -idx;
		}
	}
 
	void updateMax(int idx, int val)
	{
		while (idx <= N)
		{
			tree[idx] = max(tree[idx], val);
			idx += idx & -idx;
		}
	}
 
	int pref(int idx)
	{
		int ans = 0;
		while (idx > 0)
		{
			ans += tree[idx];
			idx -= idx & -idx;
		}
		return ans;
	}
 
	int rsum(int l, int r)
	{
		return pref(r) - pref(l - 1);
	}
 
	int prefMax(int idx)
	{
		int ans = -2e9;
		while (idx > 0)
		{
			ans = max(ans, tree[idx]);
			idx -= idx & -idx;
		}
		return ans;
	}
};
 
 
 
void solve() {
	int n, q; cin >> n >> q;
	vi v(n);
	FenwickTree bit;
	bit.init(n);
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		v[i] = x;
		bit.update(i + 1, x);
	}
 
	while (q--) {
		int ty; cin >> ty;
		if (ty == 1) {
			int k, u; cin >> k >> u;
			int temp = v[k - 1];
			v[k - 1] = u;
			// cout << u - temp << endl;
			bit.update(k, u - temp);
 
 
 
		}
		else {
			int a, b; cin >> a >> b;
			cout << bit.rsum(a, b) << endl;
		}
	}
}
 
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#ifdef SEIVE
	seive();
#endif
#ifdef NCR
	init();
#endif
	int t = 1;
	// cin >> t;
	while (t--) solve();
	return 0;
 
}
