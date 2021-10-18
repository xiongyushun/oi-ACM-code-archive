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
int gcd (int x, int y) {return y == 0 ? x : gcd (y, x % y);}
int T, a, b, c, d;
int get () {
	fin >> T; while (T --) {
		fin >> a >> b >> c >> d; int ans = 0;
		for (int x = 1; x * x <= d; ++ x) {
			if (d % x != 0) continue; int y = d / x; 
			if (gcd (x / b, a / b) == 1 && gcd (d / x, d / c) == 1 && x % b == 0) ++ ans;
			if (x == y) continue;
			if (gcd (y / b, a / b) == 1 && gcd (d / y, d / c) == 1 && y % b == 0) ++ ans;
		} printf ("%d\n", ans);
	}
	return 0;
}
int main () {return get () && 0;}
