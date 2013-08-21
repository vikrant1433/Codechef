
/*  Shubhanshu Agrawal */

#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<string>
#include<sstream>

using namespace std;

#define s(n)					scanf("%d",&n)
#define sl(n) 					scanf("%lld",&n)
#define INF						(int)1e9
#define LINF					(long long)1e18
#define FOR(i,a,b)				for(int i=a;i<=(int)b;i++)
#define REP(i,n)				FOR(i,0,n-1)
#define foreach(v,c)            for( typeof((c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define mp						make_pair
#define let(x,a) __typeof(a) x(a)
#define pb						push_back
#define fill(a,v) 				memset(a,v,sizeof a)
#define all(x)					x.begin(),x.end()
#define INDEX(arr,ind)			(lower_bound(all(arr),ind)-arr.begin())
#define debug(args...)			{dbg,args; cerr<<endl;}

struct debugger
{
	template<typename T> debugger& operator , (const T& v)
	{
		cerr<<v<<" ";
		return *this;
	}
} dbg;

void debugarr(int * arr,int n)
{
	cout<<"[";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<"]"<<endl;
}


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






int main()
{
    freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	s(t);
		char arr[1100];
		scanf("%s",arr);

	int pow[300]={0};
	REP(i,26) pow[arr[i]]=i;
		char arr1[1100],arr2[1100];

	while(t--)
	{
		scanf("%s%s",arr1,arr2);

		int len1=strlen(arr1);
		int len2=strlen(arr2);

		int get[300]={0};
		REP(i,len1) get[ arr1[i] ] +=1;
		REP(i,len2) get[ arr2[i] ] -=1;

		int ans=0;
		REP(i,256)
		{
			if( get[i]>0 ) ans+=pow[i];
			if( get[i]<0 ) ans-=pow[i];
		}

		if(ans==0)
		{
			printf("TIE\n");
		}
		else if(ans>0)
		{
			printf("ALICE\n");
		}
		else
		{
			printf("BOB\n");
		}
	}


	return 0;
}
