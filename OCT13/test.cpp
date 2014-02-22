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

int main()
{	
	// #ifndef ONLINE_JUDGE
	// 	// freopen ("in.txt", "r", stdin);
	// 	// freopen ("out.txt", "w", stdout);
	// #endif
	// numTest(t)
	// {
	// 	int N, M=0;
	// 	cin>>N;
	// 	VII v(N);

	// 	FOR(i,0,N)
	// 	{
	// 		int x,y;
	// 		cin>>x>>y;
	// 		v[i] = mp(x,y);
	// 		M = max(M,y);
	// 	}
	// 	msort(v);
	// 	int n = v[N-1].first;
	// 	int k=0;
	// 	// DEBUG(N)
	// 	// DEBUG(M)
	// 	// FOR(i,0,N)	
	// 	// 	cout<<v[i].first<<" "<<v[i].second<<"\n";
	// 	FOR(j,0,M+1)
	// 		printf("   %d",j);
	// 	printf("\n");
	// 	FOR(i,0,n+1)
	// 	{
	// 		printf("%d  ",i);
	// 		FOR(j,0,M+1)
	// 		{
	// 			if (k < N && i== v[k].first && j == v[k].second)
	// 			{
	// 				k++;
	// 				printf("*   ");
	// 			}
	// 			else
	// 				printf("    ");
	// 		}
	// 		printf("\n");
	// 	}
	// printf("\n\n");
	// }
	// system("pause");
	int a = 123, b = 7654;
	a ^= b ^= a ^= b;
	DEBUG(a)
	DEBUG(b)
	return 0;
}