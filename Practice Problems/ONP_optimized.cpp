#include <iostream>
#include <cmath>
#include <algorithm>
#include <limits>
#include <vector>
#include <bitset>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <time.h>
#include <map>
using namespace std;
#define MOD             1000000007LL
#define LL              long long
#define ULL             unsigned long long
#define LD              long double
#define MAX(a,b)        ((a)>(b)?(a):(b))
#define MIN(a,b)        ((a)<(b)?(a):(b))
#define ABS(x)          ((x)<0?-(x):(x))
#define si(n)           scanf("%d",&n)
#define sf(n)           scanf("%f",&n)
#define sl(n)           scanf("%lld",&n)
#define slu(n)          scanf("%llu",&n)
#define sd(n)           scanf("%lf",&n)
#define ss(n)           scanf("%s",n)
#define pnl             printf("\n")//print new line
#define REP(i,n)        for(int i=0;i<(n);i++)//repeat n times
#define FOR(i,a,b)      for(int i=(a);i<(b);i++)//end not included
#define FORR(i,n)       for(int i=(n);i>=0;i--)//reverse for
#define DB(x)           cout<<"\n"<<#x<<" = "<<(x)<<"\n";//debugging
#define CL(a,b)         memset(a,b,sizeof(a))
#define GOLD            ((1+sqrt(5))/2)
const double            PI=3.14159265358979323846264338327950288419716939937510582097494459230;

void swaps (char *x,char *y)
{
    char temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
void swapi(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
ULL gcd(ULL a,ULL b)
{
    if(a==0)return b;
    if(b==0)return a;
    if(a==1||b==1)return 1;
    if(a==b)return a;
    if(a>b)return gcd(b,a%b);
    else return gcd(a,b%a);
}
//}
#define SIZE 1000001

ULL arr[SIZE];
void precompute()
{
}//end precompute
void refresh()
{

}//end refresh
void doThis()
{
    char line[401],op[401],ch;
    int i=0,j=0;//k for toWrite,i for line,j for operands
    gets(line);
    while((ch=line[i++])!='\0')
    {
        if(ch=='(')
        {
        }
        else if(ch==')')  //need to pop out last entered operator
        {
            putchar(op[j--]);
        }
        else if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
        {
            putchar(ch);

        }
        else  //means operator, we will keep them in sep array
        {
            op[++j]=ch;
        }
    }
    pnl;

}

int main()
{

    freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // freopen("log.txt", "w", stderr);
    int t;
    scanf("%d",&t);
    char garbage[10];
    gets(garbage);
    while(t--)
    {
        doThis();    //end while
    }
    fprintf(stdout,"\nTIME: %.3lf sec\n", (double)clock()/(CLOCKS_PER_SEC));
    return 0;
}//end main

