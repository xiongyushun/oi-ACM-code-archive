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
CLL MaxN = 110, mod = 1e9 + 7; int n, q;
LL f[MaxN][MaxN][MaxN], C[MaxN][MaxN], pow2[MaxN*MaxN], poww[MaxN][MaxN];
LL Pow (LL x, LL k) {LL r = 1; for (; k; x = x * x % mod, k >>= 1) if (k & 1) r = r * x % mod; return r;}
void initC () {
	C[0][0] = 1; for (int i = 1; i <= n; ++ i) {C[i][0] = 1; for (int j = 1; j <= n; ++ j) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;}
}
void initpow () {
	pow2[0] = 1; for (int i = 1; i <= n * n; ++ i) pow2[i] = (pow2[i - 1] * 2) % mod;
	for (int i = 1; i <= n; ++ i) for (int j = 1; j <= n; ++ j) poww[i][j] = Pow (pow2[i] - 1, j) % mod;
}
int get () {
	fin >> n >> q; initC (); initpow (); f[0][1][1] = 1;
	for (int i = 1; i <= q; ++ i) for (int j = 1; j <= n; ++ j) for (int k = 1; k <= j; ++ k) for (int l = 1; l <= j - k; ++ l) {
		if (i == q) f[i][j][k] += (f[i - 1][j - k][l] * poww[l][k] % mod) * pow2[k * (k - 1) / 2] % mod * C[n - j + k - 1][k - 1] % mod, f[i][j][k] %= mod;
		else f[i][j][k] += (f[i - 1][j - k][l] * poww[l][k] % mod) * pow2[k * (k - 1) / 2] % mod * C[n - j + k - 1][k] % mod, f[i][j][k] %= mod;
	}
	LL ans = 0;
	for (int i = q + 1; i <= n; ++ i) for (int j = 1; j <= n; ++ j) {
		ans += (f[q][i][j] * pow2[j * (n - i)] % mod) * pow2[(n - i) * (n - i - 1) / 2] % mod; ans %= mod;
	} printf ("%lld\n", ans % mod);
	return 0;
}
int main () {return get () && 0;}
