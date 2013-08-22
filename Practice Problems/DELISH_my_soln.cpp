#include <cstdio>
#include <cstdlib>
#include <iostream>
#define N 10000
using namespace std;
long long int  max(long long int  a, long long int  b)
{
    return a>b?a:b;
}
long long int  min(long long int  a, long long int  b)
{
    return a<b?a:b;
}
void min_max(long long int  D[], long long int  a[], int n, long long int  (*cmpfn)(long long int , long long int ), int S)
{
    int t = (S==0?1:-1);
    a[S] = D[S];
    for(int i=S+t; i >=0 && i<n ; i = i + t)
        a[i] = (*cmpfn)(D[i],a[i-t]+D[i]);
}
void readArr(long long int  a[], int n)
{
    for(int i=0; i<n; i++)
        scanf("%lld",&(a[i]));
}

int main()
{
    long long int LMax[N],LMin[N],RMax[N],RMin[N],D[N];
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        readArr(D,n);
        min_max(D,LMin,n,min,0);
        min_max(D,LMax,n,max,0);
        min_max(D,RMax,n,max,n-1);
        min_max(D,RMin,n,min,n-1);
        long long int  maxDiff = 0, curDiff=0;
        for(int  i=0; i<n-1; i++)
        {
            curDiff = max(abs(LMax[i]-RMin[i+1]), abs(LMin[i]-RMax[i+1]));
            maxDiff = max(maxDiff,curDiff);
        }
        printf("%lld\n",maxDiff);
    }

    return 0;
}
