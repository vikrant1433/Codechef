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

#define s(n)                         scanf("%d",&n)
#define sc(n)                        scanf("%c",&n)
#define sl(n)                        scanf("%lld",&n)
#define sf(n)                        scanf("%lf",&n)
#define ss(n)                        scanf("%s",n)
#define scana(a,t)                   for(int i = 0; i < t; i++){cin >> a[i];}

#define forall(i,a,b)                for(int i=a;i<b;i++)
#define foreach(v, c)                for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define rep(i,a)                     for (int i=0; i<a; i++)

#define all(a)                        a.begin(), a.end()
#define in(a,b)                       ( (b).find(a) != (b).end())
#define pb                            push_back
#define fill(a,v)                     memset(a, v, sizeof a)
#define sz(a)                         ((int)(a.size()))

#define maX(a,b)                      ( (a) > (b) ? (a) : (b))
#define miN(a,b)                      ( (a) < (b) ? (a) : (b))

#define p(n)                          printf("%d\n",n)
#define pl(n)                         printf("%lld\n",n)
#define pul(n)                        printf("%llu\n", n);
#define pf(n)                         printf("%f\n",n)
#define pc(n)                         printf("%c\n",n)
#define ps(n)                         printf("%s\n",n)

#define sort(x)                       sort(all(x))

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

typedef struct point
{
	int x;
	int y;
}point;
int distance_square(point a, point b)
{
	return (int)pow((a.x-b.x),2) + (int)pow((a.y-b.y),2);
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen ("in.txt", "r", stdin);
		// freopen ("out.txt", "w", stdout);
	#endif
	ULL cnt=0;
	int N,x,y;
	point p[2000];
	s(N);s(D);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d%d",&(p[i].x),&(p[i].y));
	}
	std::vector<int> v(3);
	for (int i = 0; i < N-2; i++)
	{
		for (int j = i+1; j < N-1; j++)
		{
			for (int k = j+1; k < N; k++)
			{
				v[0] = distance_square(p[i],p[j]);
				v[1] = distance_square(p[i],p[k]);
				v[2] = distance_square(p[j],p[k]);
				sort(v);
				if (v[2]<v[1]+v[0])
				{
					cnt++;
				}
			}
		}
	}
	pul(cnt);
	return 0;
}
