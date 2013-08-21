#include<stdio.h>
#define MAX 100000

unsigned long r[MAX];

unsigned long dp(unsigned long n)
{
    unsigned long q;

    if(n==0) return 0;

    if(n<MAX && r[n]!=0)
    {
        return r[n];
    }

    q=dp(n/2)+dp(n/3)+dp(n/4);

    if(n<=q)
    {
        if(n<MAX)
            r[n]=q;
        return q;
    }
    else
    {
        if(n<MAX)
            r[n]=n;
        return n;
    }
}

int main()
{
    unsigned long n,i;
    i=0;
    while(i++<MAX)
        r[i]=0;


    while(scanf("%lu",&n)!=EOF)
    {
        printf("%lu\n",dp(n));
    }
    return 0;
}

