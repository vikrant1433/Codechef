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

// Useful hardware instructions
#define bitcount                    __builtin_popcount
#define gcd                         __gcd

// Useful container manipulation / traversal macros
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define rep(i,b)					forall(i,0,b)
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

int main(int argc, char const *argv[])
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	// int t,i,as,bs,n,len;
	int t;
	s(t);
	string s,alice,bob;
	cin>>s;
	while(t--)
	{
		int power[26] = {0};
		cin>>alice>>bob;

		for(int i = 0, pos; i < sz(alice); i++)
		{
			pos = bob.find_first_of(alice[i]);
			if (pos != (int)string::npos)
			{
				alice.erase(i,1);
				bob.erase(pos,1);
				i--;
			}
		}

		rep(i,sz(alice))
			if(power[alice[i]-'a']==0)
				power[alice[i]-'a']++;
		rep(i,sz(bob))
			if(power[bob[i]-'a']==0)
				power[bob[i]-'a']--;
			
		int ans = 0;
		char ch[2] = "a";
		rep(i,26)
		{
			ans += power[i]*(int)s.find_first_of(ch);
			(*ch)++;
		}
		if (ans > 0)
		 {
		 	cout<<"ALICE"<<endl;
		 }
		 else if (ans < 0)
		 	cout<<"BOB"<<endl;
		 else
		 	cout<<"TIE"<<endl;

	}
	return 0;
}
