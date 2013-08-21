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

#define sort(x)                       sort(all(x))
#define gsort(x)                      sort(all(x), greater<typeof(*((x).begin()))>())
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
typedef vector<ULL>	VULL;
typedef vector<PII> VII;
typedef vector<PLL> VLL;


typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VII> VVII;
typedef vector<VLL> VVLL;


typedef vector<string> VS;
typedef vector<VS> VVS;

ULL query(VULL & st, int s, int e, int qs, int qe, int i, int& M)
{
	if (qs<= s && e<= qe)
	{
		return st[i];
	}
	else if (s>qe || e < qs)
	{
		return 1ULL;
	}
	int mid = s + (e-s)/2;
	return query(st, s, mid, qs, qe, 2*i+1,M) * query(st, mid+1, e, qs, qe, 2*i+2,M);
}

ULL buildTree(VI & a, VULL & st, int s, int e, int i)
{
	if (s == e)
	{
		st[i] = a[s];
		return st[i];
	}
	int mid = s + (e-s)/2;
	st[i] = buildTree(a, st, s, mid, 2*i+1) * buildTree(a, st, mid+1, e, 2*i+2);
	return st[i];
}
int main()
{
	#ifndef ONLINE_JUDGE
        freopen ("in.txt", "r", stdin);
		// freopen ("out.txt", "w", stdout);
	#endif
	VI a;
	VULL st;

	int N;
	cin>>N;
	a.resize(N);
	scana(a,N);
	int size = (1<<((int) log2(N)+2))-1;
	st.resize(size);
	buildTree(a, st, 0, N-1, 0);
	int L,R,M;
	numTest(t)
	{
		cin>>L>>R>>M;
		cout<<query(st, 0, N-1, L-1 , R-1, 0, M)<<endl;
	}
	cout<<st[0]<<endl;
	st.clear();
	a.clear();
	return 0;
}
