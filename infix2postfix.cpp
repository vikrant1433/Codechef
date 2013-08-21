using namespace std;
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>

// // Input macros
#define s(n)                        scanf("%d",&n)
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%lld",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)



// // Useful constants
#define INF                         (int)1e9
#define EPS                         1e-9

// // Useful hardware instructions
#define bitcount                    __builtin_popcount
#define gcd                         __gcd

// // Useful container manipulation / traversal macros
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define foreach(v, c)               for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back
#define fill(a,v)                    memset(a, v, sizeof a)
#define sz(a)                       ((int)(a.size()))
#define mp                          make_pair

// Some common useful functions
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))
#define checkbit(n,b)                ( (n >> b) & 1)
#define DREP(a)                      sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)               (lower_bound(all(arr),ind)-arr.begin())

#define p(n)                          printf("%d\n",n)
#define pl(n)                         printf("%lld\n",n)
#define pul(n)                        printf("%llu\n", n);
#define pf(n)                         printf("%f\n",n)
#define pc(n)                         printf("%c\n",n)
#define ps(n)                         printf("%s\n",n)
#define scana(a,t)                          for(int i = 0; i < t; i++){cin >> a[i];}
#define sort(x)                           sort(all(x))
#define gsort(x)                          sort(all(x), greater<typeof(*((x).begin()))>())
#define unique(v)                         sort(v); (v).resize(unique(all(v)) - (v).begin())
#define rep(i,a)                          for (int i=0; i<a; i++)
#define gc                            getchar_unlocked
#define MOD                           1000000007
#define MAX                           1000
#define freopen_in                 	  freopen("in.txt","r",stdin);
#define freopen_out                   freopen("out.txt","w",stdout);
#define numTest(t)                    int t; s(t); while(t--)

int main ()
{
	#ifndef ONLINE_JUDGE
        freopen_in;
    #endif

	char in[401],op[401];
	numTest(t)
	{
		int i=0,j=0;
		char ch;
		ss(in);
		while((ch=in[i++]) != '\0')
		{
			if(ch=='(')
				continue;
			else if (ch >= 'a' && ch <= 'z')
				putchar(ch);
			else if (ch == ')')
				putchar(op[j--]);
			else
				op[++j] = ch;
		}
		printf("\n");
	}

	return 0;
}

