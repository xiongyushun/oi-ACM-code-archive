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
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
#define Gmax(x,y) (x<(y)&&(x=(y)))
#define Gmin(x,y) (x>(y)&&(x=(y)))
#define dbg(x) printf ("%s = %d", #x, x)
struct FastIO {
	Tp FastIO& operator >> (Ty& in) {
		in = 0; char ch = getchar (); bool flag = 0;
		for (; ! isdigit (ch); ch = getchar ()) (ch == '-' && (flag = 1));
		for (;   isdigit (ch); ch = getchar ()) in = (in * 10) + (ch ^ 48);
		in = (flag ? -in : in); return *this;
	}
}fin;
int n;
int get () {
	fin >> n; if (n & 1) {
		int k = (n - 1) / 2; printf ("%d\n", k * (k + 1)); printf ("3 1 2 3\n3 1 2 3\n");
		for (int i = 4; i + 1 <= n; i += 2) {printf ("3 %d %d %d\n3 %d %d %d\n", i, i + 1, 1, i, i + 1, 1); for (int j = 2; j < i; j += 2) printf ("4 %d %d %d %d\n4 %d %d %d %d\n",i, j, i + 1, j + 1, i, j, i + 1, j + 1);}
	} else {
		int k = (n - 2) / 2; printf ("%d\n", k * (k + 2)); printf ("4 1 2 3 4\n4 1 3 2 4\n4 1 2 4 3\n");
		for (int i = 5; i + 1 <= n; i += 2) {printf ("4 %d %d %d %d\n3 %d %d %d\n3 %d %d %d\n", i, 1, i + 1, 2, i, i + 1, 1, i, i + 1, 2); for (int j = 3; j < i; j += 2) printf ("4 %d %d %d %d\n4 %d %d %d %d\n",i, j, i + 1, j + 1, i, j, i + 1, j + 1);}
	}
	return 0;
}
int main () {return get () && 0;}
