#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;


long long lmin[10010],rmin[10010],lmax[10010],rmax[10010];

void LMaxContigousSum(long long A[],long long n)
{
    long long i;
    lmax[0]=A[0];
    for(i=1; i<n; i++)
    {
        if(lmax[i-1]+A[i]>A[i])
            lmax[i]=lmax[i-1]+A[i];
        else lmax[i]=A[i];
    }
}
void LMinContigousSum(long long A[],long long n)
{
    long long i;

    lmin[0]=A[0];
    for(i=1; i<n; i++)
    {
        if(lmin[i-1]+A[i]<A[i])
            lmin[i]=lmin[i-1]+A[i];
        else
        {
            lmin[i]=min(A[i],lmin[i-1]);
        }
    }
}
void RMaxContigousSum(long long A[],long long n)
{
    long long i;

    rmax[n-1]=A[n-1];
    for(i=n-2; i>=0; i--)
    {
        if(rmax[i+1]+A[i]>A[i])
            rmax[i]=rmax[i+1]+A[i];
        else rmax[i]=A[i];
    }
}
void RMinContigousSum(long long A[],long long n)
{
    long long i;

    rmin[n-1]=A[n-1];
    for(i=n-2; i>=0; i--)
    {
        if(rmin[i+1]+A[i]<A[i])
            rmin[i]=rmin[i+1]+A[i];
        else rmin[i]=min(A[i],rmin[i+1]);
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    long long n,i,t;
    cin>>t;
    while(t--)
    {
        long long  ans=0,rmaxlmin[10010]= {0},lmaxrmin[10010]= {0};
        cin>>n;
        long long A[n];
        for(i=0; i<n; i++)
        {
            cin>>A[i];
        }
        LMaxContigousSum(A,n);
        LMinContigousSum(A,n);
        RMaxContigousSum(A,n);
        RMinContigousSum(A,n);
        for(i=0; i<n-1; ++i)

        {

            rmaxlmin[i]=abs(rmax[i+1]-lmin[i]);
            lmaxrmin[i]=abs(lmax[i]-rmin[i+1]);
            if(rmaxlmin[i]>ans)
                ans=rmaxlmin[i];

            if(lmaxrmin[i]>ans)
                ans=lmaxrmin[i];
        }
        cout<<ans<<"\n";
    }
}
