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
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <climits>

#define INF                         (int)1e9
#define EPS                         1e-9

#define bitcount                    __builtin_popcount
#define gcd                         __gcd

#define s(n)                         scanf("%d",&n)
#define sc(n)                        scanf("%c",&n)
#define sl(n)                        scanf("%lld",&n)
#define sf(n)                        scanf("%lf",&n)
#define ss(n)                        scanf("%s",n)
#define scana(a,t)                   for(int i = 0; i < t; i++){cin >> a[i];}

#define FOR(i,a,b)                	 for(int i=a;i<b;i++)
#define FOREACH(v, c)                for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define REP(i,a)                     for (int i=0; i<a; i++)

#define all(a)                        a.begin(), a.end()
#define in(a,b)                       ( (b).find(a) != (b).end())
#define pb                            push_back
#define fill(a,v)                     memset(a, v, sizeof a)
#define sz(a)                         ((int)(a.size()))

#define maX(a,b)                      ( (a) > (b) ? (a) : (b))
#define miN(a,b)                      ( (a) < (b) ? (a) : (b))
#define PI                     		  acos(-1)
#define sqr(x)                 		  ((x) * (x))

#define p(n)                          printf("%d\n",n)
#define pl(n)                         printf("%lld\n",n)
#define pul(n)                        printf("%llu\n", n);
#define pf(n)                         printf("%f\n",n)
#define pc(n)                         printf("%c\n",n)
#define ps(n)                         printf("%s\n",n)

#define msort(x)                      sort(all(x))
#define gsort(x)                      sort(all(x), greater<typeof(*((x).begin()))>())
#define mp 							  make_pair

#define DEBUG(x)               		  { cerr << #x << " = " << x << endl; }
#define PR(a,n)                		  {cerr<<#a<<" = "; FOR(_,1,n) cerr << a[_] << ' '; cerr <<endl;}
#define PR0(a,n)               		  {cerr<<#a<<" = ";REP(_,n) cerr << a[_] << ' '; cerr << endl;}

#define numTest(t)                    int t; s(t); while(t--)

typedef int64_t LL;
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

int cnt = 0;
void findFactors(VII & p, int j, int ans) {
    if (j == sz(p)) {
        int t = ans;
        cout<<ans<<endl;
        while(t > 0)
        {
        	int m = t%10;
        	if (m == 4 || m == 7)
        	{
        		cnt++;
        		break;
        	}
        	t /= 10;
        }
        return;
    }
    for (int i = 0; i <= p[j].second; ++i) {
        findFactors(p, j + 1, ans);
        ans *= p[j].first;
    }
}



int main()
{	
	#ifndef ONLINE_JUDGE
		freopen ("in.txt", "r", stdin);
		// freopen ("out.txt", "w", stdout);
	#endif
	VII d;
	numTest(t)
	{
		int n; cin>>n;
		for (int i = 2, sqroot = sqrt(n); i <= sqroot && n > 1; ++i)
		{
			if(n%i == 0)
			{
				int cnt = 0;
				while(n%i == 0)
				{
					cnt++ ;
					n /= i;
				}
				d.pb(mp(i,cnt));
			}	
		}
		if (n > 1)
		{
			d.pb(mp(n,1));
		}
		findFactors(d,0,1);
		cout<<cnt<<"\n";
		cnt = 0;
		d.clear();
	}
	return 0;
}