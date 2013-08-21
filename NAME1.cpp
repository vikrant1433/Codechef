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
#define freopen_in                    freopen("in.txt","r",stdin);
#define freopen_out                   freopen("out.txt","w",stdout);
#define numTest(t)						  int t; s(t); while(t--)

typedef long long LL;
typedef unsigned long long ULL;
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






int main(int argc, char const *argv[])
{

    freopen_in;


	numTest(t1)
	{
        string s1,s2,c,temp;
		cin>>s1>>s2;
		s1 += s2;

		numTest(t2)
		{
			cin>>temp;
			c += temp;
		}

		int pos=-1;
		sort(s1);
		sort(c);
		forall(i,0,sz(c))
		{
			if ((pos = s1.find(c[i], pos+1)) == string::npos)
				break;
		}
		if(pos == string::npos)
			ps("NO");
		else
			ps("YES");



	}


	return 0;
}
