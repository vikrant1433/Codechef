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
#include <climits>

#define s(n)                         scanf("%d",&n)
#define sc(n)                        scanf("%c",&n)
#define sl(n)                        scanf("%lld",&n)
#define sf(n)                        scanf("%lf",&n)
#define ss(n)                        scanf("%s",n)
#define scana(a,t)                   for(int _ = 0; _ < t; _++){cin >> a[_];}

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

#define gsort(x)                      sort(all(x), greater<typeof(*((x).begin()))>())
#define sort(x)                       sort(all(x))
#define mp 							  make_pair

#define DEBUG(x)               		  { cerr << #x << " = " << x << endl; }
#define PR(a,n)                		  {cerr<<#a<<" = "; FOR(_,1,n) cerr << a[_] << ' '; cerr <<endl;}
#define PR0(a,n)               		  {cerr<<#a<<" = ";REP(_,n) cerr << a[_] << ' '; cerr << endl;}

#define numTest(t)                    int t; s(t); while(t--)

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

int main()
{
	#ifndef ONLINE_JUDGE
		freopen ("in.txt", "r", stdin);
		// freopen ("out.txt", "w", stdout);
	#endif
	int n,m;
	VI P;
	VVI rooms;
	numTest(t)
	{
		cin>>n>>m;
		rooms.resize(n);
		P.resize(m);
		scana(P, m);
		REP(j,n)
		{
			int num;
			cin>>num;
			rooms[j].resize(num);
			scana(rooms[j], num);
			sort(rooms[j]);
		}
		// PR0(P,m);
		// REP(i,n)
		// 	PR0(rooms[i],sz(rooms[i]));
		ULL vol = 0;
		REP(i,m)
		{
			int s = sz(rooms[P[i]]);
			if(s != 0)
			{
				vol += rooms[P[i]][s-1];
				rooms[P[i]].pop_back();
			}
		}
		pul(vol);
		P.clear();
		rooms.clear();
	}

	return 0;
}
