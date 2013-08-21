#include <template.h>
//#include <stdio.h>

//long long power(int a, int b)
//{
////    int MOD=1000000007;
//    long long x=1,y=a;
//    while(b > 0)
//    {
//        if(b%2 == 1)
//        {
//            x = x*y;
//            x %= MOD;
//        }
//        y = y*y;
//        y %= MOD;
//        b /= 2;
//    }
//    return x;
//}
long long power(int base ,int n)
{
    n = n%2 ? n/2 +1 : n/2;
    long long ans = base;
    while(n>1)
    {
        if (n%2 == 0)
        {
            ans *= ans;
            ans %= MOD;
            n /= 2;

        }
        else
        {

            ans *= ans*base;
            ans %= MOD;
            n /= 2;
        }

    }
    return ans;
}

long long InverseEuler(int n)
{
//    int MOD=1000000007;
    return power(n,MOD-2);
}
int main()
{
    freopen("in.txt","r",stdin);
    int q,t,i,j,n;
    long long temp;
//    int MOD=1000000007;
    scanf("%d",&t);
    long long inv;
    inv=InverseEuler(25);
    for(q=0; q<t; q++)
    {
        scanf("%d",&n);
        if (n%2==0)
            printf("%lld\n",(((2*(power(26,(n/2)+1)-26)%MOD)%MOD)*inv)%MOD);
        else
        {
            temp=power(26,(n/2)+1);
            printf("%lld\n",(((2*((temp-26)%MOD)*inv)%MOD)+temp)%MOD);

        }
    }
    return 0;
}
