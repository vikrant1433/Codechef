using namespace std;
#include <cstdio>
#include <limits.h>
typedef unsigned long long ULL;


#define getcx getchar//_unlocked

inline void inp(unsigned int &n )
{
   n=0;
   int ch=getcx();int sign=1;
   while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}

   while(  ch >= '0' && ch <= '9' )
           n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
   n=n*sign;
}


int main()
{
	#ifndef ONLINE_JUDGE
		freopen ("in.txt", "r", stdin);
		// freopen ("out.txt", "w", stdout);
	#endif
	unsigned int N,L,R,M;
	inp(N);
	unsigned int a[100000];
	for(int i=0; i<N; i++)
	{
		inp(a[i]);
	}
	unsigned int t; inp(t);
	ULL c = ULLONG_MAX>>7;
	while(t--)
	{
		bool t = true;
        ULL ans =1;
		inp(L); inp(R); inp(M);
		L--; R--;
		if (M == 1)
		{
			putchar('0');
		}
		else
		{
			for(int i = L; i<=R; i++)
			{
				ans *= a[i];
				if (ans > c )
				{
					ans %= M;
				}
				if (ans == 0)
				{
					putchar('0');
					t = false;
					break;
				}
			}
			if (t)
			{
				printf("%llu",ans%M);
			}
		}
		putchar('\n');
	}
	return 0;
}
