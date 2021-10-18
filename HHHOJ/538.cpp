#include <bits/stdc++.h>
#define Tp template<typename Ty>
#define I inline
#define LL long long
#define Con const
#define Reg register
#define CI Con int
#define CLL Con LL
#define RI Reg int
#define RLL Reg LL
#define W while 
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
#define Gmax(x,y) (x<(y)&&(x=(y)))
#define Gmin(x,y) (x>(y)&&(x=(y)))
struct FastIO {
	Tp FastIO& operator >> (Ty& in) {
		in = 0; char ch = getchar (); bool flag = 0;
		for (; ! isdigit (ch); ch = getchar ()) (ch == '-' && (flag = 1));
		for (;   isdigit (ch); ch = getchar ()) in = (in * 10) + (ch ^ 48);
		in = (flag ? -in : in); return *this;
	}
}fin;
CI MaxN = 1e6 + 100; int n, q; struct node {int l; int r;}a[MaxN]; int pre[MaxN], fa[MaxN][25];
int get () {
	fin >> n >> q; for (int i = 1; i <= n; ++ i) fin >> a[i].l >> a[i].r; 
	std :: sort (a + 1, a + n + 1, [] (node x, node y) {return x.l != y.l ? x.l < y.l : x.r < y.r;});
	pre[n] = a[n].r; for (int i = n - 1; i; -- i) pre[i] = min (pre[i + 1], a[i].r);
	memset (fa, -1, sizeof (fa)); int o = 0; for (int i = 1; i <= n; ++ i) while (o <= a[i].l) fa[o][0] = pre[i] + 1, ++ o;
	for (int i = 1; i <= 23; ++ i) for (int j = 0; j <= 1000000; ++ j) if (fa[j][i - 1] != -1) fa[j][i] = fa[fa[j][i - 1]][i - 1];
//	for (int i = 1; i <= 10; ++ i) printf ("%d ", fa[i]); printf ("\n");
	for (int i = 1; i <= q; ++ i) {
		int ll, rr; fin >> ll >> rr; ++ rr; int ans = 0;
		for (int i = 23; i >= 0; -- i) if (fa[ll][i] != -1 && fa[ll][i] <= rr) ll = fa[ll][i], ans += (1 << i); printf ("%d\n", ans);
	}
	return 0;
}
int main () {return get () && 0;}
