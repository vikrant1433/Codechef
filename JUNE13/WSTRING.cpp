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

#define p(n) printf("%d\n",n)
#define pl(n) printf("%lld\n",n)
#define pf(n) printf("%f\n",n)
#define pc(n) printf("%c\n",n)
#define ps(n) printf("%s\n",n)
#define scana(a,t)                  for(int i = 0; i < t; i++){cin >> a[i];}
#define sort(x)                     sort(all(x))
#define gsort(x)                    sort(all(x), greater<typeof(*((x).begin()))>())
#define unique(v)                   sort(v); (v).resize(unique(all(v)) - (v).begin())
#define rep(i,a)                    for (int i=0; i<a; i++)
#define gc                          getchar_unlocked
#define freopen_in                    freopen("in.txt","r",stdin);
#define numTest(t)                        int t; s(t); while(t--)

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


int findMax(int a[])
{
	int t = a[0];
	forall(i,1,26)
	{
		if(a[i]>t)
			t = a[i];
	}
	return t;
}
int maxSumBeforeHash(int a[][26], int h)
{
	if(h>0)
	{
		for (int i = 0; i < 26; ++i)
			a[h][i] += a[h-1][i];
	}

	return findMax(a[h]);
}
int maxSumAfterHash(int a[][26], int h, int numHash, int b[])
{
	if(h==3)
	{
		for (int i = 0; i < 26; ++i)
		{
			for (int j = h; j<numHash; j++)
			{
				b[i] += a[j][i];
			}
		}

	}
	else
	{
		forall(i,0,26)
			b[i] -= a[h-1][i];
	}

	return findMax(b);

}
int main(int argc, char const *argv[])
{
    freopen_in;
	numTest(t)
	{
		int j = 0;
		char s[10000];
		int a[10000][26]; fill(a,0);
		ss(s);
		int i=0;
		while(s[i]!='\0')
		{
			if(s[i]=='#')
				j++;
			else
			{
				a[j][s[i]-'a']++;
			}
			i++;
		}
		j++; i=0;
		int b[4];
		int c[26]; fill(c,0);
		int maxSoFar = 0, curMax = 0;
		forall(i,0,j-3)
		{
			b[0] = maxSumBeforeHash(a,i);
			b[1] = findMax(a[i+1]);
			b[2] = findMax(a[i+2]);
			b[3] = maxSumAfterHash(a,i+3,j,c);

			if(b[0]==0 || b[1]==0 || b[2]==0 || b[3]==0)
				continue;
			else
			{
				curMax = b[0]+b[1]+b[2]+b[3];
				maxSoFar = max(curMax,maxSoFar);
			}
		}
		if(maxSoFar != 0)
			p(maxSoFar+3);
		else
			p(0);

	}

    return 0;
}
