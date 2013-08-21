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
const int sz = 10005;
#define lo long long int

int a[sz];
lo p_max[sz],p_min[sz];
lo n_max[sz],n_min[sz];

lo maxx ( lo a, lo b )
{
    return  ( a > b )? a:b;
}
#define getcx getchar_unlocked
//
//inline void inp( int &n )
//{
//        n=0;
//        int ch=getcx();  int sign=1;
//        while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
//
//        while(  ch >= '0' && ch <= '9' )
//                n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
//                n=n*sign;
//}
int main ()
{
    freopen("in.txt","r",stdin);
    int tc;
    scanf("%d",&tc);

    while ( tc-- )
    {
        int n;
        scanf("%d",&n);
        memset ( a, 0, sizeof a );
        memset ( p_max, 0, sizeof p_max );
        memset ( p_min, 0,  sizeof p_min );
        memset ( n_max, 0, sizeof n_max );
        memset ( n_min, 0,  sizeof n_min );
        for ( int i = 0; i < n; i++ )
            scanf("%d",&a[i]);

        ///calculating max from l--->r
        p_max[ 0 ] = a[ 0 ];
        for ( int i = 1; i < n - 1; i++)
            p_max[i] = (p_max[i - 1] > 0 )?(a[i] + p_max[i - 1]):a[i];

        for (int i=0; i<n; i++)
            cout<<p_max[i]<<" ";
        cout<<endl;
        ///calculating min from l ---> r
        n_min[ 0 ] = a[0];
        for ( int i  = 1; i < n - 1; i++ )
            n_min [ i ] = ( n_min[ i - 1 ] < 0 )? ( a[ i ] + n_min [i -1]) : a[ i ];
        for (int i=0; i<n; i++)
            cout<<n_min[i]<<" ";
        cout<<endl;
        ///calculating min from r ---> l
        n_max [  n - 2  ]  = a [ n - 1 ];
        for ( int i  = n  - 3; i >=0; i-- )
            n_max [ i ] = ( n_max[ i + 1 ] > 0 )? ( a[ i + 1 ] + n_max [i + 1]) : a[ i + 1 ];
        for (int i=0; i<n; i++)
            cout<<n_max[i]<<" ";
        cout<<endl;
        ///calculating min from r ---> l
        p_min [  n - 2  ]  = a [ n - 1 ];
        for ( int i  = n  - 3; i >=0; i-- )
            p_min [ i ] = ( p_min[ i + 1 ] < 0 )? ( a[ i + 1 ] + p_min [i + 1]) : a[ i + 1 ];
        for (int i=0; i<n; i++)
            cout<<p_min[i]<<" ";
        cout<<endl;
        unsigned long long abmx = 0;
        for ( int i = 0; i < n - 1; i++ )
            abmx = maxx ( abmx , maxx ( p_max[i] - p_min[i], n_max [ i] - n_min[i] ));
        printf ("%llu\n", abmx );
    }
}
