#include <iostream>
#include <string>
#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <list>
#include <cmath>
#include <stack>
#include<sstream>
using namespace std;

#define pb push_back
#define ll long long
typedef     istringstream     iss;
typedef     ostringstream     oss;
#define scan(n) scanf("%d",&n)
#define print(n) printf("%d\n",n)
#define pl(n) printf("%lld\n",n)
#define sf(n) scanf("%f",&n)
#define pf(n) printf("%f\n",n)
#define sc(n) scanf("%c",&n);
#define pc(n) printf("%c\n",n)
#define ss(n) scanf("%s",n)
#define ps(n) printf("%s\n",n)
#define scana(a,t) for(int i = 0; i < t; i++){cin >> a[i];}
#define     ALL(v)            (v).begin(),(v).end()
#define     SORT(x)           sort(ALL(x))
#define     GSORT(x)          sort(ALL(x), greater<typeof(*((x).begin()))>())
#define     UNIQUE(v)         SORT(v); (v).resize(unique(ALL(v)) - (v).begin())
#define     REP(i,a)          for (int i=0; i<a; i++)
#define gc getchar_unlocked

typedef pair < int, int >pii;
typedef pair < pii, int >piii;

inline int isvowel(char c)
{
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')return 1;
    return 0;
}
inline int isprime(int a)
{
    for(int i=2; i*i<=a; i++)if(!(a%i))return 0;
    return 1;
}
template<typename T> inline string tostring(const T& x)
{
    oss os;
    os<<x;
    return os.str();
}
inline int toint(const string& s)
{
    iss is(s);
    int x;
    is>>x;
    return x;
}
inline int todecimal(string s)
{
    int a=0;
    REP(i,s.size())a=2*a+(s[i]-'0');
    return a;
}
inline string tobinary( int a)
{
    string s;
    while(a!=0)
    {
        s=(char)(a%2+'0')+s;
        a>>=1;
    }
    return s;
}

const int dx4[4] = { 0, 0, 1, -1 };
const int dy4[4] = { 1, -1, 0, 0 };
const int dx8[8] = {0, 0, 1, 1, 1, -1, -1, -1};
const int dy8[8] = {1, -1, 0, 1, -1, 1, 0, -1};


void scanint(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(; ((c<48 || c>57) && c != '-'); c = gc());
    if(c=='-')
    {
        neg=1;
        c=gc();
    }
    for(; c>47 && c<58; c = gc())
    {
        x = (x<<1) + (x<<3) + c - 48;
    }
    if(neg) x=-x;
}

vector <int> func(string s1, string s2, string p)
{
    int m1[28],m[28],m2[28];
    memset(m1, 0, sizeof(m1));
    memset(m, 0, sizeof(m));
    memset(m2, 0, sizeof(m2));

    int i,a=0,b=0;
    vector <int> v;

    for ( i = 0; i < p.size(); i++ )
    {
        m[p[i]-96] = i;
    }
    for ( i = 0; i < s1.size(); i++ )
    {
        m1[s1[i]-96]++;
    }
    for ( i = 0; i < s2.size(); i++ )
    {
        m2[s2[i]-96]++;
    }
    char p1;
    for ( p1 = 'a'; p1 <= 'z'; p1++ )
    {
        if ( m1[p1-96] > m2[p1-96] )
        {
            a += m[p1-96];
        }
        if ( m2[p1-96] > m1[p1-96] )
        {
            b += m[p1-96];
        }
    }

    v.push_back(a);
    v.push_back(b);

    return v;
}


int main()
{
    int t;
    string p,s1,s2;

    scanf("%d", &t);
    cin >> p;

    while ( t-- )
    {
        cin >> s1 >> s2;
        vector <int> v = func(s1,s2,p);
        int x1 = v[0];
        int x2 = v[1];
        if ( x1 > x2 ) printf("ALICE\n");
        else if ( x2 > x1 ) printf("BOB\n");
        else printf("TIE\n");
    }

    return 0;
}


