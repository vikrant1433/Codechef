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
// Input macros
#define s(n)                        scanf("%d",&n)
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%lld",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)

// Useful constants
#define INF                         (int)1e9
#define EPS                         1e-9
#define MAX 						100000000
// Useful hardware instructions
#define bitcount                    __builtin_popcount
#define gcd                         __gcd

// Useful container manipulation / traversal macros
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


unsigned long dp[MAX] = {0};
bool isPrime(unsigned long n)
{
	if (n < MAX && dp[n] != 0)
		return true;
	if (n<2)
		return false;
	if (n%2 == 0)
		return false;
	for (unsigned long i = 3, sqroot_n = sqrt(n); i <= sqroot_n; ++++i)
		if ((n%i) == 0)
			return false;
	if (n<MAX)
		dp[n] = n;
	return true;
}
int main(int argc, char const *argv[])
{
	 freopen("in.txt","r",stdin);
	 freopen("out.txt","w",stdout);

	int t;
	for(s(t);t;--t)
	{
		unsigned long m,n;
		scanf("%lu%lu",&m,&n);
		if (m<=2)
            printf("2\n");
		m = m%2 ? m:m+1;
		for (unsigned long i = m; i <= n; ++++i)
		{
			if(isPrime(i))
				printf("%lu\n",i);
		}
		printf("\n");
	}

	return 0;
}

