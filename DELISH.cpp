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
#include <cstring>
// Input macros
#define s(n)                        scanf("%d",&n)
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%lld",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)



// Useful constants
#define INF                         (int)1e9
#define EPS                         1e-9

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


typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;

typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VII;
typedef vector<PLL> VLL;

typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VII> VVII;
typedef vector<VLL> VVLL;

typedef vector<string> VS;
typedef vector<VS> VVS;

typedef     istringstream     iss;
typedef     ostringstream     oss;

#define p(n) printf("%d\n",n)
#define pl(n) printf("%lld\n",n)
#define pf(n) printf("%f\n",n)
#define pc(n) printf("%c\n",n)
#define ps(n) printf("%s\n",n)
#define scana(a,t) 			  		for(int i = 0; i < t; i++){cin >> a[i];}
#define sort(x)           			sort(all(x))
#define gsort(x)          			sort(all(x), greater<typeof(*((x).begin()))>())
#define unique(v)         			sort(v); (v).resize(unique(all(v)) - (v).begin())
#define rep(i,a)          			for (int i=0; i<a; i++)
#define gc getchar_unlocked
#define freopen_in                    freopen("in.txt","r",stdin);
#define numTest(t)                        int t; s(t); while(t--)

LL maxSubArraySum(LL a[], int size)
{
   LL maxSoFar = a[0], i;
   LL curMax = a[0];
 
   for (i = 1; i < size; i++)
   {
        curMax = max(a[i], curMax+a[i]);
        maxSoFar = max(maxSoFar, curMax);
   }
   return maxSoFar;
}
LL minSubArraySum(LL a[], int size)
{
   LL minSoFar = a[0], i;
   LL curMin = a[0];
 
   for (i = 1; i < size; i++)
   {
        curMin = min(a[i], curMin+a[i]);
        minSoFar = min(minSoFar, curMin);
   }
   return minSoFar;
}
int main(int argc, char const *argv[])
{
    // freopen_in;
    long long a[10000];
    numTest(t)
    {
    	int N,b;
    	s(N);
    	forall(i,0,N)
    	{
    		sl(a[i]);
    	}
      LL curMin, curMax, maxSoFar, minSoFar;
      forall(i,0,)

    }

   return 0;
}
