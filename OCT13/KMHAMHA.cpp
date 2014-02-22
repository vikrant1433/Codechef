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


#define gsort(x)                      sort(all(x), greater<typeof(*((x).begin()))>())
#define msort(x)                      sort(all(x))

#define mp 							  make_pair

#define DEBUG(x)               		  { cerr << #x << " = " << x << endl; }
#define PR(a,n)                		  {cerr<<#a<<" = "; FOR(_,1,n) cerr << a[_] << ' '; cerr <<endl;}
#define PR0(a,n)               		  {cerr<<#a<<" = ";REP(_,n) cerr << a[_] << ' '; cerr << endl;}

#define numTest(t)                    int t; s(t); while(t--)

typedef int64_t LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<bool> VB;
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

void printVII(VII & v)
{
	FOR(i,0,sz(v))
		cout<<v[i].first<<" "<<v[i].second<<"\n";
	cout<<"\n";
}

int main()
{	
	#ifndef ONLINE_JUDGE
		freopen ("in.txt", "r", stdin);
		// freopen ("out.txt", "w", stdout);
	#endif
	int N;
	VII C,R;
	VII Rcnt, Ccnt;
	VB B;
	numTest(t)
	{
		cin>>N;
		R.resize(N);
		C.resize(N);
		B.resize(N,false);
		int x, y;
		FOR(i,0,N)
		{
			cin>>x>>y;
			R[i] = mp(x,i);
			C[i] = mp(y,i);
		}
		msort(R);
		msort(C);
		// printVII(R);
		// printVII(C);

		int cnt = 0;
		
		VII::iterator Rprev = R.begin(),Cprev = C.begin(),Rup = R.begin(), Cup = C.begin();
		
		while(Rup != R.end())
		{			
			Rup = upper_bound(Rup, R.end(),mp((*Rup).first, INT_MAX));
			cnt = Rup - Rprev;
			Rcnt.pb(mp(cnt,Rprev-R.begin()));
			Rprev = Rup;
		}
		while(Cup != C.end())
		{

			Cup = upper_bound(Cup, C.end(),mp((*Cup).first, INT_MAX));
			cnt = Cup - Cprev;
			Ccnt.pb(mp(cnt,Cprev-C.begin()));
			Cprev = Cup;
		}
		gsort(Rcnt);
		gsort(Ccnt);
		// printVII(Rcnt);
		// printVII(Ccnt);
		int n=0;
		int R_i = 0, C_i = 0;
		cnt = 0;
		int i = 0, k = 0;
		bool work = false;
		while(n < N && i < sz(Rcnt) && k < sz(Ccnt))
		{
			if (Rcnt[i].first > Ccnt[k].first )
			{
				int s = Rcnt[i].second;			// 0
				int e = s+Rcnt[i].first;		// 0+5
				FOR(j,s,e)
				{
					R_i = R[j].second;			// 0 1 2 3 4 
					// DEBUG(R_i)
					// DEBUG(n);	
					if (B[R_i] == false)
					{
						n++;
						B[R_i] = true;
						work = true;
					}
				}
				i++;
			}
			else
			{
				int s = Ccnt[k].second;			//6
				int e = s+Ccnt[k].first;		//6 + 4	
				FOR(j,s,e)
				{
					C_i = C[j].second;			// 3,6,8,10
					// DEBUG(C_i)
					// DEBUG(n);
					if (B[C_i] == false)
					{
						n++;
						B[C_i] = true;
						work = true;
					}
				}
				k++;
			}
			if(work == true)
				cnt++;
			work = false;
		}
		cnt = min(sz(Rcnt), cnt);
		cnt = min(sz(Ccnt),cnt);
		cout<<cnt<<"\n";
		Rcnt.clear();
		Ccnt.clear();
		B.clear();
	}
	return 0;
}