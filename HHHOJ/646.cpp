#include <bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar> 
#define I inline
#define ll long long
#define Con const
#define CI Con int
#define RI register int
#define W while
#define gc getchar
#define D isdigit(c=gc())
#define pc(c) putchar((c))
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
#define Gmax(x,y) (x<(y)&&(x=(y)))
#define Gmin(x,y) (x>(y)&&(x=(y)))
#define ms(a,x) memset((a), (x), sizeof (a))
using namespace std;
namespace FastIO {
	CI FS = 1e5; int Top = 0; char S[FS]; 
	Tp I void read (Ty& x) {char c; int f = 1; x = 0; W (! D) f = c ^ '-' ? 1 : -1; W (x = (x * 10) + (c ^ 48), D); x *= f;}
	Ts I void read (Ty& x, Ar&... y) {read (x); read (y...);}
	Tp I void write (Ty x) {x < 0 && (pc ('-'), x = -x, 0); W (S[++ Top] = x % 10 + '0', x /= 10); W (Top) pc (S[Top --]);}
	Tp I void writeln (Ty x) {write (x); pc ('\n');}
}using namespace FastIO;
CI M = 3e5 + 100; int n, m; ll ans; struct node {ll x; ll w;} e[M];
ll gcd (ll a, ll b) {return b == 0 ? a : gcd (b, a % b);}
void get () {
//	freopen ("ex_tree4.in", "r", stdin);
	RI i, j; for (read (n, m), i = 1; i <= m; ++ i) read (e[i].x, e[i].w); sort (e + 1, e + m + 1, [] (node a, node b) {return a.w < b.w;});
	for (i = 1; i <= m; ++ i) {
		if (gcd (n, e[i].x) == 1) {ans += (n - 1) * e[i].w; n = 0; break;}
		else {ans += gcd (n, e[i].x) * (n / gcd (n, e[i].x) - 1) * e[i].w; n = gcd (n, e[i].x);}
	} if (n != 0) printf ("-1\n"); else printf ("%lld\n", ans);
}
int main () {return get (), 0;}
