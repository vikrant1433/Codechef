/*gauravjasraj*/
#include<stdlib.h>
#include<stdio.h>
#define mod 1000000007
long long int inv;
int pow(long long int a,long long int k)
{
    if(!k) return 1;
    long long t=pow(a,k>>1);
    t=(t*t)%mod;
    if(k&1) return (t*a)%mod;
    else return t;
}
int comp(long long int p)
{
    long long ans=pow(26,p+1);
    ans-=1;
    ans=(ans*inv)%mod;
    if(ans<0) ans+=mod;
    return (int)ans;
}
int main()
{
    long long int n,ans,t;
    inv=pow(25,mod-2);
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        ans=comp(n>>1);
        ans=(ans+comp((n+1)>>1))%mod;
        printf("%lld\n",(ans-2));
    }
    return 0;
}
